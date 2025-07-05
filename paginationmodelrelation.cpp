#include "paginationmodelrelation.h"
#include "Controller/database.h"

#include <QSqlError>

PaginationModelRelation::PaginationModelRelation(const QString &tbName, QSqlDatabase db, QObject *parent, bool removeCol, int numberCol, QString selectionQr)
    : QSqlRelationalTableModel(parent, db), tableName(tbName), filterString(""), StatusPageLabel(nullptr), filterSat(false), m_pageSize(10), m_currentPage(0), m_rowCount(0) {
    setTable(tableName);
    if (removeCol) {
        removeColumn(numberCol);
    }
    selectionQuery = selectionQr;
    select();  // Ensure select is called after setting the table
}

int PaginationModelRelation::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_pageSize;
}

QVariant PaginationModelRelation::data(const QModelIndex &index, int role) const {
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

void PaginationModelRelation::nextPage() {
    if (m_currentPage < pageCount() - 1) {
        ++m_currentPage;
        select();
    }
}

void PaginationModelRelation::previousPage() {
    if (m_currentPage > 0) {
        --m_currentPage;
        select();
    }
}

void PaginationModelRelation::refresh() {
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

int PaginationModelRelation::pageCount() const {
    return (m_rowCount + m_pageSize - 1) / m_pageSize;
}

bool PaginationModelRelation::select() {
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
    QString queryStr = filterSat ? selectionQuery : QString("SELECT * FROM %1 ORDER BY ID DESC LIMIT %2 OFFSET %3").arg(tableName).arg(m_pageSize).arg(offset);
    if (!queryStr.contains("ORDER BY ID DESC", Qt::CaseInsensitive)) {
        queryStr += " ORDER BY ID DESC";
    }

    qDebug() << "Executing query:" << queryStr;
    QSqlQuery query(Database::getDatabase());
    if (!query.exec(queryStr)) {
        qDebug() << "Failed to execute pagination query:" << query.lastError().text();
        return false;
    }
    setQuery(query);
    UpdateStatusLabel(); // update the current label to user;
    return true;
}

void PaginationModelRelation::setFilter(const QString &filter) {
    filterSat = true;
    QString saveQuery = selectionQuery;

    if (!filter.isEmpty()) {
        selectionQuery = QString("SELECT * FROM %1 WHERE %2 ORDER BY ID DESC").arg(tableName).arg(filter);
    } else {
        selectionQuery = QString("SELECT * FROM %1 ORDER BY ID DESC").arg(tableName);
    }

    qDebug() << "Applying filter:" << selectionQuery;
    select();
    selectionQuery = saveQuery;
    filterSat = false;
}

QString PaginationModelRelation::getTableName(){
    return tableName;
}

QMap<QString, QString> PaginationModelRelation::getColumnNames(){
    return columnList;
}

void PaginationModelRelation::setColumnNames(QMap<QString, QString> list){
    this->columnList = list;
}


void PaginationModelRelation::reload(){
    clear();
    select();
}

void PaginationModelRelation::setStatusLabelOnPageUpdate(QLabel *statusPageLabel){
    this->StatusPageLabel = statusPageLabel;
}

void PaginationModelRelation::UpdateStatusLabel(){
    if(StatusPageLabel){
        StatusPageLabel->setText(QString("Current Page: %1").arg(m_currentPage+1));
    }
}
