#ifndef ANALYZEFORM_H
#define ANALYZEFORM_H

#include "Controller/database.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QGraphicsView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>
#include <QDateTime>
#include <QWidget>
#include <QGraphicsItem>

namespace Ui {
class AnalyzeForm;
}

class AnalyzeForm : public QWidget
{
    Q_OBJECT

public:
    explicit AnalyzeForm(QWidget *parent = nullptr);
    ~AnalyzeForm();

private slots:

    void on_DocumentsRefresh_clicked();

    void on_ItemsRefresh_clicked();

    void on_PaymentsOutRefresh_clicked();

    void on_PaymentsInNewPayed_clicked();

    void on_resultRefresh_clicked();

    void on_OverviewRefreshButton_2_clicked();

private:
    Ui::AnalyzeForm *ui;
    void loadDataDocumentsGrowth(QLineSeries *series);
    void loadDocumentsChartView();
    void loadItemChartView();
    void loadItemData(QLineSeries *series);
    void updateTotalItemCount();
    void loadPaymentOut();
    void loadPaymentIn();
    void loadPaymentInOutChart();

    QChartView *DocumentChartview;

    QChartView *lineChartViewPaymentOut;

    QChartView *lineChartViewPaymentIn;

    QChartView *lineChartViewResult;


};

#endif // ANALYZEFORM_H
