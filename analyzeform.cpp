#include "analyzeform.h"
#include "ui_analyzeform.h"
#include <QGraphicsProxyWidget>
#include <QtCharts/QStackedBarSeries>>

AnalyzeForm::AnalyzeForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnalyzeForm)
{
    ui->setupUi(this);
    // Initial loading of the chart view
    loadDocumentsChartView();

    loadItemChartView();

    loadPaymentOut();

    loadPaymentIn();

    loadPaymentInOutChart();
}

AnalyzeForm::~AnalyzeForm()
{
    delete ui;
}

void AnalyzeForm::loadDocumentsChartView()
{
    // Create a new chart
    QChart *chart = new QChart();
    chart->setTitle("File Size Growth Over Time");



    // Create a line series to hold the data
    QLineSeries *series = new QLineSeries();
    loadDataDocumentsGrowth(series);

    chart->addSeries(series);

    // Create and configure the X axis (time)
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create and configure the Y axis (file size)
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("File Size (bytes)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view
    DocumentChartview = new QChartView(chart);
    DocumentChartview->setRenderHint(QPainter::Antialiasing);

    // Set size policy to expand to available space
    DocumentChartview->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add the chart view to the layout or widget
    ui->DocumentChartView->addWidget(DocumentChartview); // Assuming ui->DocumentChartLayout is your layout widget
}

void AnalyzeForm::loadDataDocumentsGrowth(QLineSeries *series)
{
    // Assuming you have a valid QSqlDatabase connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Handle database not open error
        return;
    }

    // Query to retrieve file sizes summed over time
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT strftime('%Y-%m-%d', FileDate) AS Date, SUM(FileSize) AS TotalSize
        FROM Documents
        GROUP BY Date
        ORDER BY Date
    )");

    if (!query.exec()) {
        // Handle query execution error
        return;
    }

    // Clear existing data in series
    series->clear();

    // Populate the series with data
    qint64 cumulativeSize = 0;
    while (query.next()) {
        QString dateStr = query.value(0).toString();
        qint64 totalSize = query.value(1).toLongLong();
        QDateTime date = QDateTime::fromString(dateStr, "yyyy-MM-dd");

        // Calculate cumulative size over time
        cumulativeSize += totalSize;

        series->append(date.toMSecsSinceEpoch(), cumulativeSize);
    }

    // Update total document count
    query.prepare(R"(
        SELECT COUNT(*) AS total FROM Documents
    )");
    if (!query.exec()) {
        // Handle query execution error
        return;
    }
    if (query.next()) {
        ui->DocumentsTotal->setText(QString("Total Docs: %1").arg(query.value(0).toString()));
    }
}

void AnalyzeForm::on_DocumentsRefresh_clicked()
{
    // Clear existing chart view
    delete DocumentChartview;
    // Reload chart view with updated data
    loadDocumentsChartView();
}

void AnalyzeForm::loadItemChartView()
{
    // Assuming you have a valid QSqlDatabase connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Handle database not open error
        return;
    }

    // Create a new chart
    QChart *chart = new QChart();
    chart->setTitle("Items Growth Over Time");

    // Create a line series to hold the data
    QLineSeries *series = new QLineSeries();
    loadItemData(series);

    chart->addSeries(series);

    // Create and configure the X axis (time)
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create and configure the Y axis (item count)
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Item Count");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set size policy to expand to available space
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Clear existing layout before adding new widget
    QLayoutItem *child;
    while ((child = ui->ItemChartView->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Add chart view to the layout
    ui->ItemChartView->addWidget(chartView);

    // Update total item count
    updateTotalItemCount();
}

void AnalyzeForm::loadItemData(QLineSeries *series)
{
    // Assuming you have a valid QSqlDatabase connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Handle database not open error
        return;
    }

    // Query to retrieve item count grouped by date
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT date, COUNT(*) AS ItemCount
        FROM Items
        GROUP BY date
        ORDER BY date
    )");

    if (!query.exec()) {
        // Handle query execution error
        return;
    }

    // Clear existing data in series
    series->clear();

    // Populate the series with data
    while (query.next()) {
        QString dateStr = query.value(0).toString();
        int itemCount = query.value(1).toInt();
        QDateTime date = QDateTime::fromString(dateStr, "yyyy-MM-dd");

        series->append(date.toMSecsSinceEpoch(), itemCount);
    }
}

void AnalyzeForm::updateTotalItemCount()
{
    // Assuming you have a valid QSqlDatabase connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Handle database not open error
        return;
    }

    // Query to retrieve total item count
    QSqlQuery query(db);
    query.prepare(R"(
        SELECT COUNT(*) AS TotalItems FROM Items
    )");

    if (!query.exec()) {
        // Handle query execution error
        return;
    }

    // Update UI with total item count
    if (query.next()) {
        ui->ItemTotal->setText(QString("Total Items: %1").arg(query.value(0).toInt()));
    }
}

void AnalyzeForm::on_ItemsRefresh_clicked()
{
    loadItemChartView();
}

void AnalyzeForm::loadPaymentOut(){
    // Example to create a line series
    QLineSeries *lineSeries = new QLineSeries();

    // Query to retrieve payment data
    QSqlQuery query;
    query.prepare("SELECT date, TotalAmount FROM PaymentOut ORDER BY date");
    if (query.exec()) {
        while (query.next()) {
            qreal totalAmount = query.value("TotalAmount").toReal();
            QDateTime date = QDateTime::fromString(query.value("date").toString(), "yyyy-MM-dd");
            lineSeries->append(date.toMSecsSinceEpoch(), totalAmount);
        }
    }

    QChart *lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Payment Total Amounts Over Time");
    lineChart->setAnimationOptions(QChart::SeriesAnimations);

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM yyyy");
    axisX->setTitleText("Date");
    lineChart->addAxis(axisX, Qt::AlignBottom);
    lineSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.2f");
    axisY->setTitleText("Total Amount");
    lineChart->addAxis(axisY, Qt::AlignLeft);
    lineSeries->attachAxis(axisY);

    lineChartViewPaymentOut = new QChartView(lineChart);
    lineChartViewPaymentOut->setRenderHint(QPainter::Antialiasing);
    ui->PaymentsOutChartView->addWidget(lineChartViewPaymentOut); // Adjust this to your layout
}

void AnalyzeForm::on_PaymentsOutRefresh_clicked()
{
    // Clear existing chart view
    delete lineChartViewPaymentOut;
    // Reload chart view with updated data
    loadPaymentOut();
}

void AnalyzeForm::loadPaymentIn()
{
    // Create a new chart
    QChart *chart = new QChart();
    chart->setTitle("Total Invoice Amounts Over Time");

    // Create a line series to hold the data
    QLineSeries *series = new QLineSeries();

    // Assuming you have a valid QSqlDatabase connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Handle database not open error
        return;
    }

    // Query to retrieve total invoice amounts summed by date
    QSqlQuery query;
    query.prepare(R"(
        SELECT date, SUM(total) AS TotalAmount
        FROM Invoices
        GROUP BY date
        ORDER BY date
    )");

    if (!query.exec()) {
        // Handle query execution error
        return;
    }

    // Populate the series with data
    while (query.next()) {
        QString dateStr = query.value(0).toString();
        qreal totalAmount = query.value(1).toDouble();
        QDateTime date = QDateTime::fromString(dateStr, "yyyy-MM-dd");
        series->append(date.toMSecsSinceEpoch(), totalAmount);
    }

    chart->addSeries(series);

    // Create and configure the X axis (time)
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create and configure the Y axis (total invoice amount)
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Total Invoice Amount");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create a chart view
    lineChartViewPaymentIn= new QChartView(chart);
    lineChartViewPaymentIn->setRenderHint(QPainter::Antialiasing);

    // Add the chart view to the layout
    ui->PaymentsInChartView->addWidget(lineChartViewPaymentIn); // Assuming you have a QVBoxLayout named chartLayout in your UI
}

void AnalyzeForm::loadPaymentInOutChart()
{
    // Create three line series
    QLineSeries *invoicesSeries = new QLineSeries();
    invoicesSeries->setName("payment In");

    QLineSeries *paymentOutSeries = new QLineSeries();
    paymentOutSeries->setName("Payment Out");

    QLineSeries *profitSeries = new QLineSeries();
    profitSeries->setName("Profit");

    // Assuming you have a valid QSqlDatabase connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Handle database not open error
        return;
    }

    // Query to retrieve total amounts by date for invoices
    QSqlQuery queryInvoices;
    queryInvoices.prepare(R"(
        SELECT date, SUM(total) AS totalAmount
        FROM Invoices
        GROUP BY date
        ORDER BY date
    )");

    QMap<QDateTime, qreal> invoicesData;
    if (queryInvoices.exec()) {
        while (queryInvoices.next()) {
            QDateTime date = QDateTime::fromString(queryInvoices.value("date").toString(), "yyyy-MM-dd");
            qreal totalAmount = queryInvoices.value("totalAmount").toDouble();
            invoicesSeries->append(date.toMSecsSinceEpoch(), totalAmount);
            invoicesData[date] = totalAmount;
        }
    }

    // Query to retrieve total amounts by date for payment out
    QSqlQuery queryPaymentOut;
    queryPaymentOut.prepare(R"(
        SELECT date, SUM(TotalAmount) AS totalAmount
        FROM PaymentOut
        GROUP BY date
        ORDER BY date
    )");

    QMap<QDateTime, qreal> paymentOutData;
    if (queryPaymentOut.exec()) {
        while (queryPaymentOut.next()) {
            QDateTime date = QDateTime::fromString(queryPaymentOut.value("date").toString(), "yyyy-MM-dd");
            qreal totalAmount = queryPaymentOut.value("totalAmount").toDouble();
            paymentOutSeries->append(date.toMSecsSinceEpoch(), totalAmount);
            paymentOutData[date] = totalAmount;
        }
    }

    // Calculate profit data
    for (auto it = invoicesData.begin(); it != invoicesData.end(); ++it) {
        QDateTime date = it.key();
        qreal invoicesAmount = it.value();
        qreal paymentOutAmount = paymentOutData.value(date, 0);
        qreal profit = invoicesAmount - paymentOutAmount;
        profitSeries->append(date.toMSecsSinceEpoch(), profit);
    }

    // Create the chart
    QChart *chart = new QChart();
    chart->addSeries(invoicesSeries);
    chart->addSeries(paymentOutSeries);
    chart->addSeries(profitSeries);
    chart->setTitle("Comparison of Invoices, PaymentOut, and Profit");

    // Create and configure the X axis (time)
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    invoicesSeries->attachAxis(axisX);
    paymentOutSeries->attachAxis(axisX);
    profitSeries->attachAxis(axisX);

    // Create and configure the Y axis (amount)
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%f");
    axisY->setTitleText("Total Amount");
    chart->addAxis(axisY, Qt::AlignLeft);
    invoicesSeries->attachAxis(axisY);
    paymentOutSeries->attachAxis(axisY);
    profitSeries->attachAxis(axisY);

    // Create a chart view
    lineChartViewResult = new QChartView(chart);
    lineChartViewResult->setRenderHint(QPainter::Antialiasing);

    // Set size policy to expand to available space
    lineChartViewResult->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add the chart view to the layout
    ui->ResultchartView->addWidget(lineChartViewResult); // Assuming you have a QVBoxLayout named chartLayout in your UI
}

void AnalyzeForm::on_PaymentsInNewPayed_clicked()
{
    delete lineChartViewPaymentIn;
    loadPaymentIn();
}


void AnalyzeForm::on_resultRefresh_clicked()
{
    delete lineChartViewResult;
    loadPaymentInOutChart();
}


void AnalyzeForm::on_OverviewRefreshButton_2_clicked()
{
    on_resultRefresh_clicked();
    on_PaymentsOutRefresh_clicked();
    on_ItemsRefresh_clicked();
    on_DocumentsRefresh_clicked();
    on_PaymentsInNewPayed_clicked();

}

