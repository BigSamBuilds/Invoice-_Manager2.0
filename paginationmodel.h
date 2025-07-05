#ifndef PAGINATIONMODEL_H
#define PAGINATIONMODEL_H

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QLabel>

class PaginationModel : public QSqlTableModel {
    Q_OBJECT
    QString tableName;
public:
    explicit PaginationModel(const QString &tbName, QSqlDatabase db, QObject *parent = nullptr, bool removeCol = false, int numberCol = 0, QString selectionQuery = "");

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

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void flagsOn(bool arg);

    void filterByQuery(const QString &query);

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

    bool flagsSatted = false;


};

#endif // PAGINATIONMODEL_H
