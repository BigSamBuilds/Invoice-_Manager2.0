#ifndef FUNCTOOLS_H
#define FUNCTOOLS_H
#include <QTableWidget>

class FuncTools
{
public:
    FuncTools();

    static void addLastRow(int row, QTableWidget *table );
    static void filterTable(QTableWidget *tableWidget, const QString &searchString);
    static void filterTable(QTableView *tableView, const QString &searchqurey);
    static void showAll(QTableWidget *table);
    static QString generateInvoiceHTML(QMap<QString, QString> values);

public slots:
    static void defaultCallbackFunc();
    static void ShowContextMenu(const QPoint &pos, QTableWidget *table, QWidget *widget, const std::function<void()>& callback = defaultCallbackFunc);
    static void ShowContextMenu(const QPoint &pos, QTableView *table, QWidget *widget, bool restrict = false, const std::function<void()>& callback = defaultCallbackFunc);

private:

};

#endif // FUNCTOOLS_H
