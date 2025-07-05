#include "customersform.h"
#include "ui_customersform.h"
#include "functools.h"
#include "paginationmodel.h"
#include "Controller/database.h"

CustomersForm::CustomersForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomersForm)
{
    ui->setupUi(this);

    setupCustomerTableView();

    ui->customerTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->customerTableView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));

}

CustomersForm::~CustomersForm()
{
    delete ui;
}


void CustomersForm::on_searchLineEdit_returnPressed()
{
    QString filter = QString("id LIKE '%%1%' OR name LIKE '%%1%' OR address LIKE '%%1%' OR comment LIKE '%%1%' OR email LIKE '%%1%'").arg(ui->searchLineEdit->text());
    //filter the the table
    FuncTools::filterTable(ui->customerTableView, filter);
}


void CustomersForm::on_searchLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString filter = QString("id LIKE '%%1%' OR name LIKE '%%1%' OR address LIKE '%%1%' OR comment LIKE '%%1%' OR email LIKE '%%1%'").arg(ui->searchLineEdit->text());
    //filter the the table
    FuncTools::filterTable(ui->customerTableView, filter);
}


void CustomersForm::on_searchButton_clicked()
{
    QString filter = QString("id LIKE '%%1%' OR name LIKE '%%1%' OR address LIKE '%%1%' OR comment LIKE '%%1%' OR email LIKE '%%1%'").arg(ui->searchLineEdit->text());
    //filter the the table
    FuncTools::filterTable(ui->customerTableView, filter);
}

void CustomersForm::ShowContextMenu(const QPoint &pos){
    FuncTools::ShowContextMenu(pos, ui->customerTableView, this);
}

void CustomersForm::setColumnsStretch() {
    ui->customerTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void CustomersForm::resetColumnsToDefault() {
    ui->customerTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}


void CustomersForm::setupCustomerTableView(){
    PaginationModel *model = new PaginationModel("Customers", Database::getDatabase());
    ui->customerTableView->setModel(model);
    QMap<QString, QString> columns;
    columns["id"] = "0";
    columns["name"] = R"(" ")";
    columns["address"] = R"(" ")";
    columns["email"] = R"(" ")";
    columns["comment"] = R"(" ")";//    = {"id", "item", "location", "comment", "date"};
    model->setColumnNames(columns);
    model->setStatusLabelOnPageUpdate(ui->CustomerPageStatus);
    model->refresh();
}

