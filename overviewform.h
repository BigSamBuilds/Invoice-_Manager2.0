#ifndef OVERVIEWFORM_H
#define OVERVIEWFORM_H

#include <QWidget>

namespace Ui {
class OverviewForm;
}

class OverviewForm : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewForm(QWidget *parent = nullptr);
    ~OverviewForm();

private slots:
    void on_PaymentsOutNextMonth_clicked();

    void on_PaymentsOutPreviewsMonth_clicked();

    void on_PaymentsOutNextYear_clicked();

    void on_PaymentsOutPreviewsYear_clicked();

    void on_PaymentsInnextMonthly_clicked();

    void on_PaymentsInPreviewsMonthly_clicked();

    void on_PaymentsInNextYearly_clicked();

    void on_PaymentsInPreviewsYearly_clicked();

    void on_OverviewRefreshButton_2_clicked();

    void on_DocumentsPlainText_textChanged();

    void on_ItemsPlainText_textChanged();

    void on_VendorsPlainText_textChanged();

    void on_PaymentsOutPlainText_textChanged();

    void on_PaymentsInPlainText_textChanged();

    void on_InvoicesPlainText_textChanged();

    void on_CustomersPlainText_textChanged();

private:
    Ui::OverviewForm *ui;
    void LoadDocumentView();
    void defualtNotesSetup();
    void LoadItemView();
    void LoadVendorView();
    void LoadPaymentsOutView();
    int paymentsoutMonthNmb = 0;
    void LoadPaymentsOutMonthly(int jump);
    void LoadPaymentsOutYearly(int jump);
    int paymentsoutYearlNmb = 0;
    void LoadCustomersView();
    void LoadInvoicesView();
    void LoadPaymentsInView();
    int paymentsInMonthNmb = 0;
    void LoadPaymentsInMonthly(int jump);
    void LoadPaymentsInYearly(int jump);
    int paymentsInYearlNmb = 0;

    void saveNotes(QString data, QString column);
};

#endif // OVERVIEWFORM_H
