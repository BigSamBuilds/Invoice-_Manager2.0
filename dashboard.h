#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dashboard;
}
QT_END_NAMESPACE

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_Overview_clicked();

    void on_Items_clicked();

    void on_Documents_clicked();

    void on_Vendors_clicked();

    void on_PaymentOut_clicked();

    void on_Customers_clicked();

    void on_Invoices_clicked();

    void on_PaymentIn_clicked();

    void on_Analys_clicked();

    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Dashboard *ui;

    void ChangeView(QPushButton* btn, int index);

    QPushButton* lastClicked;

    QList<QWidget*> listOfWidgets;
};
#endif // DASHBOARD_H
