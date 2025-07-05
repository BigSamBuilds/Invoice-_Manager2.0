#include "itemform.h"
#include "ui_itemform.h"
#include "functools.h"
#include "controller/database.h"
#include "paginationmodel.h"

#include <QSqlTableModel>


ItemForm::ItemForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ItemForm)
{
    ui->setupUi(this);
    ui->ItemsTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->ItemsTableView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));

    setTableModel();
}

ItemForm::~ItemForm()
{
    delete ui;
}


void ItemForm::on_ItemsSearchButton_clicked()
{
    QString filter = QString("ID LIKE '%%1%' OR item LIKE '%%1%' OR location LIKE '%%1%' OR comment LIKE '%%1%' OR date LIKE '%%1%'").arg(ui->ItemsLineEditSearch->text());
    //filter the the table
    FuncTools::filterTable(ui->ItemsTableView, filter);
}


void ItemForm::on_ItemsLineEditSearch_returnPressed()
{
    QString filter = QString("ID LIKE '%%1%' OR item LIKE '%%1%' OR location LIKE '%%1%' OR comment LIKE '%%1%' OR date LIKE '%%1%'").arg(ui->ItemsLineEditSearch->text());
    //filter the the table
    FuncTools::filterTable(ui->ItemsTableView, filter);
}


void ItemForm::on_ItemsLineEditSearch_textChanged(const QString &arg1)
{
    QString filter = QString("ID LIKE '%%1%' OR item LIKE '%%1%' OR location LIKE '%%1%' OR comment LIKE '%%1%' OR date LIKE '%%1%'").arg(ui->ItemsLineEditSearch->text());
    //filter the the table
    FuncTools::filterTable(ui->ItemsTableView, filter);
}

void ItemForm::ShowContextMenu(const QPoint &pos){
    FuncTools::ShowContextMenu(pos, ui->ItemsTableView, this);
}


void ItemForm::setColumnsStretch() {
    ui->ItemsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ItemForm::resetColumnsToDefault() {
    ui->ItemsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}


void ItemForm::setTableModel(){
    PaginationModel *model = new PaginationModel("Items", Database::getDatabase());
    ui->ItemsTableView->setModel(model);
    QMap<QString, QString> columns;
    columns["id"] = "0";
    columns["item"] = R"(" ")";
    columns["location"] = R"(" ")";
    columns["comment"] = R"(" ")";
    columns["date"] = R"(" ")";//    = {"id", "item", "location", "comment", "date"};
    model->setColumnNames(columns);
    model->setStatusLabelOnPageUpdate(ui->statusLabelItems);
    model->refresh();
}

void ItemForm::on_ItemsTableView_activated(const QModelIndex &index)
{
    resetColumnsToDefault();
}

