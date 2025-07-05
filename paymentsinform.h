#ifndef PAYMENTSINFORM_H
#define PAYMENTSINFORM_H

#include <QWidget>

namespace Ui {
class PaymentsInForm;
}

class PaymentsInForm : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentsInForm(QWidget *parent = nullptr);
    ~PaymentsInForm();

    void setColumnsStretch();
    void resetColumnsToDefault();

private slots:

    void on_tableView_clicked(const QModelIndex &index);

    void on_SetInvoiceStatus_clicked();

    void on_searchLineEdit_returnPressed();

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_searchButton_clicked();

    void ShowContextMenu(const QPoint &);

private:
    Ui::PaymentsInForm *ui;

    void setupTableView();

    QString selectedCustomerId = nullptr;
    int selectedCustomerRowNmb = NULL;
    QString selectedCustomerStatus = nullptr;

    void filterTable();


};

#endif // PAYMENTSINFORM_H
