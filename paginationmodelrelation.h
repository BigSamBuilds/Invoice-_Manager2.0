#ifndef PAGINATIONMODELRELATION_H
#define PAGINATIONMODELRELATION_H

#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QLabel>
#include <QWidget>

class PaginationModelRelation: public QSqlRelationalTableModel {
    Q_OBJECT
    QString tableName;
public:
    explicit PaginationModelRelation(const QString &tbName, QSqlDatabase db, QObject *parent = nullptr, bool removeCol = false, int numberCol = 0, QString selectionQuery = "");

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void nextPage();
    void previousPage();
    void refresh();
    void removeCol(int column);
    bool select() override;
    void setFilter(const QString &filter);
    QString getTableName();
    QMap<QString, QString> getColumnNames();
    void setColumnNames(QMap<QString, QString> list);

    void reload();

    void setStatusLabelOnPageUpdate(QLabel *statusPageLabel);

private:
    int m_pageSize = 50; // Number of rows per page
    int m_currentPage = 0; // Current page index
    int m_rowCount = 0; // Total number of rows in the table

    int pageCount() const;

    QString selectionQuery;

    QString filterString;
    QLabel *StatusPageLabel;

    QMap<QString, QString> columnList;

    void UpdateStatusLabel();

    bool filterSat = false;


};

#endif // PAGINATIONMODEL_H
