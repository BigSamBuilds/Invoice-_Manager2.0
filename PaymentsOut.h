#ifndef PAYMENTSOUT_H
#define PAYMENTSOUT_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QSqlRelationalTableModel>

namespace Ui {
class VendorsForm;
}

class VendorsForm : public QWidget
{
    Q_OBJECT

public:
    explicit VendorsForm(QWidget *parent = nullptr);
    ~VendorsForm();

    void setColumnsStretch();
    void resetColumnsToDefault();

private slots:
    // void ShowContextMenuVendors(const QPoint &);
    // void ShowContextMenuItems(const QPoint &);
    // void on_vendorsTableWidget_cellChanged(int row, int column);

    // void on_itemsBoughtTableWidget_cellChanged(int row, int column);

    void on_searchLineEdit_returnPressed();

    void on_searchButton_clicked();

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_VendorsSearchEditLine_returnPressed();

    void on_VendorsSearchEditLine_textChanged(const QString &arg1);

    void on_VendorsItemSearchButton_clicked();

    // void on_vendorsTableWidget_cellClicked(int row, int column);

    // void on_itemsBoughtTableWidget_cellClicked(int row, int column);

    void on_VendorsTableView_clicked(const QModelIndex &index);

    void onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

    void on_DeleteCurrentRowVendors_clicked();

    void on_InsertNewRowVendors_clicked();

    void on_InsertNewRowItems_clicked();

    void on_DeleteCurrentRowItems_clicked();

    void on_RefreshPaymentsOutBtn_clicked();

    void on_RefreshItemBoguthItemBtn_clicked();

private:
    Ui::VendorsForm *ui;

    void setupVendorsTableView();

    void setupItemBoughtTableView();

    int vendorIDForItemBought = NULL;

    void searchIngVendors(QAbstractItemModel *model);

    void searchIngItemBought(QAbstractItemModel *model);

    void FilterCurrentPayment(QSqlRelationalTableModel *model);

};

#endif // PAYMENTSOUT_H
