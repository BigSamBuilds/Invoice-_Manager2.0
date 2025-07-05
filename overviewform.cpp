#include "overviewform.h"
#include "ui_overviewform.h"
#include "controller/database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

OverviewForm::OverviewForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OverviewForm)
{
    ui->setupUi(this);

    defualtNotesSetup();

    LoadDocumentView();

    LoadItemView();

    LoadVendorView();

    LoadPaymentsOutView();

    LoadPaymentsOutMonthly(0);

    LoadPaymentsOutYearly(0);

    LoadCustomersView();

    LoadInvoicesView();

    LoadPaymentsInView();

    LoadPaymentsInMonthly(0);

    LoadPaymentsInYearly(0);

}

OverviewForm::~OverviewForm()
{
    delete ui;
}

void OverviewForm::defualtNotesSetup(){
    QSqlQuery query(Database::getDatabase());
    query.prepare(QString(R"(INSERT INTO OverviewNotes (id, document_note, item_note, vendors_note, payments_out_note, customers_note, invoices_note, payments_in_note)
                                        SELECT 1, '', '', '', '', '', '', ''
                                        WHERE NOT EXISTS (SELECT 1 FROM OverviewNotes WHERE id = 1);)"));
    if(!query.exec()){
        qDebug() << "default Note setup failed: " << query.lastError().text();
    }
}

void OverviewForm::LoadDocumentView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) AS total_documents FROM Documents; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve total document:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->DocumentStatusTotalDocs->setText(QString("Total Documents: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT SUM(FileSize) / (1024.0 * 1024.0) AS total_document_size_mb FROM Documents; )"));
    if(!query.exec()){
        qDebug() << "Failed to retrive total document size: " << query.lastError().text();
        return;
    }

    if(query.next()){
        // Retrieve the value from the query and convert it to a double
        double totalSizeMB = query.value(0).toDouble();

        // Format the double to a string with 5 decimal places
        QString formattedSize = QString::number(totalSizeMB, 'f', 5);

        // Set the text with the formatted string
        ui->DocumentsStatusSize->setText(QString("Total Documents Size (MB): %1").arg(formattedSize));
    }

    query.prepare(QString(R"(SELECT FileDate AS recent_document FROM Documents ORDER BY FileDate DESC LIMIT 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive recent document: " << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->DocumentsStatusLastDate->setText(QString("Recent Document Changes: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT document_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive document note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->DocumentsPlainText->setPlainText(retrieved);
        }
    }

}

void OverviewForm::LoadItemView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) AS total_items FROM Items; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve total Items:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->ItemsStatusTotalItems->setText(QString("Total Items: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT item FROM Items ORDER BY date DESC LIMIT 1 )"));
    if(!query.exec()){
        qDebug() << "Failed to retrive Recent items registerd: " << query.lastError().text();
        return;
    }

    if(query.next()){
        // Set the text with the formatted string
        ui->ItemsStatusDate->setText(QString("Recent Registered item: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT Items.item AS recent_bought_item
                                            FROM ItemBought
                                            JOIN Items ON ItemBought.item_id = Items.id
                                            ORDER BY ItemBought.date DESC
                                            LIMIT 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive recent item bought from item view: " << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->ItemsStatusLastBought->setText(QString("Recent Bought Item: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT item_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive item note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->ItemsPlainText->setPlainText(retrieved);
        }
    }
}

void OverviewForm::LoadVendorView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) AS total_vendors FROM Vendors; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve total vendors:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->vendorsTotalStatus->setText(QString("Total Vendors: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT name FROM Vendors ORDER BY RecentChange DESC LIMIT 1 )"));
    if(!query.exec()){
        qDebug() << "Failed to retrive Recent vendor registered: " << query.lastError().text();
        return;
    }

    if(query.next()){
        // Set the text with the formatted string
        ui->VendorsStatusDate->setText(QString("Recent Registered Vendor: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT Vendors.name AS recent_bought_item
                                            FROM vendors
                                            JOIN PaymentOut ON PaymentOut.vendor_id = Vendors.id
                                            ORDER BY PaymentOut.date DESC
                                            LIMIT 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive recent vendor ordered : " << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->VendorsStatusLastOrder->setText(QString("Recent Ordered Items From: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT vendors_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive item note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->VendorsPlainText->setPlainText(retrieved);
        }
    }
}

void OverviewForm::LoadPaymentsOutView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) AS total_paymentout FROM PaymentOut; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve Number of Payments out:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->PaymentsOutNumberOfPayments->setText(QString("%1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(Select count(*) as total_pending from paymentout where paid = false; )"));
    if(!query.exec()){
        qDebug() << "Failed to retrive number of payment out: " << query.lastError().text();
        return;
    }

    if(query.next()){
        // Set the text with the formatted string
        ui->PaymentsOutNumberOfPending->setText(QString("%1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(Select count(*) as total_pending from paymentout where paid = true;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrieve number of the fulfilled: " << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->PaymentsOutNumberOfFulfilled->setText(QString("%1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT payments_out_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive Payments out note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->PaymentsOutPlainText->setPlainText(retrieved);
        }
    }
}

void OverviewForm::LoadPaymentsOutMonthly(int jump){
    // Calculate the target month based on the current month and jump
    paymentsoutMonthNmb += jump;

    QDate currentDate = QDate::currentDate();

    QDate targetDate = currentDate.addMonths(paymentsoutMonthNmb);

    QString targetMonth = targetDate.toString("yyyy-MM");

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("SELECT SUM(TotalAmount) FROM PaymentOut WHERE strftime('%Y-%m', date) = ?");
    query.addBindValue(targetMonth);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "SQL error:" << query.lastError();
        return;
    }

    // Process the result
    if (query.next()) {
        double totalAmount = query.value(0).toDouble();
        ui->PaymentsOutMonthlyStatus->setText(targetDate.toString("yyyy-MMMM")+ ": " +QString::number(totalAmount, 'f', 2));
        // qDebug() << "Total amount for" << targetMonth << ":" << totalAmount;
    } else {
        qDebug() << "No data found for" << targetMonth;
    }
}

void OverviewForm::on_PaymentsOutNextMonth_clicked()
{
    LoadPaymentsOutMonthly(1);
}

void OverviewForm::on_PaymentsOutPreviewsMonth_clicked()
{
    LoadPaymentsOutMonthly(-1);
}

void OverviewForm::LoadPaymentsOutYearly(int jump){
    // Calculate the target month based on the current month and jump
    paymentsoutYearlNmb += jump;

    QDate currentDate = QDate::currentDate();

    QDate targetDate = currentDate.addYears(paymentsoutYearlNmb);

    QString targetMonth = targetDate.toString("yyyy");

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("SELECT SUM(TotalAmount) FROM PaymentOut WHERE strftime('%Y', date) = ?");
    query.addBindValue(targetMonth);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "SQL error:" << query.lastError();
        return;
    }

    // Process the result
    if (query.next()) {
        double totalAmount = query.value(0).toDouble();
        ui->PaymentsOutYearlyStatus->setText(targetDate.toString("yyyy")+ ": " +QString::number(totalAmount, 'f', 2));
        // qDebug() << "Total amount for" << targetMonth << ":" << totalAmount;
    } else {
        qDebug() << "No data found for" << targetMonth;
    }
}

void OverviewForm::on_PaymentsOutNextYear_clicked()
{
    LoadPaymentsOutYearly(1);
}

void OverviewForm::on_PaymentsOutPreviewsYear_clicked()
{
    LoadPaymentsOutYearly(-1);
}

void OverviewForm::LoadCustomersView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) AS total_customers FROM Customers; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve total Customers:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->CustomersTotalStatus->setText(QString("Total Customers: %1").arg(query.value(0).toString()));
    }


    query.prepare(QString(R"(SELECT customers_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrieve customers note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->CustomersPlainText->setPlainText(retrieved);
        }
    }
}

void OverviewForm::LoadInvoicesView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) FROM invoices; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve total invoices:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->InvoicesTotalStatus->setText(QString("Total Invocies: %1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT date  FROM invoices ORDER BY date DESC LIMIT 1; )"));
    if(!query.exec()){
        qDebug() << "Failed to retrieve recent invoice: " << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->InvoicesRecentRegister->setText(QString("Recent Invoice: %1").arg(query.value(0).toString()));
    }


    query.prepare(QString(R"(SELECT invoices_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive invoices note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->InvoicesPlainText->setPlainText(retrieved);
        }
    }
}

void OverviewForm::LoadPaymentsInView(){
    QSqlQuery query(Database::getDatabase());

    query.prepare(QString(R"(SELECT COUNT(*) AS total_paymentout FROM paymentsin; )"));

    if(!query.exec()){
        qDebug() << "Failed to retrieve Number of payments in:" << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->PaymentsInNumberOfPaysStatus->setText(QString("%1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(Select count(*) as total_pending from paymentsin where paid = false; )"));
    if(!query.exec()){
        qDebug() << "Failed to retrive number of payments in pending: " << query.lastError().text();
        return;
    }

    if(query.next()){
        // Set the text with the formatted string
        ui->PaymentsInNumberOfPendingStatus->setText(QString("%1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(Select count(*) as total_fulfilled from paymentsin where paid = true;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrieve number of payments in fulfilled: " << query.lastError().text();
        return;
    }

    if(query.next()){
        ui->PaymentsInNumberOfFulfilledStatus->setText(QString("%1").arg(query.value(0).toString()));
    }

    query.prepare(QString(R"(SELECT payments_in_note  FROM OverviewNotes where id = 1;)"));
    if(!query.exec()){
        qDebug() << "Failed to retrive Payments in note: " << query.lastError().text();
        return;
    }

    if(query.next()){
        QString retrieved = query.value(0).toString();
        if(!retrieved.isEmpty()){
            ui->PaymentsInPlainText->setPlainText(retrieved);
        }
    }
}

void OverviewForm::LoadPaymentsInMonthly(int jump){
    // Calculate the target month based on the current month and jump
    paymentsInMonthNmb += jump;

    QDate currentDate = QDate::currentDate();

    QDate targetDate = currentDate.addMonths(paymentsInMonthNmb);

    QString targetMonth = targetDate.toString("yyyy-MM");

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("SELECT SUM(total) FROM invoices WHERE strftime('%Y-%m', date) = ?");
    query.addBindValue(targetMonth);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "SQL error:" << query.lastError();
        return;
    }

    // Process the result
    if (query.next()) {
        double totalAmount = query.value(0).toDouble();
        ui->PaymentsInMonthlyStatus->setText(targetDate.toString("yyyy-MMMM")+ ": " +QString::number(totalAmount, 'f', 2));
        // qDebug() << "Total amount for" << targetMonth << ":" << totalAmount;
    } else {
        qDebug() << "No data found for" << targetMonth;
    }
}

void OverviewForm::LoadPaymentsInYearly(int jump){
    // Calculate the target month based on the current month and jump
    paymentsInYearlNmb += jump;

    QDate currentDate = QDate::currentDate();

    QDate targetDate = currentDate.addYears(paymentsInYearlNmb);

    QString targetMonth = targetDate.toString("yyyy");

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("SELECT SUM(total) FROM invoices WHERE strftime('%Y', date) = ?");
    query.addBindValue(targetMonth);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "SQL error:" << query.lastError();
        return;
    }

    // Process the result
    if (query.next()) {
        double totalAmount = query.value(0).toDouble();
        ui->PaymentsinYearlyStatus->setText(targetDate.toString("yyyy")+ ": " +QString::number(totalAmount, 'f', 2));
        // qDebug() << "Total amount for" << targetMonth << ":" << totalAmount;
    } else {
        qDebug() << "No data found for" << targetMonth;
    }
}

void OverviewForm::on_PaymentsInnextMonthly_clicked()
{
    LoadPaymentsInMonthly(1);
}


void OverviewForm::on_PaymentsInPreviewsMonthly_clicked()
{
    LoadPaymentsInMonthly(-1);
}


void OverviewForm::on_PaymentsInNextYearly_clicked()
{
    LoadPaymentsInYearly(1);
}


void OverviewForm::on_PaymentsInPreviewsYearly_clicked()
{
    LoadPaymentsInYearly(-1);
}


void OverviewForm::on_OverviewRefreshButton_2_clicked()
{
    paymentsInMonthNmb = 0;
    paymentsInYearlNmb = 0;
    paymentsoutMonthNmb = 0;
    paymentsoutYearlNmb = 0;

    defualtNotesSetup();

    LoadDocumentView();

    LoadItemView();

    LoadVendorView();

    LoadPaymentsOutView();

    LoadPaymentsOutMonthly(0);

    LoadPaymentsOutYearly(0);

    LoadCustomersView();

    LoadInvoicesView();

    LoadPaymentsInView();

    LoadPaymentsInMonthly(0);

    LoadPaymentsInYearly(0);
}


void OverviewForm::on_DocumentsPlainText_textChanged()
{
    saveNotes(ui->DocumentsPlainText->toPlainText(), "document_note");

}


void OverviewForm::on_ItemsPlainText_textChanged()
{
    saveNotes(ui->ItemsPlainText->toPlainText(), "item_note");

}


void OverviewForm::on_VendorsPlainText_textChanged()
{
    saveNotes(ui->VendorsPlainText->toPlainText(), "vendors_note");

}


void OverviewForm::on_PaymentsOutPlainText_textChanged()
{
    saveNotes(ui->PaymentsOutPlainText->toPlainText(), "payments_out_note");

}


void OverviewForm::on_PaymentsInPlainText_textChanged()
{
    saveNotes(ui->PaymentsInPlainText->toPlainText(), "payments_in_note");

}


void OverviewForm::on_InvoicesPlainText_textChanged()
{
    saveNotes(ui->InvoicesPlainText->toPlainText(), "invoices_note");

}


void OverviewForm::on_CustomersPlainText_textChanged()
{
    saveNotes(ui->CustomersPlainText->toPlainText(), "customers_note");

}

void OverviewForm::saveNotes(QString data, QString column){
    QSqlQuery query(Database::getDatabase());
    QString queryString = "UPDATE OverviewNotes SET " + column + " = :data WHERE id = 1;";
    query.prepare(queryString);
    query.bindValue(":data", data);

    if(!query.exec()){
        qDebug() << "Couldn't update column " << column << " in saveNotes: " << query.lastError().text();
    }
}
