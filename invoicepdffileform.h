#ifndef INVOICEPDFFILEFORM_H
#define INVOICEPDFFILEFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlRelationalTableModel>

namespace Ui {
class InvoicePDFFileForm;
}

class InvoicePDFFileForm : public QWidget
{
    Q_OBJECT

public:
    explicit InvoicePDFFileForm(int invoiceID, QWidget *parent = nullptr);
    ~InvoicePDFFileForm();

private slots:
    void on_SaveInfo_clicked();

    void on_PrintSaveButton_clicked();

    void on_SaveTheInvoice_clicked();

private:
    Ui::InvoicePDFFileForm *ui;

    int currentInvoiceID = NULL;

    QMap<QString, QString> getUserInformation();

    QMap<QString, QObject*> getUserQLineEdits();

    void defultValues();

    void loadCustomerData();

    QMap<QString, QObject*> getCustomerQLineEdits();

    void FilterCurrentInvoice(QSqlRelationalTableModel *model);

    QString formatDouble(const QString &input);

    bool insertDocument(const QString &fileName, const QString &fileData);

    bool alreadySavedOnce = false;

};

#endif // INVOICEPDFFILEFORM_H
