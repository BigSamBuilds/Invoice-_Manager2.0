#include "dashboard.h"
#include "ui_dashboard.h"
#include "overviewform.h"
#include "itemform.h"
#include "documentsform.h"
#include "PaymentsOut.h"
#include "Vendors2Form.h"
#include "customersform.h"
#include "invoicesform.h"
#include "paymentsinform.h"
#include "analyzeform.h"

#include <QResizeEvent>
#include <QWidget>

#include "Controller/database.h"
#include "Controller/enableforgeingkeysqlite.h"
#include "Controller/tablecreator.h"
#include "Controller/functiontools.h"

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
    , lastClicked(nullptr)
{


    Database *db = new Database();
    db->initialize();
    EnableForgeingKeySQLITE::enable();

    TableCreator *creator = new TableCreator();
    if(!(
            creator->makeDocumentsTable() &&
            creator->makeItemsTable() &&
            creator->makeVendorsTable() &&
            creator->makeItemBoughtTable() &&
            creator->makePaymentoutTable() &&
            creator->makeCustomersTable() &&
            creator->makeInvoicesTable() &&
            creator->makeInvoiceDetailsTable() &&
            creator->makePaymentsInTable() &&
            creator->makeUserInformationTable() &&
            creator->makeNoteTable()

          ) ){

        FunctionTools::messageBox("Creating tables", "Error while creating table", QMessageBox::Critical);
    }

     ui->setupUi(this);

    //chnage deafult clicked button
    ChangeView(ui->Overview, 0);

    //setting up overviewpage
    OverviewForm *ovr = new OverviewForm(this);
    QVBoxLayout *qvBoxOverview = ui->qhboxlaoutPag0;
    qvBoxOverview->addWidget(ovr);

    //setting up ItemForm page
    ItemForm *its = new ItemForm(this);
    QVBoxLayout *qvBoxItem = ui->qhboxlaoutPag1;
    qvBoxItem->addWidget(its);

    //setting up DocumentsForm page
    DocumentsForm *docs = new DocumentsForm(this);
    QVBoxLayout *qvBoxDocs = ui->qhboxlaoutPag2;
    qvBoxDocs->addWidget(docs);

    //setting up VendorsForm page
    PaymentOutForm *vend = new PaymentOutForm(this);
    QVBoxLayout *qvBoxvend = ui->qhboxlaoutPag3;
    qvBoxvend->addWidget(vend);

    //setting up PaymentoutForm page
    VendorsForm *payout = new VendorsForm(this);
    QVBoxLayout *qvBoxPayOut = ui->qhboxlaoutPag6;
    qvBoxPayOut->addWidget(payout);


    //setting up CustoemrsForm page
    CustomersForm *cust = new CustomersForm(this);
    QVBoxLayout *qvBoxCusts = ui->qhboxlaoutPag7;
    qvBoxCusts->addWidget(cust);

    //setting up CustoemrsForm page
    InvoicesForm *invoices = new InvoicesForm(this);
    QVBoxLayout *qvBoxInvoice = ui->qhboxlaoutPag8;
    qvBoxInvoice->addWidget(invoices);

    //setting up paymentsinform page
    PaymentsInForm *payin = new PaymentsInForm(this);
    QVBoxLayout *qvBoxpayin = ui->qhboxlaoutPag9;
    qvBoxpayin->addWidget(payin);

    //setting up paymentsinform page
    AnalyzeForm *analyse = new AnalyzeForm(this);
    QVBoxLayout *ana = ui->qhboxlaoutPag10;
    ana->addWidget(analyse);

    listOfWidgets.append(its);
    listOfWidgets.append(docs);
    listOfWidgets.append(vend);
    listOfWidgets.append(payout);
    listOfWidgets.append(cust);
    listOfWidgets.append(invoices);
    listOfWidgets.append(payin);



}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::ChangeView(QPushButton* btn, int index) {
    if (btn) {
        if (lastClicked != nullptr) {
            lastClicked->setStyleSheet("QPushButton {"
                                       "color: white;" /* Default text color */
                                       "border: 2px solid transparent;" /* Default border */
                                       "padding: 15px 32px;" /* Padding around text */
                                       "text-align: left;" /* Left align text */
                                       "text-decoration: none;" /* Remove underline from text */
                                       "font-size: 14px;" /* Text size */
                                       "margin: 4px 2px;" /* Margin around button */
                                       "}"
                                       "QPushButton:hover {"
                                       "background-color: rgba(255, 255, 255, 0.3);" /* White background with 50% opacity */
                                       "border-left: 2px solid white;" /* White left border */
                                       "}");
        }

        lastClicked = btn;

        lastClicked->setStyleSheet("QPushButton {"
                                   "background-color: rgba(255, 255, 255, 0.3);" /* White background with 50% opacity */
                                   "color: white;" /* Default text color */
                                   "border: 2px solid transparent;" /* Default border */
                                   "border-left: 2px solid white;" /* White left border */
                                   "padding: 15px 32px;" /* Padding around text */
                                   "text-align: left;" /* Left align text */
                                   "text-decoration: none;" /* Remove underline from text */
                                   "font-size: 14px;" /* Text size */
                                   "margin: 4px 2px;" /* Margin around button */
                                   "}");

        // Ensure ui->stackedPages is not null and the index is within range
        if (ui->stackedPages && index >= 0 && index < ui->stackedPages->count()) {
            ui->stackedPages->setCurrentIndex(index);
        } else {
            qWarning("Invalid index or ui->stackedPages is null");
        }

        // Add your logic to change the view here
    }
}

void Dashboard::on_Overview_clicked()
{
    ChangeView(ui->Overview, 0);
}

void Dashboard::on_Items_clicked()
{
    ChangeView(ui->Items, 1);
}

void Dashboard::on_Documents_clicked()
{
    ChangeView(ui->Documents, 2);
}

void Dashboard::on_Vendors_clicked()
{
    ChangeView(ui->Vendors, 3);
}

void Dashboard::on_PaymentOut_clicked()
{
    ChangeView(ui->PaymentOut, 6);
}

void Dashboard::on_Customers_clicked()
{
    ChangeView(ui->Customers, 7);
}

void Dashboard::on_Invoices_clicked()
{
    ChangeView(ui->Invoices, 8);
}

void Dashboard::on_PaymentIn_clicked()
{
    ChangeView(ui->PaymentIn, 9);
}

void Dashboard::on_Analys_clicked()
{
    ChangeView(ui->Analys, 10);
}


void Dashboard::resizeEvent(QResizeEvent *event) {
    // QSize newSize = event->size();
    // ui->LogoStatus->setText(QString("New size: %1 x %2").arg(newSize.width()).arg(newSize.height()));


    for (QWidget *widget : listOfWidgets) {
        if (ItemForm *itemForm = dynamic_cast<ItemForm*>(widget)) {
            itemForm->setColumnsStretch();
        } else if (DocumentsForm *docsForm = dynamic_cast<DocumentsForm*>(widget)) {
            docsForm->setColumnsStretch();
        } else if (VendorsForm *vendForm = dynamic_cast<VendorsForm*>(widget)) {
            vendForm->setColumnsStretch();
        } else if (PaymentOutForm *payout = dynamic_cast<PaymentOutForm*>(widget)){
            payout->setColumnsStretch();
        } else if (CustomersForm *payout1 = dynamic_cast<CustomersForm*>(widget)){
            payout1->setColumnsStretch();
        } else if (InvoicesForm *payout2 = dynamic_cast<InvoicesForm*>(widget)){
            payout2->setColumnsStretch();
        } else if (PaymentsInForm *payout3 = dynamic_cast<PaymentsInForm*>(widget)){
            payout3->setColumnsStretch();
        }

    }


    // Call the base class implementation
    QWidget::resizeEvent(event);
}
