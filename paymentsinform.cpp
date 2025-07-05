#include "paymentsinform.h"
#include "ui_paymentsinform.h"
#include "paginationmodel.h"
#include "functools.h"
#include "Controller/database.h"
#include "booleancomboboxdelegate.h"
#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QPainter>

PaymentsInForm::PaymentsInForm(QWidget *parent)
    : QWidget(parent)

    , ui(new Ui::PaymentsInForm)

{
    ui->setupUi(this);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));

    setupTableView();
}

PaymentsInForm::~PaymentsInForm()
{
    delete ui;
}

void PaymentsInForm::setColumnsStretch() {
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void PaymentsInForm::resetColumnsToDefault() {
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
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

void PaymentsInForm::setupTableView(){
    PaginationModel *model = new PaginationModel("PaymentsIn", Database::getDatabase(), this, false, 0,
QString(R"(SELECT paymentsin.id AS ID, customers.name AS Customer, customers.address AS Address, invoices.total AS 'To Pay', invoices.date AS 'Register Date', paymentsin.paid AS 'Invoice Status' FROM PaymentsIn LEFT JOIN invoices ON PaymentsIn.invoice_id = invoices.id LEFT JOIN customers ON invoices.customer_id = customers.id GROUP BY PaymentsIn.id ORDER BY paymentsin.paid ASC, Paymentsin.id DESC )"));

    ui->tableView->setModel(model);
    model->setStatusLabelOnPageUpdate(ui->tableViewPageStatus);
    model->refresh();
    model->flagsOn(true); // ma
    BooleanComboBoxDelegate *boBox = new BooleanComboBoxDelegate(ui->tableView);
    ui->tableView->setItemDelegateForColumn(5, boBox);
    NumberDelegate *delegate = new NumberDelegate(this);
    ui->tableView->setItemDelegateForColumn(3, delegate);

}

void PaymentsInForm::on_tableView_clicked(const QModelIndex &index)
{
    QString id  = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    if(index.isValid() && id != ""){
        QString customer  = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 1)).toString();
        QString topay  = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 3)).toString();
        QString status  = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 5)).toString();

        selectedCustomerId = id;

        ui->SelectedRow->setText(QString(R"(ID: %4, Customer: %1, To Pay: %2, Status: %3)").arg(customer).arg(topay).arg(status == "0" ? "Pending":"Fullfiled").arg(id));
        // qDebug() << customer << " " << topay << " " << (status == "0" ? false : true);

        ui->SetInvoiceStatus->setText(QString("Change invoice status to %1").arg(status == "0" ? "Fullfiled":"Pending"));

    }else{
        ui->SelectedRow->setText(QString(R"(Select a row to change the invoice status. )"));
        ui->SetInvoiceStatus->setText(QString("Change invoice status"));
        selectedCustomerId = nullptr;
    }
}

void PaymentsInForm::on_SetInvoiceStatus_clicked()
{
    if(selectedCustomerId != nullptr){
        QMessageBox msgBox(this);
        msgBox.setText(QString("Are you sure you want change status for row: %1 ?").arg(selectedCustomerId));
        msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);

        int ret = msgBox.exec();

        if (ret == QMessageBox::Cancel) {
            // Cancel was pressed, return immediately
            return;
        }
        QSqlQuery query(Database::getDatabase());
        QString str = QString(R"(UPDATE PaymentsIn
                                                SET paid = CASE
                                                    WHEN paid = 0 THEN 1
                                                    ELSE 0
                                                END
                                                WHERE id = %1;
                                                 )").arg(selectedCustomerId);
        if(!query.exec(str)){
            qDebug() << "error chaging paymentis status: " << query.lastError().text();
            return;
        }

        PaginationModel *model = qobject_cast<PaginationModel*>(ui->tableView->model());
        model->refresh();
        ui->SelectedRow->setText(QString(R"(Select a row to change the invoice status. )"));
        ui->SetInvoiceStatus->setText(QString("Change invoice status"));
        selectedCustomerId = nullptr;
    }
}


void PaymentsInForm::filterTable(){
    PaginationModel *model = qobject_cast<PaginationModel*>(ui->tableView->model());
    QString userInput = ui->searchLineEdit->text(); // Get user input: "pending" or "fulfilled"
    QString paidFilter;

    if (QString("pending").contains(userInput.toLower(), Qt::CaseInsensitive)) {
        paidFilter = "0";
    } else if (QString("fulfilled").contains(userInput.toLower(), Qt::CaseInsensitive)) {
        paidFilter = "1";
    } else {
        paidFilter = userInput; // Or handle invalid input appropriately
    }

    // Construct the SQL query
    QString queryString = QString(
                              R"(
                SELECT
                    paymentsin.id AS ID,
                    customers.name AS Customer,
                    customers.address AS Address,
                    invoices.total AS "To Pay",
                    invoices.date AS "Register Date",
                    paymentsin.paid AS "Invoice Status"
                FROM
                    PaymentsIn
                LEFT JOIN
                    invoices ON PaymentsIn.invoice_id = invoices.id
                LEFT JOIN
                    customers ON invoices.customer_id = customers.id
                WHERE
                    paymentsin.id LIKE '%%1%' OR
                    customers.name LIKE '%%1%' OR
                    customers.address LIKE '%%1%' OR
                    invoices.total LIKE '%%1%' OR
                    invoices.date LIKE '%%1%' OR
                    paymentsin.paid LIKE '%%2%'

                GROUP BY
                    PaymentsIn.id
                ORDER BY
                    paymentsin.paid ASC,
                    PaymentsIn.id DESC;
                )").arg(ui->searchLineEdit->text()).arg(paidFilter);
    model->filterByQuery(queryString);
}

void PaymentsInForm::on_searchLineEdit_returnPressed()
{
    filterTable();
}


void PaymentsInForm::on_searchLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    filterTable();
}


void PaymentsInForm::on_searchButton_clicked()
{
    filterTable();
}


void PaymentsInForm::ShowContextMenu(const QPoint &pos){
    FuncTools::ShowContextMenu(pos, ui->tableView, this, true);
}
