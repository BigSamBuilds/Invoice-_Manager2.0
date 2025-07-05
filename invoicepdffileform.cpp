#include "invoicepdffileform.h"
#include "ui_invoicepdffileform.h"
#include "Controller/database.h"
#include "functools.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>
#include <QLineEdit>
#include <QSqlRelationalTableModel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QSqlRelationalDelegate>
#include <QApplication>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QPdfWriter>
#include <QFileDialog>
#include <iostream>
#include <iomanip>
#include <QScrollBar>>

InvoicePDFFileForm::InvoicePDFFileForm(int invoiceID, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InvoicePDFFileForm)
{
    ui->setupUi(this);
    this->currentInvoiceID = invoiceID;

    qDebug() << currentInvoiceID;
    //laoding the data to qlinedits
    defultValues(); // set a value deafult is not exists id = 1
    QMap<QString, QString> mp = getUserInformation();
    mp.remove("id");
    QMap<QString, QObject*> obj = getUserQLineEdits();
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        // qDebug() << it.key() << ":" << it.value();
        if (!(QString::compare(it.key() ,"bank_address", Qt::CaseInsensitive) == 0)) {
            QLineEdit* lineEdit = qobject_cast<QLineEdit*>(obj.value(it.key()));
            if (lineEdit) {
                lineEdit->setText(it.value());
            } else {
                qDebug() << "Failed to cast" << it.key() << "to QLineEdit*";
            }
        }else{
            QTextEdit* lineEdit = qobject_cast<QTextEdit*>(obj.value(it.key()));
            lineEdit->setText(it.value());
        }
    }

    loadCustomerData();

    QMap<QString, QObject*> custLines = getCustomerQLineEdits();
    for(auto so = custLines.begin(); so != custLines.end(); so++){
        QLineEdit* line = qobject_cast<QLineEdit*>(so.value());
        if(so.key() != "balanceDue"){
            if(line){
                line->setReadOnly(true);
            }else{
                QTextEdit* txt = qobject_cast<QTextEdit*>(so.value());
                txt->setReadOnly(true);
            }
        }
    }
}

InvoicePDFFileForm::~InvoicePDFFileForm()
{
    delete ui;
}

QMap<QString, QString> InvoicePDFFileForm::getUserInformation() {
    QMap<QString, QString> resultMap;
    QSqlQuery query(Database::getDatabase());
    query.prepare("SELECT * FROM userInformation WHERE id = :id");
    query.bindValue(":id", 1);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return resultMap;
    }

    if (query.next()) {
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            QString columnName = record.fieldName(i);
            QString value = query.value(i).toString();
            resultMap.insert(columnName, value);
        }
    }
    return resultMap;
}

void InvoicePDFFileForm::on_SaveInfo_clicked()
{
    QSqlQuery query(Database::getDatabase());
    query.prepare(R"(UPDATE userInformation
                                    SET address = :address,
                                        post_number = :postNumber,
                                        vat_number = :vatNumber,
                                        mobile = :mobile,
                                        phone = :phone,
                                        email = :email,
                                        website = :website,
                                        accountNumber = :accountNumber,
                                        sort_code = :sortCode,
                                        bank_name = :bankName,
                                        bank_address = :bankAddress
                                    WHERE id = 1; )");
    query.bindValue(":address", ui->addressLineEdit->text());
    query.bindValue(":postNumber", ui->postnumberLineEdit->text());
    query.bindValue(":vatNumber", ui->vat_numberQlineEdit->text());
    query.bindValue(":mobile", ui->mobileQLineEdit->text());
    query.bindValue(":phone", ui->phone_QLineEdit->text());
    query.bindValue(":email", ui->email_QLineEdit->text());
    query.bindValue(":website", ui->website_QLineEdit->text());
    query.bindValue(":accountNumber", ui->accountLineEdit->text());
    query.bindValue(":sortCode", ui->sortCodeLineEdit->text());
    query.bindValue(":bankName", ui->bankLineEdit->text());
    query.bindValue(":bankAddress", ui->bankAddressTextEdit->toPlainText());

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
    }
}


QMap<QString, QObject*> InvoicePDFFileForm::getUserQLineEdits(){
    QMap<QString, QObject*> *editline = new QMap<QString, QObject*>();
    editline->insert("address", ui->addressLineEdit);
    editline->insert("post_number", ui->postnumberLineEdit);
    editline->insert("vat_number", ui->vat_numberQlineEdit);
    editline->insert("mobile", ui->mobileQLineEdit);
    editline->insert("phone", ui->phone_QLineEdit);
    editline->insert("email", ui->email_QLineEdit);
    editline->insert("website", ui->website_QLineEdit);
    editline->insert("accountNumber", ui->accountLineEdit);
    editline->insert("sort_code", ui->sortCodeLineEdit);
    editline->insert("bank_name", ui->bankLineEdit);
    editline->insert("bank_address", ui->bankAddressTextEdit);
    return *editline;
}

void InvoicePDFFileForm::defultValues(){
    QSqlQuery query(Database::getDatabase());
    QString queryStr = R"(INSERT INTO userInformation (id, address, post_number, vat_number, mobile, phone, email, website, accountNumber, sort_code, bank_name, bank_address)
                                    SELECT 1, '123 Main St', '12345', 'VAT123456', '555-1234', '555-5678', 'user@example.com', 'www.example.com', '12345678', '1234', 'Example Bank', 'Bank Address'
                                    WHERE NOT EXISTS (SELECT 1 FROM userInformation WHERE id = 1);)";

    if (!query.exec(queryStr)) {
        qDebug() << "Query failed:" << query.lastError().text();
    }
}


class NumberDelegate : public QStyledItemDelegate {
public:
    NumberDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        QVariant value = index.data(Qt::DisplayRole);
        QString text;

        if (value.canConvert<double>()) {
            // Format number with thousands separator and variable decimal places
            double number = value.toDouble();
            text = QLocale().toString(number, 'f', 6).remove(QRegularExpression ("0+$")); // Remove trailing zeros
            if (text.endsWith('.')) {
                text.chop(1); // Remove the dot if there are no decimals
            }
        } else {
            text = value.toString();
        }

        painter->save();
        painter->setFont(opt.font);
        painter->setPen(opt.palette.color(QPalette::Text));
        painter->drawText(opt.rect, Qt::AlignRight | Qt::AlignVCenter, text);
        painter->restore();
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        return QStyledItemDelegate::sizeHint(option, index);
    }
};


void InvoicePDFFileForm::loadCustomerData(){

    // get invoice information
    QMap<QString, QString> resultMap;
    QSqlQuery query(Database::getDatabase());
    query.prepare("select * from invoices inv, customers cst where inv.id = :id and inv.customer_id = cst.id;");
    query.bindValue(":id", currentInvoiceID);

    if (!query.exec()) {
        qDebug() << "Query failed loadCustomerData: " << query.lastError().text();
        return;
    }

    if (query.next()) {
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            QString columnName = record.fieldName(i);
            QString value = query.value(i).toString();
            resultMap.insert(columnName, value);
        }
    }

    QMap<QString, QObject*> mp = getCustomerQLineEdits();
    for(auto it = mp.begin(); it != mp.end(); it++){
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(it.value());
        if(lineEdit){
            lineEdit->setText( formatDouble(resultMap.value(it.key())));
        }
    }
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(mp.value("balanceDue"));
    lineEdit->setText( formatDouble( resultMap.value("total")));

    QTextEdit* lineEdit2 = qobject_cast<QTextEdit*>(mp.value("billTo"));
    lineEdit2->setText(resultMap.value("name"));

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this, Database::getDatabase());

    // Set the table to invoicesDetails
    model->setTable("InvoiceDetails");
    model->setSort(0, Qt::DescendingOrder);

    // // Set the relation for item_id to Items table
    model->setRelation(model->fieldIndex("invoice_id"), QSqlRelation("Invoices", "id", "invoice_id"));

    // Select data from the model
    if (!model->select()) {
        qDebug() << "Error selecting data from invoicesDetails:" << model->lastError();
        return;
    }

    // Set header names
    // model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    // model->setHeaderData(1, Qt::Horizontal, tr("Customer"));
    model->setHeaderData(2, Qt::Horizontal, tr("Products"));
    model->setHeaderData(3, Qt::Horizontal, tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, tr("Rate"));
    model->setHeaderData(5, Qt::Horizontal, tr("Amount"));
    model->setHeaderData(6, Qt::Horizontal, tr("Comment"));

    // FilterCurrentPayment(model);
    FilterCurrentInvoice(model);


    ui->tableView->setModel(model);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(6);

    // Set the item delegate for handling foreign keys
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    NumberDelegate *delegate = new NumberDelegate(this);
    ui->tableView->setItemDelegateForColumn(5, delegate);
    NumberDelegate *delegate1 = new NumberDelegate(this);
    ui->tableView->setItemDelegateForColumn(4, delegate1);
    NumberDelegate *delegate2 = new NumberDelegate(this);
    ui->tableView->setItemDelegateForColumn(3, delegate2);


    // ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
      ui->tableView->setColumnWidth(2, 500);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QString queryStr = QString(R"(
        SELECT SUM(amount)
        FROM InvoiceDetails
        WHERE invoice_id = %1
    )").arg(currentInvoiceID);

    // QSqlQuery query(Database::getDatabase());
    if (!query.exec(queryStr)) {
        qDebug() << "Failed to calculate the sum of the current row";
        return;
    }

    double totalAmount = 0;
    if (query.next()) {
        totalAmount += query.value(0).toDouble();
    }

    double vat = ui->vatPercentLineEdit->text().toDouble();
    double vated = (vat/100)*totalAmount;

    QString totalInAmount = QLocale().toString(totalAmount, 'f', 2).remove(QRegularExpression ("0+$"));
    QString vatedAmountStr = QLocale().toString(vated, 'f', 2).remove(QRegularExpression ("0+$"));
    ui->subtotalLineEdit->setText(formatDouble(totalInAmount));
    ui->vatAmountLineEdit->setText(formatDouble(vatedAmountStr));


}


QMap<QString, QObject*> InvoicePDFFileForm::getCustomerQLineEdits(){
    QMap<QString, QObject*> *editline = new QMap<QString, QObject*>();
    editline->insert("date", ui->dateLineEdit);
    editline->insert("invoice_id", ui->invoiceNumberLineEdit);
    editline->insert("vat", ui->vatPercentLineEdit);
    editline->insert("discount", ui->discountLineEdit);
    editline->insert("total_discount", ui->totalDiscountLineEdit);
    editline->insert("total", ui->totalLineEdit);
    editline->insert("billTo", ui->billToTextEdit);
    editline->insert("subtotal", ui->subtotalLineEdit);
    editline->insert("vatAmount", ui->vatAmountLineEdit);
    editline->insert("balanceDue", ui->balanceDueLineEdit);
    return *editline;
}

void InvoicePDFFileForm::FilterCurrentInvoice(QSqlRelationalTableModel *model) {
    if (model) {
        // Explicitly specify the table name for the id column to avoid ambiguity
        model->setFilter(QString("InvoiceDetails.invoice_id = %1").arg(currentInvoiceID));
        if (!model->select()) {
            qDebug() << "Error selecting filtered data from invoice details: " << model->lastError();
        }
    }
}

QString InvoicePDFFileForm::formatDouble(const QString &input) {
    bool ok;
    double number = input.toDouble(&ok);
    if (!ok) {
        // Handle conversion error if needed
        return input;
    }

    // Format the number with commas as thousand separators
    QString formattedString = QLocale().toString(number, 'f', 2).remove(QRegularExpression ("0+$"));

    return formattedString;
}

void InvoicePDFFileForm::on_PrintSaveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", ui->billToTextEdit->toPlainText() + "-invoice-"+ui->invoiceNumberLineEdit->text(), "PDF Files (*.pdf)");
        if (!fileName.isEmpty()) {



            QApplication::setOverrideCursor(Qt::WaitCursor);
            QApplication::processEvents();
            QWebEngineView *view = new QWebEngineView();
            QWebEnginePage *page =  view->page();

            QMap<QString, QString> values;
            values["%1"] = ui->addressLineEdit->text(); // address
            values["%2"] = ui->postnumberLineEdit->text(); // post_number
            values["%3"] = ui->vat_numberQlineEdit->text(); // vat_number
            values["%4"] = ui->mobileQLineEdit->text(); // mobile
            values["%5"] = ui->phone_QLineEdit->text(); // phone
            values["%6"] = ui->email_QLineEdit->text(); // email
            values["%7"] = ui->website_QLineEdit->text(); // website
            values["%8"] = ui->dateLineEdit->text(); // date
            values["%9"] = ui->invoiceNumberLineEdit->text(); // invoice_number
            values["%10"] = ui->billToTextEdit->toPlainText(); // bills_to


            QString tableRows;
            // Construct a query to fetch rows based on invoice_id
            QString queryString = QString("SELECT * FROM InvoiceDetails WHERE invoice_id = %1").arg(currentInvoiceID);
            QSqlQuery query(queryString);

            // Execute the query and iterate through the results
            while (query.next()) {
                tableRows += "<tr>";

                QString products = query.value("products").toString();
                int quantity = query.value("quantity").toInt();
                qreal rate = query.value("rate").toReal();
                qreal amount = query.value("amount").toReal();

                tableRows += "<td>" + products + "</td>";
                tableRows += "<td class='quantity' >" + QString::number(quantity) + "</td>";
                tableRows += "<td class='rate'>" + QString::number(rate, 'f', 2) + "</td>"; // Format rate to 2 decimal places
                tableRows += "<td class='amount' >" + QString::number(amount, 'f', 2) + "</td>"; // Format amount to 2 decimal places

                tableRows += "</tr>";
            }

            values["%11"] = tableRows;//"<tr><td>Service 1</td><td>1</td><td>100.00</td><td>100.00</td></tr>"; // table_rows
            values["%12"] = ui->accountLineEdit->text(); // accountNumber
            values["%13"] = ui->sortCodeLineEdit->text();//"12-34-56"; // sort_code
            values["%14"] = ui->bankLineEdit->text();//"Example Bank"; // bank_name
            values["%15"] = ui->bankAddressTextEdit->toPlainText();//"Bank Address"; // bank_address
            values["%16"] = ui->subtotalLineEdit->text();//"100.00"; // subtotal
            values["%17"] = ui->vatPercentLineEdit->text();//"20"; // vat_percentage
            values["%18"] = ui->vatAmountLineEdit->text();//"20.00"; // vat_amount
            values["%19"] = ui->discountLineEdit->text();//"0.00"; // discount
            values["%20"] = ui->totalDiscountLineEdit->text();//"0.00"; // total_discount
            values["%21"] = ui->totalLineEdit->text();//"120.00"; // total
            values["%22"] = ui->balanceDueLineEdit->text();//"120.00"; // balance_due

            QString html = FuncTools::generateInvoiceHTML(values);

            if(!alreadySavedOnce){
                QMessageBox msgBox(this);
                msgBox.setText(QString("Do you want to add this invoice to your document files too?"));
                msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
                msgBox.setDefaultButton(QMessageBox::Yes);

                int ret = msgBox.exec();

                if (ret == QMessageBox::Yes) {
                    if(insertDocument( ui->billToTextEdit->toPlainText() + "-invoice-"+ui->invoiceNumberLineEdit->text(), html)){
                        alreadySavedOnce = true;
                    }else{
                        QMessageBox::critical(this, "Error", "Couldn't save the file");
                    }
                }
            }

            page->setHtml(html);


            connect(page, &QWebEnginePage::loadFinished, this, [=](bool success) {
                if (success) {
                    page->printToPdf(fileName);

                } else {
                    qWarning("Failed to load HTML content.");
                }
                QApplication::restoreOverrideCursor();
            });
        }


}

bool InvoicePDFFileForm::insertDocument(const QString &fileName, const QString &fileData) {
    QSqlQuery query(Database::getDatabase());
    query.prepare("INSERT INTO Documents (FileName, FileSize, FileDate, FileData) VALUES (:FileName, :FileSize, :FileDate, :FileData)");

    // Calculate file size
    int fileSizeBytes = fileData.toUtf8().size();

    // Convert bytes to megabytes
    // double fileSizeMB = fileSizeBytes / (1024.0 * 1024.0);

    // Current date/time
    QString fileDate = QDate::currentDate().toString(Qt::ISODate);

    // Bind values to the query
    query.bindValue(":FileName", fileName);
    query.bindValue(":FileSize", fileSizeBytes);
    query.bindValue(":FileDate", fileDate);
    query.bindValue(":FileData", fileData);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error inserting document:" << query.lastError().text();
        return false;
    }
    return true;
}

void InvoicePDFFileForm::on_SaveTheInvoice_clicked()
{
    if(alreadySavedOnce){
        QMessageBox msgBox(this);
        msgBox.setText(QString("The invoice has been already added to the documents, do you want save it again?"));
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Yes);

        int ret = msgBox.exec();

        if (ret == QMessageBox::No) {
            return;
        }
    }

    QMap<QString, QString> values;
    values["%1"] = ui->addressLineEdit->text(); // address
    values["%2"] = ui->postnumberLineEdit->text(); // post_number
    values["%3"] = ui->vat_numberQlineEdit->text(); // vat_number
    values["%4"] = ui->mobileQLineEdit->text(); // mobile
    values["%5"] = ui->phone_QLineEdit->text(); // phone
    values["%6"] = ui->email_QLineEdit->text(); // email
    values["%7"] = ui->website_QLineEdit->text(); // website
    values["%8"] = ui->dateLineEdit->text(); // date
    values["%9"] = ui->invoiceNumberLineEdit->text(); // invoice_number
    values["%10"] = ui->billToTextEdit->toPlainText(); // bills_to

    QString tableRows;
    // Construct a query to fetch rows based on invoice_id
    QString queryString = QString("SELECT * FROM InvoiceDetails WHERE invoice_id = %1").arg(currentInvoiceID);
    QSqlQuery query(queryString);

    // Execute the query and iterate through the results
    while (query.next()) {
        tableRows += "<tr>";

        QString products = query.value("products").toString();
        int quantity = query.value("quantity").toInt();
        qreal rate = query.value("rate").toReal();
        qreal amount = query.value("amount").toReal();

        tableRows += "<td>" + products + "</td>";
        tableRows += "<td class='quantity' >" + QString::number(quantity) + "</td>";
        tableRows += "<td class='rate'>" + QString::number(rate, 'f', 2) + "</td>"; // Format rate to 2 decimal places
        tableRows += "<td class='amount' >" + QString::number(amount, 'f', 2) + "</td>"; // Format amount to 2 decimal places

        tableRows += "</tr>";
    }
    values["%11"] = tableRows;//"<tr><td>Service 1</td><td>1</td><td>100.00</td><td>100.00</td></tr>"; // table_rows
    values["%12"] = ui->accountLineEdit->text(); // accountNumber
    values["%13"] = ui->sortCodeLineEdit->text();//"12-34-56"; // sort_code
    values["%14"] = ui->bankLineEdit->text();//"Example Bank"; // bank_name
    values["%15"] = ui->bankAddressTextEdit->toPlainText();//"Bank Address"; // bank_address
    values["%16"] = ui->subtotalLineEdit->text();//"100.00"; // subtotal
    values["%17"] = ui->vatPercentLineEdit->text();//"20"; // vat_percentage
    values["%18"] = ui->vatAmountLineEdit->text();//"20.00"; // vat_amount
    values["%19"] = ui->discountLineEdit->text();//"0.00"; // discount
    values["%20"] = ui->totalDiscountLineEdit->text();//"0.00"; // total_discount
    values["%21"] = ui->totalLineEdit->text();//"120.00"; // total
    values["%22"] = ui->balanceDueLineEdit->text();//"120.00"; // balance_due

    QString html = FuncTools::generateInvoiceHTML(values);

    if(insertDocument( ui->billToTextEdit->toPlainText() + "-invoice-"+ui->invoiceNumberLineEdit->text(), html)){
        QMessageBox::information(this, "Saved", "The document saved successfully!");
        alreadySavedOnce = true;
    }else{
        QMessageBox::critical(this, "Error", "Error while saving file to documents");
        alreadySavedOnce = false;
    }

}

