#ifndef PAGINATEDSQLRELATIONALTABLEMODEL_H
#define PAGINATEDSQLRELATIONALTABLEMODEL_H

#include <QSqlRelationalTableModel>

class PaginatedSqlRelationalTableModel : public QSqlRelationalTableModel {
    Q_OBJECT

public:
    explicit PaginatedSqlRelationalTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

    void setPageSize(int pageSize);
    int pageSize() const;

    void setCurrentPage(int page);
    int currentPage() const;

    void nextPage();
    void previousPage();

    bool select();

protected:
    // void updateModel();

private:
    int m_pageSize;
    int m_currentPage;
};

#endif // PAGINATEDSQLRELATIONALTABLEMODEL_H
