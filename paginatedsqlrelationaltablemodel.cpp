#include "PaginatedSqlRelationalTableModel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

PaginatedSqlRelationalTableModel::PaginatedSqlRelationalTableModel(QObject *parent, QSqlDatabase db)
    : QSqlRelationalTableModel(parent, db), m_pageSize(10), m_currentPage(0)
{
}

void PaginatedSqlRelationalTableModel::setPageSize(int pageSize)
{
    m_pageSize = pageSize;
    select();
}

int PaginatedSqlRelationalTableModel::pageSize() const
{
    return m_pageSize;
}

void PaginatedSqlRelationalTableModel::setCurrentPage(int page)
{
    if (page >= 0 && page != m_currentPage) {
        m_currentPage = page;
        select();
    }
}

int PaginatedSqlRelationalTableModel::currentPage() const
{
    return m_currentPage;
}

void PaginatedSqlRelationalTableModel::nextPage()
{
    setCurrentPage(m_currentPage + 1);
}

void PaginatedSqlRelationalTableModel::previousPage()
{
    if (m_currentPage > 0) {
        setCurrentPage(m_currentPage - 1);
    }
}

bool PaginatedSqlRelationalTableModel::select()
{
    int offset = m_currentPage * m_pageSize;
    QString queryStr = QString("SELECT * FROM %1 LIMIT %2 OFFSET %3")
                           .arg(tableName())
                           .arg(m_pageSize)
                           .arg(offset);

    QSqlQuery query(database());
    query.prepare(queryStr);
    if (!query.exec()) {
        qWarning() << "Failed to execute paginated query:" << query.lastError().text();
        return false;
    }

    setQuery(query);
    return true;
}
