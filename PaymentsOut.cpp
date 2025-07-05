#include "PaymentsOut.h"
#include "ui_PaymentsOut.h"
#include "Controller/database.h"
#include "booleancomboboxdelegate.h"
#include <QStyledItemDelegate>

#include <QMap>
#include <QSqlRelationalDelegate>
#include <QSqlError>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDate>
#include <QPainter>

VendorsForm::VendorsForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VendorsForm)
{
    ui->setupUi(this);

    //setupt vendors table view
    setupVendorsTableView();

}

VendorsForm::~VendorsForm()
{
    delete ui;
}


void VendorsForm::searchIngVendors(QAbstractItemModel *model){
    QString filterText = ui->searchLineEdit->text();
    // QAbstractItemModel *model = ui->VendorsTableView->model();

    if (!model) {
        qWarning() << "Model is not set!";
        return;
    }

    int paidColumn = 4; // Column index for the paid status

    for (int row = 0; row < model->rowCount(); ++row) {
        bool match = false;
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();

            // Convert the boolean column to text for comparison
            if (column == paidColumn) {
                data = (model->data(index).toInt() == 1) ? "fulfilled" : "pending";
                qDebug() << model->data(index).toString() << "   " << data;
            }

            if (data.contains(filterText, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->VendorsTableView->setRowHidden(row, !match);
    }
}

void VendorsForm::searchIngItemBought(QAbstractItemModel *model){
    if (vendorIDForItemBought == NULL) {
        QMessageBox::warning(this, "No Payment selected", "Please select a payment. ");
        return;
    }
    QString filterText = ui->VendorsSearchEditLine->text();
    // QAbstractItemModel *model = ui->VendorsTableView->model();

    if (!model) {
        qWarning() << "Model is not set!";
        return;
    }


    for (int row = 0; row < model->rowCount(); ++row) {
        bool match = false;
        for (int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            if (data.contains(filterText, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->ItemBoughtTableView->setRowHidden(row, !match);
    }
}

void VendorsForm::on_searchLineEdit_returnPressed()
{
    searchIngVendors(ui->VendorsTableView->model());
}


void VendorsForm::on_searchButton_clicked()
{
    searchIngVendors(ui->VendorsTableView->model());
}


void VendorsForm::on_searchLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    searchIngVendors(ui->VendorsTableView->model());
}


void VendorsForm::on_VendorsSearchEditLine_returnPressed()
{
    searchIngItemBought(ui->ItemBoughtTableView->model());// FuncTools::filterTable(ui->itemsBoughtTableWidget, ui->VendorsSearchEditLine->text());
}


void VendorsForm::on_VendorsSearchEditLine_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    searchIngItemBought(ui->ItemBoughtTableView->model());// FuncTools::showAll(ui->itemsBoughtTableWidget);
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



void VendorsForm::on_VendorsItemSearchButton_clicked()
{
     searchIngItemBought(ui->ItemBoughtTableView->model());// FuncTools::filterTable(ui->itemsBoughtTableWidget, ui->VendorsSearchEditLine->text());
}

void VendorsForm::setColumnsStretch() {
    ui->VendorsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->ItemBoughtTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void VendorsForm::resetColumnsToDefault() {
    ui->VendorsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->ItemBoughtTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

class CustomItemDelegate2 : public QStyledItemDelegate {
public:
    CustomItemDelegate2(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        // Disable editing for columns ID (0), File Size (2), and File Date (3)
        if (index.column() == 0) {
            return nullptr; // Return nullptr to disable editing
        }
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
};

void VendorsForm::setupVendorsTableView(){

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this, Database::getDatabase());

    // Set the main table for the model (PaymentOut in this case)
    model->setTable("PaymentOut");
    model->setSort(0, Qt::DescendingOrder);

    // Set the relations for vendor_id to Vendors table
    model->setRelation(model->fieldIndex("vendor_id"), QSqlRelation("Vendors", "id", "name"));

    // Select the data
    model->select();

    // Set the model to your view
    ui->VendorsTableView->setModel(model);

    NumberDelegate *col1 = new NumberDelegate(this);
    ui->VendorsTableView->setItemDelegateForColumn(3, col1);

    // Set the item delegate for handling foreign keys
    ui->VendorsTableView->setItemDelegate(new QSqlRelationalDelegate(ui->VendorsTableView));

    // Set the custom delegate for the boolean column (assuming it's the last column)
    int boolColumn = model->fieldIndex("paid");
    BooleanComboBoxDelegate * bComb = new BooleanComboBoxDelegate(ui->VendorsTableView);

    ui->VendorsTableView->setItemDelegateForColumn(boolColumn, bComb);

}

void VendorsForm::on_VendorsTableView_clicked(const QModelIndex &index)
{
    QString ID = ui->VendorsTableView->model()->data(index.sibling(index.row(), 0)).toString();
    if (index.isValid() && !ID.trimmed().isEmpty()) {
        QApplication::setOverrideCursor(Qt::WaitCursor);
        QApplication::processEvents();
        QString ID = ui->VendorsTableView->model()->data(index.sibling(index.row(), 0)).toString();
        QString Name = ui->VendorsTableView->model()->data(index.sibling(index.row(), 1)).toString();
        QString RecentChange = ui->VendorsTableView->model()->data(index.sibling(index.row(), 2)).toString();
        // qDebug() << "ID: " + ID + " Name: " + Name + " Changes: " + RecentChange;
        ui->VendorsIDStatus->setText("ID: " + ID);
        ui->VendorsNameStatus->setText("Name: " + Name);
        ui->VendorsRecentChangesStatus->setText("Recent Change: " + RecentChange);

        vendorIDForItemBought = ID.toInt();

        if (!vendorIDForItemBought) {
            QMessageBox::warning(this, "No Selection", "Please select a row.");
            return;
        }
        setupItemBoughtTableView();
        QApplication::restoreOverrideCursor();
    }
}

void VendorsForm::FilterCurrentPayment(QSqlRelationalTableModel *model){
    if (model) {
        // Set the filter to filter items based on the vendor ID
        model->setFilter(QString("payment_id = %1").arg(vendorIDForItemBought));
        if (!model->select()) {
            qDebug() << "Error selecting filtered data from ItemBought:" << model->lastError();
        }
    }
}

void VendorsForm::setupItemBoughtTableView() {

    if (!vendorIDForItemBought) {
        QMessageBox::warning(this, "No Selection", "Please select a row.");
        return;
    }


    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this, Database::getDatabase());

    // Set the table to ItemBought
    model->setTable("ItemBought");
    model->setSort(0, Qt::DescendingOrder);

    // // Set the relation for item_id to Items table
    model->setRelation(model->fieldIndex("item_id"), QSqlRelation("Items", "id", "item"));

    // // Set the relation for payment_id to PaymentOut table
    model->setRelation(model->fieldIndex("payment_id"), QSqlRelation("PaymentOut", "id", "id"));

    // Select data from the model
    if (!model->select()) {
        qDebug() << "Error selecting data from ItemBought:" << model->lastError();
        return;
    }

    // Set header names
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Item"));
    model->setHeaderData(2, Qt::Horizontal, tr("Quantity"));
    model->setHeaderData(3, Qt::Horizontal, tr("Rate"));
    model->setHeaderData(4, Qt::Horizontal, tr("Amount"));
    model->setHeaderData(5, Qt::Horizontal, tr("Date"));
    model->setHeaderData(6, Qt::Horizontal, tr("Comment"));
    model->setHeaderData(7, Qt::Horizontal, tr("Payment Out ID"));


    // Set the model to the view
    FilterCurrentPayment(model);
    ui->ItemBoughtTableView->setModel(model);

    NumberDelegate *quant = new NumberDelegate(this);
    ui->ItemBoughtTableView->setItemDelegateForColumn(2, quant);
    NumberDelegate *Rate = new NumberDelegate(this);
    ui->ItemBoughtTableView->setItemDelegateForColumn(3, Rate);
    NumberDelegate *amount = new NumberDelegate(this);
    ui->ItemBoughtTableView->setItemDelegateForColumn(4, amount);

    // Set the item delegate for handling foreign keys
    ui->ItemBoughtTableView->setItemDelegate(new QSqlRelationalDelegate(ui->ItemBoughtTableView));
    // Connect the dataChanged signal to a slot
    connect(model, &QSqlRelationalTableModel::dataChanged, this, &VendorsForm::onDataChanged);

}

void VendorsForm::onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
    Q_UNUSED(bottomRight)
    Q_UNUSED(roles)

    QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(sender());
    if (!model)
        return;

    int row = topLeft.row();
    int column = topLeft.column();

    // Check if quantity or rate has changed
    if (column == 2 || column == 3 || column == 4) {
        int quantity = model->data(model->index(row, 2)).toInt();
        double rate = model->data(model->index(row, 3)).toDouble();
        double amount = quantity * rate;

        // Update the amount in the model
        QVariant var;
        var.setValue(amount);
        model->setData(model->index(row, 4), var);

        // Assuming vendorIDForItemBought holds the current payment_id
        int payment_id = vendorIDForItemBought;

        // SQL query to calculate the sum of amounts for the specific payment_id
        QString queryStr = QString(R"(
        SELECT SUM(amount)
        FROM ItemBought
        WHERE payment_id = %1
    )").arg(payment_id);

        QSqlQuery query(Database::getDatabase());
        if (!query.exec(queryStr)) {
            qDebug() << "Failed to calculate the sum of the current row";
            return;
        }

        double totalAmount = amount;
        if (query.next()) {
            totalAmount += query.value(0).toDouble();
        }

        QSqlRelationalTableModel *model2 = qobject_cast<QSqlRelationalTableModel *>(ui->VendorsTableView->model());

        QVariant *varw = new QVariant();
        varw->setValue(totalAmount);
        QModelIndex inx = ui->VendorsTableView->currentIndex();
        model2->setData(model2->index(inx.row(), 3), *varw);
        model2->submit();
        model2->submitAll();
        model->submit();
        model->submitAll();
    }

}

void VendorsForm::on_DeleteCurrentRowVendors_clicked()
{
    QMessageBox msgBox(this);
    msgBox.setText(QString("Are you sure you want delete row: %1 ?").arg(vendorIDForItemBought));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Cancel) {
        // Cancel was pressed, return immediately
        return;
    }

    QItemSelectionModel *selectionModel = ui->VendorsTableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
        return;
    }

    // Get the row of the first selected index (assuming single row selection)
    int rowToDelete = selectedIndexes.first().row();

    // Remove the row from the model
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->VendorsTableView->model());
    if (!model) {
        qWarning() << "Model is not a QSqlTableModel!";
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

class VendorSelectionDialog : public QDialog {
public:
    VendorSelectionDialog(QString quaryString, QString header = "Select: ", QWidget *parent = nullptr)
        : QDialog(parent)
    {
        this->setMinimumWidth(120);
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
            QMessageBox::critical(this, "Error", "Failed to fetch vendors from database.");
        }
    }

    int selectedVendorId() const {
        return vendorComboBox->currentData().toInt();
    }

private:
    QComboBox *vendorComboBox;
};

void VendorsForm::on_InsertNewRowVendors_clicked()
{
    // Create and exec the vendor selection dialog
    VendorSelectionDialog dialog("SELECT id, name FROM Vendors ORDER BY name", "Select vendor: ", this);
    if (dialog.exec() == QDialog::Accepted) {
        int selectedVendorId = dialog.selectedVendorId();

        // Insert new row into PaymentOut table
        QSqlDatabase db = Database::getDatabase();
        QSqlQuery query(db);
        query.prepare("INSERT INTO PaymentOut (vendor_id, date, TotalAmount, paid) VALUES (:vendorId, :date, :totalAmount, :paid)");
        query.bindValue(":vendorId", selectedVendorId);
        query.bindValue(":date", QDate::currentDate().toString(Qt::ISODate));
        query.bindValue(":totalAmount", 0.0);  // Default value for TotalAmount
        query.bindValue(":paid", false);  // Default value for paid

        if (query.exec()) {
            QMessageBox::information(this, "Success", "New payment record inserted successfully.");
            // Optionally refresh the view or do other updates
            QSqlRelationalTableModel *model = qobject_cast<QSqlRelationalTableModel *>(ui->VendorsTableView->model());
            model->select();
        } else {
            QMessageBox::critical(this, "Error", "Failed to insert new payment record into database: " + query.lastError().text());
        }
    }
}

void VendorsForm::on_InsertNewRowItems_clicked()
{
    if (vendorIDForItemBought == NULL) {
        QMessageBox::warning(this, "No Payment selected", "Please select a payment. ");
        return;
    }
    VendorSelectionDialog dialog("SELECT id, item FROM Items ORDER BY item", "Select item: ", this);
    if (dialog.exec() == QDialog::Accepted) {

        // Now you have vendorId, you can proceed to insert into ItemBought table
        QSqlQuery insertQuery(Database::getDatabase());
        insertQuery.prepare("INSERT INTO ItemBought (item_id, quantity, rate, amount, date, comment, payment_id) "
                            "VALUES (:item_id, :quantity, :rate, :amount, :date, :comment, :payment_id)");
        insertQuery.bindValue(":item_id", dialog.selectedVendorId()); // Replace with actual item_id value
        insertQuery.bindValue(":quantity", 0); // Replace with actual quantity value
        insertQuery.bindValue(":rate", 0.0); // Replace with actual rate value
        insertQuery.bindValue(":amount", 0.0); // Replace with actual amount value
        insertQuery.bindValue(":date", QDate::currentDate().toString(Qt::ISODate)); // Replace with actual date value
        insertQuery.bindValue(":comment", "New Item Bought"); // Replace with actual comment value
        insertQuery.bindValue(":payment_id", vendorIDForItemBought);

        if (!insertQuery.exec()) {
            QMessageBox::critical(this, "Error", "Failed to insert new row into ItemBought table: " + insertQuery.lastError().text());
            return;
        }
        // Refresh the ItemBoughtTableView to reflect the new data
        setupItemBoughtTableView(); // Assuming this function refreshes the view
    }
}

void VendorsForm::on_DeleteCurrentRowItems_clicked()
{

    if (vendorIDForItemBought == NULL) {
        QMessageBox::warning(this, "No Payment selected", "Please select a payment. ");
        return;
    }
    QItemSelectionModel *selectionModel = ui->ItemBoughtTableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();


    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
        return;
    }

    // Get the row of the first selected index (assuming single row selection)
    int rowToDelete = selectedIndexes.first().row();

    QMessageBox msgBox(this);
    msgBox.setText(QString("Are you sure you want delete row number: %1 ?").arg(ui->ItemBoughtTableView->model()->index(rowToDelete, 0).data().toString()));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int ret = msgBox.exec();

    if (ret == QMessageBox::Cancel) {
        // Cancel was pressed, return immediately
        return;
    }



    // Remove the row from the model
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->ItemBoughtTableView->model());
    if (!model) {
        qWarning() << "Model is not a QSqlTableModel!";
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


void VendorsForm::on_RefreshPaymentsOutBtn_clicked()
{
    setupVendorsTableView();
}


void VendorsForm::on_RefreshItemBoguthItemBtn_clicked()
{
    if(vendorIDForItemBought){
        setupItemBoughtTableView();
    }
}

