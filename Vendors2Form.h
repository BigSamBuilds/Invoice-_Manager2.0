#ifndef VENDORS2FORM_H
#define VENDORS2FORM_H

#include <QWidget>
#include <QComboBox>
#include <QTableWidget>

namespace Ui {
class PaymentOutForm;
}

class PaymentOutForm : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentOutForm(QWidget *parent = nullptr);
    ~PaymentOutForm();

    void setColumnsStretch();
    void resetColumnsToDefault();

private slots:

    void on_searchLineEdit_returnPressed();

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_searchButton_clicked();

     void ShowContextMenu(const QPoint &pos);


    void on_VendorsTableView_clicked(const QModelIndex &index);

     void on_VendorsTableView_activated(const QModelIndex &index);

 private:
    Ui::PaymentOutForm *ui;

    void setuptableView();

};

#endif // VENDORS2FORM_H
