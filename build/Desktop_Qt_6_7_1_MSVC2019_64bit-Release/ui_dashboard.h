/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayoutMain;
    QHBoxLayout *horizontalLayout;
    QWidget *Menu;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *LogoStatus;
    QSpacerItem *verticalSpacer;
    QPushButton *Overview;
    QPushButton *Documents;
    QSpacerItem *verticalSpacer_3;
    QLabel *Section1;
    QPushButton *Items;
    QPushButton *Vendors;
    QPushButton *PaymentOut;
    QSpacerItem *verticalSpacer_4;
    QLabel *Section2;
    QPushButton *Customers;
    QPushButton *Invoices;
    QPushButton *PaymentIn;
    QSpacerItem *verticalSpacer_5;
    QFrame *line;
    QPushButton *Analys;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_6;
    QWidget *Board;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedPages;
    QWidget *OverviewPage;
    QVBoxLayout *qhboxlaoutPag0;
    QWidget *ItemsPage;
    QVBoxLayout *qhboxlaoutPag1;
    QWidget *DocumentsPage;
    QVBoxLayout *qhboxlaoutPag2;
    QWidget *VendorsPage;
    QVBoxLayout *qhboxlaoutPag3;
    QWidget *ApprovalsPage;
    QVBoxLayout *qhboxlaoutPag4;
    QWidget *BillsPage;
    QVBoxLayout *qhboxlaoutPag5;
    QWidget *PaymentsOutPage;
    QVBoxLayout *qhboxlaoutPag6;
    QWidget *CustomersPage;
    QVBoxLayout *qhboxlaoutPag7;
    QWidget *InvoicesPage;
    QVBoxLayout *qhboxlaoutPag8;
    QWidget *PaymentsInPage;
    QVBoxLayout *qhboxlaoutPag9;
    QWidget *AnalysePage;
    QVBoxLayout *qhboxlaoutPag10;
    QWidget *SettingsPage;
    QVBoxLayout *qhboxlaoutPag11;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1462, 914);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dashboard->setWindowIcon(icon);
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 47, 48)"));
        verticalLayoutMain = new QVBoxLayout(centralwidget);
        verticalLayoutMain->setSpacing(0);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        verticalLayoutMain->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        Menu = new QWidget(centralwidget);
        Menu->setObjectName("Menu");
        Menu->setMinimumSize(QSize(150, 0));
        Menu->setMaximumSize(QSize(280, 16777215));
        Menu->setStyleSheet(QString::fromUtf8("background-color:rgb(21, 47, 89)"));
        verticalLayout_2 = new QVBoxLayout(Menu);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        LogoStatus = new QLabel(Menu);
        LogoStatus->setObjectName("LogoStatus");
        LogoStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                                        "));
        LogoStatus->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(LogoStatus);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_3->addItem(verticalSpacer);

        Overview = new QPushButton(Menu);
        Overview->setObjectName("Overview");
        Overview->setCursor(QCursor(Qt::PointingHandCursor));
        Overview->setMouseTracking(true);
        Overview->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/overview.png"), QSize(), QIcon::Normal, QIcon::Off);
        Overview->setIcon(icon1);
        Overview->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Overview);

        Documents = new QPushButton(Menu);
        Documents->setObjectName("Documents");
        Documents->setCursor(QCursor(Qt::PointingHandCursor));
        Documents->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/Documents.png"), QSize(), QIcon::Normal, QIcon::Off);
        Documents->setIcon(icon2);
        Documents->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Documents);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        Section1 = new QLabel(Menu);
        Section1->setObjectName("Section1");
        Section1->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"                                                        "));

        verticalLayout_3->addWidget(Section1);

        Items = new QPushButton(Menu);
        Items->setObjectName("Items");
        Items->setCursor(QCursor(Qt::PointingHandCursor));
        Items->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/Items.png"), QSize(), QIcon::Normal, QIcon::Off);
        Items->setIcon(icon3);
        Items->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Items);

        Vendors = new QPushButton(Menu);
        Vendors->setObjectName("Vendors");
        Vendors->setCursor(QCursor(Qt::PointingHandCursor));
        Vendors->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/icons/Vendors.png"), QSize(), QIcon::Normal, QIcon::Off);
        Vendors->setIcon(icon4);
        Vendors->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Vendors);

        PaymentOut = new QPushButton(Menu);
        PaymentOut->setObjectName("PaymentOut");
        PaymentOut->setCursor(QCursor(Qt::PointingHandCursor));
        PaymentOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons/payment.png"), QSize(), QIcon::Normal, QIcon::Off);
        PaymentOut->setIcon(icon5);
        PaymentOut->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(PaymentOut);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        Section2 = new QLabel(Menu);
        Section2->setObjectName("Section2");
        Section2->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"                                                        "));

        verticalLayout_3->addWidget(Section2);

        Customers = new QPushButton(Menu);
        Customers->setObjectName("Customers");
        Customers->setCursor(QCursor(Qt::PointingHandCursor));
        Customers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        Customers->setIcon(icon4);
        Customers->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Customers);

        Invoices = new QPushButton(Menu);
        Invoices->setObjectName("Invoices");
        Invoices->setCursor(QCursor(Qt::PointingHandCursor));
        Invoices->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        Invoices->setIcon(icon2);
        Invoices->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Invoices);

        PaymentIn = new QPushButton(Menu);
        PaymentIn->setObjectName("PaymentIn");
        PaymentIn->setCursor(QCursor(Qt::PointingHandCursor));
        PaymentIn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        PaymentIn->setIcon(icon5);
        PaymentIn->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(PaymentIn);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);

        line = new QFrame(Menu);
        line->setObjectName("line");
        line->setMaximumSize(QSize(300, 16777215));
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"                                                        "));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::Shape::HLine);

        verticalLayout_3->addWidget(line);

        Analys = new QPushButton(Menu);
        Analys->setObjectName("Analys");
        Analys->setCursor(QCursor(Qt::PointingHandCursor));
        Analys->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"\n"
"    font-size: 14px; /* Text size */\n"
"    margin: 4px 2px; /* Margin around button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-left: 2px solid white; /* White left border */\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons/analyze.png"), QSize(), QIcon::Normal, QIcon::Off);
        Analys->setIcon(icon6);
        Analys->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(Analys);

        line_2 = new QFrame(Menu);
        line_2->setObjectName("line_2");
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"                                                        "));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::Shape::HLine);

        verticalLayout_3->addWidget(line_2);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);


        verticalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(Menu);

        Board = new QWidget(centralwidget);
        Board->setObjectName("Board");
        verticalLayout_5 = new QVBoxLayout(Board);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        stackedPages = new QStackedWidget(Board);
        stackedPages->setObjectName("stackedPages");
        OverviewPage = new QWidget();
        OverviewPage->setObjectName("OverviewPage");
        qhboxlaoutPag0 = new QVBoxLayout(OverviewPage);
        qhboxlaoutPag0->setSpacing(10);
        qhboxlaoutPag0->setObjectName("qhboxlaoutPag0");
        qhboxlaoutPag0->setContentsMargins(0, 0, 0, 10);
        stackedPages->addWidget(OverviewPage);
        ItemsPage = new QWidget();
        ItemsPage->setObjectName("ItemsPage");
        qhboxlaoutPag1 = new QVBoxLayout(ItemsPage);
        qhboxlaoutPag1->setSpacing(0);
        qhboxlaoutPag1->setObjectName("qhboxlaoutPag1");
        qhboxlaoutPag1->setContentsMargins(2, 2, 2, 2);
        stackedPages->addWidget(ItemsPage);
        DocumentsPage = new QWidget();
        DocumentsPage->setObjectName("DocumentsPage");
        qhboxlaoutPag2 = new QVBoxLayout(DocumentsPage);
        qhboxlaoutPag2->setSpacing(0);
        qhboxlaoutPag2->setObjectName("qhboxlaoutPag2");
        qhboxlaoutPag2->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(DocumentsPage);
        VendorsPage = new QWidget();
        VendorsPage->setObjectName("VendorsPage");
        qhboxlaoutPag3 = new QVBoxLayout(VendorsPage);
        qhboxlaoutPag3->setSpacing(0);
        qhboxlaoutPag3->setObjectName("qhboxlaoutPag3");
        qhboxlaoutPag3->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(VendorsPage);
        ApprovalsPage = new QWidget();
        ApprovalsPage->setObjectName("ApprovalsPage");
        qhboxlaoutPag4 = new QVBoxLayout(ApprovalsPage);
        qhboxlaoutPag4->setSpacing(0);
        qhboxlaoutPag4->setObjectName("qhboxlaoutPag4");
        qhboxlaoutPag4->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(ApprovalsPage);
        BillsPage = new QWidget();
        BillsPage->setObjectName("BillsPage");
        qhboxlaoutPag5 = new QVBoxLayout(BillsPage);
        qhboxlaoutPag5->setSpacing(0);
        qhboxlaoutPag5->setObjectName("qhboxlaoutPag5");
        qhboxlaoutPag5->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(BillsPage);
        PaymentsOutPage = new QWidget();
        PaymentsOutPage->setObjectName("PaymentsOutPage");
        qhboxlaoutPag6 = new QVBoxLayout(PaymentsOutPage);
        qhboxlaoutPag6->setSpacing(0);
        qhboxlaoutPag6->setObjectName("qhboxlaoutPag6");
        qhboxlaoutPag6->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(PaymentsOutPage);
        CustomersPage = new QWidget();
        CustomersPage->setObjectName("CustomersPage");
        qhboxlaoutPag7 = new QVBoxLayout(CustomersPage);
        qhboxlaoutPag7->setSpacing(0);
        qhboxlaoutPag7->setObjectName("qhboxlaoutPag7");
        qhboxlaoutPag7->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(CustomersPage);
        InvoicesPage = new QWidget();
        InvoicesPage->setObjectName("InvoicesPage");
        qhboxlaoutPag8 = new QVBoxLayout(InvoicesPage);
        qhboxlaoutPag8->setSpacing(0);
        qhboxlaoutPag8->setObjectName("qhboxlaoutPag8");
        qhboxlaoutPag8->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(InvoicesPage);
        PaymentsInPage = new QWidget();
        PaymentsInPage->setObjectName("PaymentsInPage");
        qhboxlaoutPag9 = new QVBoxLayout(PaymentsInPage);
        qhboxlaoutPag9->setSpacing(0);
        qhboxlaoutPag9->setObjectName("qhboxlaoutPag9");
        qhboxlaoutPag9->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(PaymentsInPage);
        AnalysePage = new QWidget();
        AnalysePage->setObjectName("AnalysePage");
        qhboxlaoutPag10 = new QVBoxLayout(AnalysePage);
        qhboxlaoutPag10->setSpacing(0);
        qhboxlaoutPag10->setObjectName("qhboxlaoutPag10");
        qhboxlaoutPag10->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(AnalysePage);
        SettingsPage = new QWidget();
        SettingsPage->setObjectName("SettingsPage");
        qhboxlaoutPag11 = new QVBoxLayout(SettingsPage);
        qhboxlaoutPag11->setSpacing(0);
        qhboxlaoutPag11->setObjectName("qhboxlaoutPag11");
        qhboxlaoutPag11->setContentsMargins(0, 0, 0, 0);
        stackedPages->addWidget(SettingsPage);

        verticalLayout_5->addWidget(stackedPages);


        horizontalLayout->addWidget(Board);


        verticalLayoutMain->addLayout(horizontalLayout);

        Dashboard->setCentralWidget(centralwidget);

        retranslateUi(Dashboard);

        stackedPages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        LogoStatus->setText(QCoreApplication::translate("Dashboard", "Stitch Alterations LTD", nullptr));
#if QT_CONFIG(statustip)
        Overview->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Overview->setText(QCoreApplication::translate("Dashboard", "Overview", nullptr));
#if QT_CONFIG(statustip)
        Documents->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Documents->setText(QCoreApplication::translate("Dashboard", "Documents", nullptr));
        Section1->setText(QCoreApplication::translate("Dashboard", "  PAYABLES", nullptr));
#if QT_CONFIG(statustip)
        Items->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Items->setText(QCoreApplication::translate("Dashboard", "Items", nullptr));
#if QT_CONFIG(statustip)
        Vendors->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Vendors->setText(QCoreApplication::translate("Dashboard", "Vendors", nullptr));
#if QT_CONFIG(statustip)
        PaymentOut->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        PaymentOut->setText(QCoreApplication::translate("Dashboard", "Payments out", nullptr));
        Section2->setText(QCoreApplication::translate("Dashboard", "  RECIVABLES", nullptr));
#if QT_CONFIG(statustip)
        Customers->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Customers->setText(QCoreApplication::translate("Dashboard", "Customers", nullptr));
#if QT_CONFIG(statustip)
        Invoices->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Invoices->setText(QCoreApplication::translate("Dashboard", "Invoices", nullptr));
#if QT_CONFIG(statustip)
        PaymentIn->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        PaymentIn->setText(QCoreApplication::translate("Dashboard", "Payments in", nullptr));
#if QT_CONFIG(statustip)
        Analys->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Analys->setText(QCoreApplication::translate("Dashboard", "Analyse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
