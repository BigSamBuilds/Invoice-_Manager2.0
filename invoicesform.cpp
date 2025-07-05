#include "invoicesform.h"
#include "ui_invoicesform.h"
// #include "functools.h"
#include "invoicepdffileform.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSize>
#include <QTextBrowser >

#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <Controller/database.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QLocale>
#include <QRegularExpression>


InvoicesForm::InvoicesForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InvoicesForm)
{
    ui->setupUi(this);

    setupInvoiceTableView();
    // setupInvoiceDetailsTableView();
}

InvoicesForm::~InvoicesForm()
{
    delete ui;
}


void InvoicesForm::search(QAbstractItemModel *model, QString saerchTerm, QTableView *table){
    for (int row = 0; row < model->rowCount(); ++row) {
        bool match = false;
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            if (data.contains(saerchTerm, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        table->setRowHidden(row, !match);
    }
}

void InvoicesForm::on_InvoiceSearchButtonCustomers_clicked()
{

         search(ui->invoiceTableView->model(), ui->InvoicesSearchLineEditCustomers->text(), ui->invoiceTableView);

}


void InvoicesForm::on_InvoicesSearchLineEditCustomers_returnPressed()
{

        search(ui->invoiceTableView->model(), ui->InvoicesSearchLineEditCustomers->text(), ui->invoiceTableView);

}


void InvoicesForm::on_InvoicesSearchLineEditCustomers_textChanged(const QString &arg1)
{

        search(ui->invoiceTableView->model(), ui->InvoicesSearchLineEditCustomers->text(), ui->invoiceTableView);

}


void InvoicesForm::on_InvoicesProductEditLine_returnPressed()
{
    if(ui->InvoiceDetailsTableView->model()){
        search(ui->InvoiceDetailsTableView->model(), ui->InvoicesProductEditLine->text(), ui->InvoiceDetailsTableView);
    }
}


void InvoicesForm::on_InvoicesProductEditLine_textChanged(const QString &arg1)
{
    if(ui->InvoiceDetailsTableView->model()){
        search(ui->InvoiceDetailsTableView->model(), ui->InvoicesProductEditLine->text(), ui->InvoiceDetailsTableView);
    }
}


void InvoicesForm::on_InvoicesSearchProduktItems_clicked()
{
    if(ui->InvoiceDetailsTableView->model()){
        search(ui->InvoiceDetailsTableView->model(), ui->InvoicesProductEditLine->text(), ui->InvoiceDetailsTableView);
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

void InvoicesForm::on_generateInvoiceButton_clicked()
{

    if(selectedInvoice){
        InvoicePDFFileForm *previewPDF = new InvoicePDFFileForm(selectedInvoice);
        previewPDF->show();
    }else{
        QMessageBox::information(this, "No Selection", "Please select a invoice to show");
    }

}

void InvoicesForm::setColumnsStretch() {
    ui->invoiceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->InvoiceDetailsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void InvoicesForm::resetColumnsToDefault() {
    ui->invoiceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->InvoiceDetailsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

void InvoicesForm::setupInvoiceTableView(){
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this, Database::getDatabase());

    // Set the main table for the model (PaymentOut in this case)
    model->setTable("Invoices");
    model->setSort(0, Qt::DescendingOrder);

    // Set the relations for vendor_id to Vendors table
    model->setRelation(model->fieldIndex("customer_id"), QSqlRelation("Customers", "id", "name"));

    // Select the data
    model->select();

    // Set header names
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Customer"));
    model->setHeaderData(2, Qt::Horizontal, tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, tr("Invoice ID"));
    model->setHeaderData(4, Qt::Horizontal, tr("Vat %"));
    model->setHeaderData(5, Qt::Horizontal, tr("Discount %"));
    model->setHeaderData(6, Qt::Horizontal, tr("Total Discount"));
    model->setHeaderData(7, Qt::Horizontal, tr("Total"));

    // Set the model to your view
    ui->invoiceTableView->setModel(model);

    // Set the item delegate for handling foreign keys
    ui->invoiceTableView->setItemDelegate(new QSqlRelationalDelegate(ui->invoiceTableView));
    NumberDelegate *delegate = new NumberDelegate(this);
    ui->invoiceTableView->setItemDelegateForColumn(7, delegate);
    NumberDelegate *delegate1 = new NumberDelegate(this);
    ui->invoiceTableView->setItemDelegateForColumn(6, delegate1);
    NumberDelegate *delegate2 = new NumberDelegate(this);
    ui->invoiceTableView->setItemDelegateForColumn(5, delegate2);
    NumberDelegate *delegate3 = new NumberDelegate(this);
    ui->invoiceTableView->setItemDelegateForColumn(4, delegate3);

    // Connect the dataChanged signal to a slot
    connect(model, &QSqlRelationalTableModel::dataChanged, this, &InvoicesForm::onInvoiceDataChanged);
}

void InvoicesForm::onInvoiceDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles){
    Q_UNUSED(bottomRight)
    Q_UNUSED(roles)
    Q_UNUSED(topLeft)
    CalaculateTheChange();
}

void InvoicesForm::FilterCurrentInvoice(QSqlRelationalTableModel *model) {
    if (model) {
        // Explicitly specify the table name for the id column to avoid ambiguity
        model->setFilter(QString("InvoiceDetails.invoice_id = %1").arg(selectedInvoice));
        if (!model->select()) {
            qDebug() << "Error selecting filtered data from invoice details: " << model->lastError();
        }
    }
}

void InvoicesForm::setupInvoiceDetailsTableView(){
    if (!selectedInvoice) {
        QMessageBox::warning(this, "No Selection", "Please select a row.");
        return;
    }


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
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    // model->setHeaderData(1, Qt::Horizontal, tr("Customer"));
    model->setHeaderData(2, Qt::Horizontal, tr("Products"));
    model->setHeaderData(3, Qt::Horizontal, tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, tr("Rate"));
    model->setHeaderData(5, Qt::Horizontal, tr("Amount"));
    model->setHeaderData(6, Qt::Horizontal, tr("Comment"));

    // FilterCurrentPayment(model);
    FilterCurrentInvoice(model);


    ui->InvoiceDetailsTableView->setModel(model);
    ui->InvoiceDetailsTableView->hideColumn(1);

    // Set the item delegate for handling foreign keys
    ui->InvoiceDetailsTableView->setItemDelegate(new QSqlRelationalDelegate(ui->InvoiceDetailsTableView));
    NumberDelegate *delegate = new NumberDelegate(this);
    ui->InvoiceDetailsTableView->setItemDelegateForColumn(5, delegate);
    NumberDelegate *delegate1 = new NumberDelegate(this);
    ui->InvoiceDetailsTableView->setItemDelegateForColumn(4, delegate1);
    NumberDelegate *delegate2 = new NumberDelegate(this);
    ui->InvoiceDetailsTableView->setItemDelegateForColumn(3, delegate2);

    // Connect the dataChanged signal to a slot
    connect(model, &QSqlRelationalTableModel::dataChanged, this, &InvoicesForm::onInvoiceDataChanged);
}

void InvoicesForm::on_InvoiceDeleteRow_clicked()
{
    QMessageBox msgBox(this);
    msgBox.setText(QString("Are you sure you want delete row: %1 ?").arg(selectedInvoice));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Cancel) {
        // Cancel was pressed, return immediately
        return;
    }

    QItemSelectionModel *selectionModel = ui->invoiceTableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
        return;
    }

    // Get the row of the first selected index (assuming single row selection)
    int rowToDelete = selectedIndexes.first().row();

    // Remove the row from the model
    QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(ui->invoiceTableView->model());
    if (!model) {
        qWarning() << "Model is not a QSqlTableModel!";
        return;
    }

    if (model->removeRow(rowToDelete)) {
        if (model->submitAll()) {
            // Update the view after successful deletion
            model->select();
            ui->InvoicesCustomerNameStatus->setText("Name: ");
            ui->invoicesRecentChangesStatus->setText("Date");
            ui->InoicesCustomerIDStatus->setText("ID: ");
            on_refreshInvoiceDetails_clicked();
            selectedInvoice = NULL;
            selectedInvoiceRow = NULL;
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete row from database.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete row from model.");
    }
}

void InvoicesForm::on_invoiceTableView_clicked(const QModelIndex &index)
{
    // ui->invoiceTableView->setEditTriggers(QAbstractItemView::SelectedClicked);

    QString ID = ui->invoiceTableView->model()->data(index.sibling(index.row(), 0)).toString();
    if (index.isValid() && !ID.trimmed().isEmpty()) {
        QString ID = ui->invoiceTableView->model()->data(index.sibling(index.row(), 0)).toString();
        QString Name = ui->invoiceTableView->model()->data(index.sibling(index.row(), 1)).toString();
        QString RecentChange = ui->invoiceTableView->model()->data(index.sibling(index.row(), 2)).toString();
        // qDebug() << "ID: " + ID + " Name: " + Name + " Changes: " + RecentChange;
        ui->InoicesCustomerIDStatus->setText("ID: " + ID);
        ui->InvoicesCustomerNameStatus->setText("Name: " + Name);
        ui->invoicesRecentChangesStatus->setText("Date: " + RecentChange);

        selectedInvoice = ID.toInt();
        selectedInvoiceRow = index.row();

        if (!selectedInvoice) {
            QMessageBox::warning(this, "No Selection", "Please select a row.");
            return;
        }
        setupInvoiceDetailsTableView();
        resetColumnsToDefault();
    }
}

class VendorSelectionDialog : public QDialog {
public:
    VendorSelectionDialog(QString quaryString, QString header = "Select: ", QWidget *parent = nullptr)
        : QDialog(parent)
    {
        this->setFixedSize(500, 500);
        this->move(parent->pos());
        QVBoxLayout *layout = new QVBoxLayout(this);
        vendorComboBox = new QComboBox(this);
        QPushButton *okButton = new QPushButton("OK", this);
        QPushButton *cancelButton = new QPushButton("Cancel", this);
        vendorComboBox->setMinimumWidth(200);

        layout->addWidget(new QLabel(header, this));
        layout->addWidget(vendorComboBox);
        layout->addWidget(okButton);
        layout->addWidget(cancelButton);

        connect(okButton, &QPushButton::clicked, this, &VendorSelectionDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &VendorSelectionDialog::reject);

        // Populate vendorComboBox with vendor names or IDs
        QSqlQuery query(Database::getDatabase());
        query.prepare(quaryString);
        if (query.exec()) {
            while (query.next()) {
                int vendorId = query.value(0).toInt();
                QString vendorName = query.value(1).toString();
                vendorComboBox->addItem(vendorName, vendorId);
            }
        } else {
            QMessageBox::critical(this, "Error", "Failed to fetch Customers from database.");
        }
    }

    int selectedVendorId() const {
        return vendorComboBox->currentData().toInt();
    }

private:
    QComboBox *vendorComboBox;
};

void InvoicesForm::on_InvoiceInsertNewRow_clicked()
{
    // Create and exec the vendor selection dialog
    VendorSelectionDialog dialog("select id, name from customers ORDER BY name", "Select Customer: ", this);
    if (dialog.exec() == QDialog::Accepted) {
        int selectedVendorId = dialog.selectedVendorId();

        QSqlDatabase db = Database::getDatabase();

        // Step 1: Query the last inserted invoice ID
        QString newInvoiceId = "INV-00001"; // Default ID if no previous invoices are found
        QSqlQuery lastInvoiceQuery(db);
        lastInvoiceQuery.prepare("SELECT invoice_id FROM Invoices ORDER BY id DESC LIMIT 1");
        if (lastInvoiceQuery.exec() && lastInvoiceQuery.next()) {
            QString lastInvoiceId = lastInvoiceQuery.value(0).toString();

            // Step 2: Extract the numeric part of the last invoice ID
            QString lastNumericPart = lastInvoiceId.mid(4); // Skip the "INV-" part

            // Step 3: Increment the numeric part
            int newNumericPart = lastNumericPart.toInt() + 1;

            // Step 4: Combine the prefix "INV-" with the incremented numeric part
            newInvoiceId = QString("INV-%1").arg(newNumericPart, 5, 10, QChar('0')); // Ensure it's zero-padded to 5 digits
        }

        // Insert new row into Invoices table
        QSqlQuery query(db);
        query.prepare("INSERT INTO Invoices (customer_id, date, invoice_id, vat, discount, total_discount, total) "
                      "VALUES (:customerid, :date, :invoiceid, :vat, :discount, :totaldis, :total)");
        query.bindValue(":customerid", selectedVendorId);
        query.bindValue(":date", QDate::currentDate().toString(Qt::ISODate));
        query.bindValue(":invoiceid", newInvoiceId);  // Use the generated invoice ID
        query.bindValue(":vat", 20);  // Default value for VAT
        query.bindValue(":discount", 0);  // Default value for discount
        query.bindValue(":totaldis", 0);  // Default value for total_discount
        query.bindValue(":total", 0);  // Default value for total

        if (query.exec()) {
            // Successfully inserted into Invoices table
            // Retrieve the last inserted invoice ID
            int lastInvoiceId = query.lastInsertId().toInt();

            // Insert into paymentsIn table
            QSqlQuery paymentQuery(db);
            paymentQuery.prepare("INSERT INTO paymentsIn (invoice_id, date, paid) "
                                 "VALUES (:invoiceid, :date, :paid)");
            paymentQuery.bindValue(":invoiceid", lastInvoiceId);
            paymentQuery.bindValue(":date", QDate::currentDate().toString(Qt::ISODate));
            paymentQuery.bindValue(":paid", 0);  // Default value for paid

            if (paymentQuery.exec()) {
                // Successfully inserted into paymentsIn table
                QMessageBox::information(this, "Success", "New invoice and payment record inserted successfully.");

                // Optionally refresh the view or do other updates
                QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(ui->invoiceTableView->model());
                model->select();
            } else {
                QMessageBox::critical(this, "Error", "Failed to insert new payment record into database: " + paymentQuery.lastError().text());
            }
        } else {
            QMessageBox::critical(this, "Error", "Failed to insert new invoice record into database: " + query.lastError().text());
        }
    }
}

// the refresh button for invoices
void InvoicesForm::on_pushButton_clicked()
{
    QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(ui->invoiceTableView->model());
    model->submit();
    model->submitAll();
    model->clear();
    setupInvoiceTableView();
    setColumnsStretch();
}

void InvoicesForm::on_ProductInsertNewRow_clicked()
{
    if (selectedInvoice == NULL) {
        QMessageBox::warning(this, "No Invoice selected", "Please select a Invoice. ");
        return;
    }
    // Now you have vendorId, you can proceed to insert into ItemBought table
    QSqlQuery insertQuery(Database::getDatabase());
    insertQuery.prepare("INSERT INTO InvoiceDetails (invoice_id, products, quantity, rate, amount, comment) "
                        "VALUES (:invoice_id, :products, :quantity, :rate, :amount, :comment)");
    insertQuery.bindValue(":invoice_id", selectedInvoice); // Replace with actual item_id value
    insertQuery.bindValue(":products", ""); // Replace with actual quantity value
    insertQuery.bindValue(":quantity", 0);
    insertQuery.bindValue(":rate", 0.0); // Replace with actual rate value
    insertQuery.bindValue(":amount", 0.0); // Replace with actual amount value
    insertQuery.bindValue(":comment", " "); // Replace with actual comment value

    if (!insertQuery.exec()) {
        QMessageBox::critical(this, "Error", "Failed to insert new row into ItemBought table: " + insertQuery.lastError().text());
        return;
    }
    // Refresh the ItemBoughtTableView to reflect the new data
    setupInvoiceDetailsTableView(); // Assuming this function refreshes the view

}

void InvoicesForm::on_productDeleteRow_clicked()
{
    if(selectedInvoice){
        QMessageBox msgBox(this);

        QItemSelectionModel *selectionModel = ui->InvoiceDetailsTableView->selectionModel();
        QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

        if (selectedIndexes.isEmpty()) {
            QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
            return;
        }

        msgBox.setText(QString("Are you sure you want to delete row: %1 ?").arg(selectedIndexes.at(0).sibling(selectedIndexes.at(0).row(), 0).data().toString()));
        msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);

        int ret = msgBox.exec();

        if (ret == QMessageBox::Cancel) {
            // Cancel was pressed, return immediately
            return;
        }

        // Get the row of the first selected index (assuming single row selection)
        int rowToDelete = selectedIndexes.first().row();

        // Remove the row from the model
        QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(ui->InvoiceDetailsTableView->model());
        if (!model) {
            qWarning() << "Model is not a QSqlRelationalTableModel!";
            return;
        }

        if (model->removeRow(rowToDelete)) {
            if (model->submitAll()) {
                // Update the view after successful deletion
                model->select();
            } else {
                QMessageBox::warning(this, "Error", "Failed to delete row from database.");
            }
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete row from model.");
        }
    }
}

void InvoicesForm::on_refreshInvoiceDetails_clicked()
{
    if(selectedInvoice && ui->InvoiceDetailsTableView->model()){
        QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(ui->InvoiceDetailsTableView->model());
        model->submit();
        model->submitAll();
        model->clear();
        setupInvoiceDetailsTableView();
        setColumnsStretch();
    }

}

void InvoicesForm::CalaculateTheChange(){

    QSqlRelationalTableModel *modelInvoices = qobject_cast<QSqlRelationalTableModel *>(ui->invoiceTableView->model());
    QSqlRelationalTableModel *modelInvoicesDetails = qobject_cast<QSqlRelationalTableModel *>(ui->InvoiceDetailsTableView->model());
    qDebug() << "changes have been detected";


    QItemSelectionModel *selectionModel = ui->InvoiceDetailsTableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    if (!selectedIndexes.isEmpty() && (selectedIndexes.at(0).column() == 3 || selectedIndexes.at(0).column() == 4 || selectedIndexes.at(0).column() == 5)) {
        double quantity = modelInvoicesDetails->data(modelInvoicesDetails->index(selectedIndexes.first().row(), 3)).toDouble();
        double rate = modelInvoicesDetails->data(modelInvoicesDetails->index(selectedIndexes.first().row(), 4)).toDouble();
        double amount = quantity*rate;

        QVariant *var = new QVariant;
        var->setValue(amount);
        modelInvoicesDetails->setData(modelInvoicesDetails->index(selectedIndexes.first().row(), 5), *var);
        if (!modelInvoicesDetails->submitAll()) {
            QMessageBox::warning(this, "Error", "Failed to save changes to database from invoiceDetails.");
        }
    }

    QString queryStr = QString(R"(
        SELECT SUM(amount)
        FROM InvoiceDetails
        WHERE invoice_id = %1
    )").arg(selectedInvoice);

    QSqlQuery query(Database::getDatabase());
    if (!query.exec(queryStr)) {
        qDebug() << "Failed to calculate the sum of the current row";
        return;
    }

    double totalAmount = 0;
    if (query.next()) {
        totalAmount += query.value(0).toDouble();
    }

    double vat = modelInvoices->data(modelInvoices->index(selectedInvoiceRow, 4)).toDouble();
    double vated = (vat/100)*totalAmount;

    double discount = modelInvoices->data(modelInvoices->index(selectedInvoiceRow, 5)).toDouble();
    double totdiscount = (discount/100)*totalAmount;

    totalAmount += vated;
    totalAmount -= totdiscount;

    QVariant *variantdisc = new QVariant;
    variantdisc->setValue(totdiscount);
    modelInvoices->setData(modelInvoices->index(selectedInvoiceRow, 6), *variantdisc);

    QVariant *variantTotal = new QVariant;
    variantTotal->setValue(totalAmount);
    modelInvoices->setData(modelInvoices->index(selectedInvoiceRow, 7), *variantTotal);

    if (!modelInvoices->submitAll()) {
        QMessageBox::warning(this, "Error", "Failed to save changes to database from invoices.");
    }
}
