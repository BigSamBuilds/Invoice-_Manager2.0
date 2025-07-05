#ifndef CUSTOMERSFORM_H
#define CUSTOMERSFORM_H

#include <QWidget>

namespace Ui {
class CustomersForm;
}

class CustomersForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersForm(QWidget *parent = nullptr);
    ~CustomersForm();

    void setColumnsStretch();
    void resetColumnsToDefault();

private slots:
    void on_searchLineEdit_returnPressed();

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_searchButton_clicked();

    void ShowContextMenu(const QPoint &);


private:
    Ui::CustomersForm *ui;

    void setupCustomerTableView();
};

#endif // CUSTOMERSFORM_H
