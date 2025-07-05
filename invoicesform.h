#ifndef INVOICESFORM_H
#define INVOICESFORM_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QTableView>
#include <QSqlRelationalTableModel>

namespace Ui {
class InvoicesForm;
}

class InvoicesForm : public QWidget
{
    Q_OBJECT

public:
    explicit InvoicesForm(QWidget *parent = nullptr);
    ~InvoicesForm();

    void setColumnsStretch();
    void resetColumnsToDefault();

private slots:
    void on_InvoiceSearchButtonCustomers_clicked();

    void on_InvoicesSearchLineEditCustomers_returnPressed();

    void on_InvoicesSearchLineEditCustomers_textChanged(const QString &arg1);

    void on_InvoicesProductEditLine_returnPressed();

    void on_InvoicesProductEditLine_textChanged(const QString &arg1);

    void on_InvoicesSearchProduktItems_clicked();

    void on_generateInvoiceButton_clicked();


    void on_InvoiceDeleteRow_clicked();

    void on_invoiceTableView_clicked(const QModelIndex &index);

    void on_InvoiceInsertNewRow_clicked();

    void on_pushButton_clicked();

    void on_ProductInsertNewRow_clicked();

    void on_productDeleteRow_clicked();

    void on_refreshInvoiceDetails_clicked();



private:
    Ui::InvoicesForm *ui;

    void setupInvoiceTableView();

    void onInvoiceDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

    void setupInvoiceDetailsTableView();

    void search(QAbstractItemModel *model, QString saerchTerm, QTableView *table);

    int selectedInvoice = NULL;

    int selectedInvoiceRow = NULL;

    void FilterCurrentInvoice(QSqlRelationalTableModel *model);

    void CalaculateTheChange();
};

#endif // INVOICESFORM_H
