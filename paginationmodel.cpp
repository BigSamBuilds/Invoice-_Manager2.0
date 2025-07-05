#include "paginationmodel.h"
#include "Controller/database.h"

#include <QSqlError>

PaginationModel::PaginationModel(const QString &tbName, QSqlDatabase db, QObject *parent, bool removeCol, int numberCol, QString selectionQr)
    : QSqlTableModel(parent, db), tableName(tbName), filterString(""), StatusPageLabel(nullptr), filterSat(false ), flagsSatted(false) {
    setTable(tableName);
    if(removeCol){
        removeColumn(numberCol);
    }
    selectionQuery = selectionQr;
    // select();
}

int PaginationModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_pageSize;
}

QVariant PaginationModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        int row = index.row();
        int column = index.column();
        int realRow = row + m_currentPage * m_pageSize;
        return QSqlTableModel::data(createIndex(realRow, column), role);
    }

    return QSqlTableModel::data(index, role);
}

void PaginationModel::nextPage() {
    if (m_currentPage < pageCount() - 1) {
        ++m_currentPage;
        select();
    }
}

void PaginationModel::previousPage() {
    if (m_currentPage > 0) {
        --m_currentPage;
        select();
    }
}

void PaginationModel::refresh() {
    // // Attempt to submit pending changes to the database
    if (!submit()) {
        qDebug() << "Error submitting changes:" << lastError().text();
        // revertAll(); // Revert any changes if submission fails
    }else{
        if (!submitAll()) {
            qDebug() << "Error submitting changes:" << lastError().text();
            // revertAll(); // Revert any changes if submission fails
        }
    }

    // Clear the model to prepare for reloading data
    // clear();

    // Select data again from the database
    if (!select()) {
        qDebug() << "Error selecting data:" << lastError().text();
    }
}

int PaginationModel::pageCount() const {
    return (m_rowCount + m_pageSize - 1) / m_pageSize;
}

bool PaginationModel::select() {
    QSqlQuery countQuery;
    if (!countQuery.exec("SELECT COUNT(*) FROM " + tableName)) {
        qDebug() << "Failed to execute count query:" << countQuery.lastError().text();
        return false;
    }
    if (countQuery.next()) {
        m_rowCount = countQuery.value(0).toInt();
    } else {
        qDebug() << "Failed to retrieve row count:" << countQuery.lastError().text();
        return false;
    }

    int offset = m_currentPage * m_pageSize;
    Q_UNUSED(offset);
    QString queryStr;
    if(!filterSat){
        //  qDebug() << QString("SELECT * FROM %1 LIMIT %2 OFFSET %3").arg(tableName).arg(m_pageSize).arg(offset);
         queryStr = QString("SELECT * FROM %1 ORDER BY ID DESC").arg(tableName);//.arg(m_pageSize).arg(offset);
        if (!selectionQuery.isEmpty()) {
             queryStr = selectionQuery;
        }
    }else{
        queryStr = selectionQuery;
    }

    if(!queryStr.contains("ORDER BY", Qt::CaseInsensitive)){
        queryStr +=  QString(" ORDER BY ID DESC ");
    }

    // qDebug() << "select final query: " << queryStr;
    QSqlQuery query(Database::getDatabase());
    if (!query.exec(queryStr)) {
        qDebug() << "Failed to execute pagination query:" << query.lastError().text();
        return false;
    }
    setQuery(query);
    UpdateStatusLabel(); // update the current lable to user;
    return true;
}

QString PaginationModel::getTableName(){
    return tableName;
}

QMap<QString, QString> PaginationModel::getColumnNames(){
    return columnList;
}

void PaginationModel::setColumnNames(QMap<QString, QString> list){
    this->columnList = list;
}

void PaginationModel::setFilter(const QString &filter) {
    filterSat = true;
    QString saveQuary = selectionQuery;
    // qDebug() << "saved Query filter: " << saveQuary;
    if (!filter.isEmpty()) {
        // Set the custom filter query
        if(selectionQuery.isEmpty()){
             selectionQuery = QString(R"(SELECT * FROM %1 WHERE %2 ORDER BY ID DESC)").arg(tableName).arg(filter);
        }else{
            selectionQuery += QString(R"( WHERE %1  ORDER BY ID DESC )").arg(filter);
        }

    } else {
        // Default query without filter
        if(selectionQuery.isEmpty()){
            selectionQuery = QString("SELECT * FROM %1 ORDER BY ID DESC ").arg(tableName);
        }
    }
    // qDebug() << "Applying filter:" << selectionQuery;
    select();
    selectionQuery = saveQuary;
    // qDebug() << "released Query: " << saveQuary;
    filterSat = false;
}

void PaginationModel::reload(){
    clear();
    select();
}

void PaginationModel::setStatusLabelOnPageUpdate(QLabel *statusPageLabel){
    this->StatusPageLabel = statusPageLabel;
}

void PaginationModel::UpdateStatusLabel(){
    if(StatusPageLabel){
        StatusPageLabel->setText(QString("Current Page: %1").arg(m_currentPage+1));
    }
}

Qt::ItemFlags PaginationModel::flags(const QModelIndex &index) const {
    Qt::ItemFlags flags = QSqlTableModel::flags(index);
    if(flagsSatted){


        // // Assuming column 5 is the one you want to be editable
        // if (index.column() == 5) {
        //     flags |= Qt::ItemIsEditable; // Make column 5 editable
        // } else {
            flags &= ~Qt::ItemIsEditable; // Make other columns non-editable
        // }


    }
    return flags;
}

void PaginationModel::flagsOn(bool arg){
    flagsSatted = arg;
}

void PaginationModel::filterByQuery(const QString &query){
    filterSat = true;
    QString saveQuary = selectionQuery;
    selectionQuery = query;
    // qDebug() << "Applying filter:" << selectionQuery;
    select();
    selectionQuery = saveQuary;
    // qDebug() << "released Query: " << saveQuary;
    filterSat = false;
}
