#include "Vendors2Form.h"
#include "ui_Vendors2Form.h"
#include "paginationmodel.h"
#include "controller/database.h"
#include "functools.h"

#include <QComboBox>

PaymentOutForm::PaymentOutForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PaymentOutForm)
{
    ui->setupUi(this);
    ui->VendorsTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->VendorsTableView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));

    setuptableView();

}


PaymentOutForm::~PaymentOutForm()
{
    delete ui;
}

void PaymentOutForm::ShowContextMenu(const QPoint &pos){
    FuncTools::ShowContextMenu(pos, ui->VendorsTableView, this);
}

void PaymentOutForm::on_searchLineEdit_returnPressed()
{
    QString filter = QString("id LIKE '%%1%' OR name LIKE '%%1%' OR address LIKE '%%1%' OR email LIKE '%%1%' OR RecentChange LIKE '%%1%'").arg(ui->searchLineEdit->text());
    //filter the the table
    FuncTools::filterTable(ui->VendorsTableView, filter);
}


void PaymentOutForm::on_searchLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString filter = QString("id LIKE '%%1%' OR name LIKE '%%1%' OR address LIKE '%%1%' OR email LIKE '%%1%' OR RecentChange LIKE '%%1%'").arg(ui->searchLineEdit->text());
    //filter the the table
    FuncTools::filterTable(ui->VendorsTableView, filter);
}


void PaymentOutForm::on_searchButton_clicked()
{
    QString filter = QString("id LIKE '%%1%' OR name LIKE '%%1%' OR address LIKE '%%1%' OR email LIKE '%%1%' OR RecentChange LIKE '%%1%'").arg(ui->searchLineEdit->text());
    //filter the the table
    FuncTools::filterTable(ui->VendorsTableView, filter);
}

void PaymentOutForm::setColumnsStretch() {
    ui->VendorsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void PaymentOutForm::resetColumnsToDefault() {
    ui->VendorsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}


void PaymentOutForm::setuptableView(){
    PaginationModel *model = new PaginationModel("Vendors", Database::getDatabase());
    ui->VendorsTableView->setModel(model);
    QMap<QString, QString> columns;
    columns["id"] = "0";
    columns["name"] = R"(" ")";
    columns["address"] = R"(" ")";
    columns["email"] = R"(" ")";
    columns["RecentChange"] = R"(" ")";
    model->setColumnNames(columns);
    model->setStatusLabelOnPageUpdate(ui->VendorPageStatus);
    model->refresh();
}

void PaymentOutForm::on_VendorsTableView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    resetColumnsToDefault();
}


void PaymentOutForm::on_VendorsTableView_activated(const QModelIndex &index)
{
    Q_UNUSED(index);
    resetColumnsToDefault();
}

