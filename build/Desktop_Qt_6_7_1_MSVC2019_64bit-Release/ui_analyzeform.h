/********************************************************************************
** Form generated from reading UI file 'analyzeform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZEFORM_H
#define UI_ANALYZEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalyzeForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *OverviewsPageLabel_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *OverviewRefreshButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *qhboxlaoutPag0Status;
    QGridLayout *gridLayout;
    QWidget *PaymentInStatus;
    QVBoxLayout *verticalLayout_14;
    QPushButton *BTNPaymentsIn;
    QHBoxLayout *PaymentsInChartView;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *PaymentsInNewPayed;
    QWidget *ItemsStatus;
    QVBoxLayout *verticalLayout_6;
    QPushButton *BTNStatus;
    QHBoxLayout *ItemChartView;
    QHBoxLayout *horizontalLayout_8;
    QLabel *ItemTotal;
    QSpacerItem *horizontalSpacer;
    QPushButton *ItemsRefresh;
    QWidget *DocumentsStatus;
    QVBoxLayout *verticalLayout_7;
    QPushButton *BTNStatus_2;
    QVBoxLayout *DocumentChartView;
    QHBoxLayout *horizontalLayout_4;
    QLabel *DocumentsTotal;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *DocumentsRefresh;
    QWidget *PaymentOutStatus;
    QVBoxLayout *verticalLayout_11;
    QPushButton *BTNPaymentsOut;
    QVBoxLayout *PaymentsOutChartView;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *PaymentsOutRefresh;
    QVBoxLayout *verticalLayout_4;
    QWidget *AnalyseStatus;
    QVBoxLayout *verticalLayout_15;
    QPushButton *pushButton_2;
    QHBoxLayout *ResultchartView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *resultRefresh;

    void setupUi(QWidget *AnalyzeForm)
    {
        if (AnalyzeForm->objectName().isEmpty())
            AnalyzeForm->setObjectName("AnalyzeForm");
        AnalyzeForm->resize(1715, 1031);
        AnalyzeForm->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d; color: white;"));
        verticalLayout = new QVBoxLayout(AnalyzeForm);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        OverviewsPageLabel_2 = new QLabel(AnalyzeForm);
        OverviewsPageLabel_2->setObjectName("OverviewsPageLabel_2");
        OverviewsPageLabel_2->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_3->addWidget(OverviewsPageLabel_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        OverviewRefreshButton_2 = new QPushButton(AnalyzeForm);
        OverviewRefreshButton_2->setObjectName("OverviewRefreshButton_2");
        OverviewRefreshButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        OverviewRefreshButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    padding: 15px 32px; /* Padding around text */\n"
"    text-align: left; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"    font-size: 14px; /* Text size */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border-bottom: 2px solid white; /* White left border */\n"
"}"));

        horizontalLayout_3->addWidget(OverviewRefreshButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        scrollArea = new QScrollArea(AnalyzeForm);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:vertical, QScrollBar:horizontal {\n"
"                                                                            border: none;\n"
"                                                                            background: rgba(255, 255, 255, 0);\n"
"                                                                            width: 14px;\n"
"                                                                            margin: 15px 0 15px 0;\n"
"                                                                            border-radius: 0px;\n"
"\n"
"                                                                        }\n"
"\n"
"                                                                        /*  HANDLE BAR VERTICAL */\n"
"                                                                        QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"                                                                            background-color: rgba(255, 255, 255, 0.472);\n"
"                "
                        "                                                            min-height: 30px;\n"
"                                                                            border-radius: 7px;\n"
"\n"
"                                                                        }\n"
"\n"
"                                                                        QScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
"                                                                            background-color: rgba(255, 255, 255, 0.732);\n"
"                                                                        }\n"
"\n"
"                                                                        QScrollBar::handle:vertical:pressed, QScrollBar::handle:horizontal:pressed {\n"
"                                                                            background-color: rgba(255, 255, 255, 0.767);\n"
"                                                                        }\n"
"\n"
"                                   "
                        "                                     /* BTN TOP - SCROLLBAR */\n"
"                                                                        QScrollBar::sub-line:vertical, QScrollBar::sub-line:horizontal {\n"
"                                                                            border: none;\n"
"                                                                            background-color: rgba(255, 255, 255, 0);\n"
"                                                                            height: 15px;\n"
"                                                                            border-top-left-radius: 7px;\n"
"                                                                            border-top-right-radius: 7px;\n"
"                                                                            subcontrol-position: top;\n"
"                                                                            subcontrol-origin: margin;\n"
"                                                                        }\n"
""
                        "\n"
"                                                                        QScrollBar::sub-line:vertical:hover, QScrollBar::sub-line:horizontal:hover {\n"
"                                                                            background-color: rgba(255, 255, 255, 0.458);\n"
"                                                                        }\n"
"\n"
"                                                                        QScrollBar::sub-line:vertical:pressed, QScrollBar::sub-line:horizontal:pressed {\n"
"                                                                            background-color: rgba(255, 255, 255, 0.46);\n"
"                                                                        }\n"
"\n"
"                                                                        /* BTN BOTTOM - SCROLLBAR */\n"
"                                                                        QScrollBar::add-line:vertical, QScrollBar::add-line:horizontal {\n"
"                                               "
                        "                             border: none;\n"
"                                                                            background-color: rgba(255, 255, 255, 0);\n"
"                                                                            height: 15px;\n"
"                                                                            border-bottom-left-radius: 7px;\n"
"                                                                            border-bottom-right-radius: 7px;\n"
"                                                                            subcontrol-position: bottom;\n"
"                                                                            subcontrol-origin: margin;\n"
"                                                                        }\n"
"\n"
"                                                                        QScrollBar::add-line:vertical:hover, QScrollBar::add-line:horizontal:hover {\n"
"                                                                            backgroun"
                        "d-color: rgba(255, 255, 255, 0.46);\n"
"                                                                        }\n"
"\n"
"                                                                        QScrollBar::add-line:vertical:pressed, QScrollBar::add-line:horizontal:pressed {\n"
"                                                                            background-color: rgba(255, 255, 255, 0.434);\n"
"                                                                        }\n"
"\n"
"                                                                        /* RESET ARROW */\n"
"                                                                        QScrollBar::up-arrow:vertical,\n"
"                                                                        QScrollBar::down-arrow:vertical,\n"
"                                                                        QScrollBar::up-arrow:horizontal,\n"
"                                                                        QScrollBar::down-arrow:horizontal {\n"
"     "
                        "                                                                       background: none;\n"
"                                                                        }\n"
"\n"
"                                                                        QScrollBar::add-page:vertical,\n"
"                                                                        QScrollBar::sub-page:vertical,\n"
"                                                                        QScrollBar::add-page:horizontal,\n"
"                                                                        QScrollBar::sub-page:horizontal {\n"
"                                                                            background: none;\n"
"                                                                        }\n"
"                                                                "));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1701, 1624));
        qhboxlaoutPag0Status = new QVBoxLayout(scrollAreaWidgetContents);
        qhboxlaoutPag0Status->setSpacing(10);
        qhboxlaoutPag0Status->setObjectName("qhboxlaoutPag0Status");
        qhboxlaoutPag0Status->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(10);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        PaymentInStatus = new QWidget(scrollAreaWidgetContents);
        PaymentInStatus->setObjectName("PaymentInStatus");
        PaymentInStatus->setMinimumSize(QSize(300, 300));
        PaymentInStatus->setMaximumSize(QSize(16777215, 16777215));
        PaymentInStatus->setCursor(QCursor(Qt::PointingHandCursor));
        PaymentInStatus->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color:  rgb(108, 109, 110);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QWidget:hover {\n"
"\n"
"    background-color: rgb(89, 90, 91);\n"
"\n"
"}"));
        verticalLayout_14 = new QVBoxLayout(PaymentInStatus);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_14->setContentsMargins(10, 10, 10, 10);
        BTNPaymentsIn = new QPushButton(PaymentInStatus);
        BTNPaymentsIn->setObjectName("BTNPaymentsIn");
        BTNPaymentsIn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: transparent;\n"
"        background: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons/payment.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTNPaymentsIn->setIcon(icon);
        BTNPaymentsIn->setIconSize(QSize(20, 20));

        verticalLayout_14->addWidget(BTNPaymentsIn);

        PaymentsInChartView = new QHBoxLayout();
        PaymentsInChartView->setObjectName("PaymentsInChartView");

        verticalLayout_14->addLayout(PaymentsInChartView);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        PaymentsInNewPayed = new QPushButton(PaymentInStatus);
        PaymentsInNewPayed->setObjectName("PaymentsInNewPayed");
        PaymentsInNewPayed->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    padding: 5px 15px; /* Padding around text */\n"
"    text-align: center; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"    font-size: 14px; /* Text size */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border: 2px solid white; /* White left border */\n"
"}"));

        horizontalLayout_12->addWidget(PaymentsInNewPayed);


        verticalLayout_14->addLayout(horizontalLayout_12);


        gridLayout->addWidget(PaymentInStatus, 1, 1, 1, 1);

        ItemsStatus = new QWidget(scrollAreaWidgetContents);
        ItemsStatus->setObjectName("ItemsStatus");
        ItemsStatus->setMinimumSize(QSize(300, 300));
        ItemsStatus->setMaximumSize(QSize(16777215, 16777215));
        ItemsStatus->setCursor(QCursor(Qt::PointingHandCursor));
        ItemsStatus->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color:  rgb(108, 109, 110);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QWidget:hover {\n"
"\n"
"    background-color: rgb(89, 90, 91);\n"
"\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(ItemsStatus);
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(10, 10, 10, 2);
        BTNStatus = new QPushButton(ItemsStatus);
        BTNStatus->setObjectName("BTNStatus");
        BTNStatus->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: transparent;\n"
"        background: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/icons/Items.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTNStatus->setIcon(icon1);
        BTNStatus->setIconSize(QSize(20, 20));

        verticalLayout_6->addWidget(BTNStatus);

        ItemChartView = new QHBoxLayout();
        ItemChartView->setObjectName("ItemChartView");
        ItemChartView->setContentsMargins(10, 10, 10, 10);

        verticalLayout_6->addLayout(ItemChartView);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(3, 3, 3, 3);
        ItemTotal = new QLabel(ItemsStatus);
        ItemTotal->setObjectName("ItemTotal");
        ItemTotal->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    border: none;"));

        horizontalLayout_8->addWidget(ItemTotal);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        ItemsRefresh = new QPushButton(ItemsStatus);
        ItemsRefresh->setObjectName("ItemsRefresh");
        ItemsRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    padding: 5px 15px; /* Padding around text */\n"
"    text-align: center; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"    font-size: 14px; /* Text size */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border: 2px solid white; /* White left border */\n"
"}"));

        horizontalLayout_8->addWidget(ItemsRefresh);


        verticalLayout_6->addLayout(horizontalLayout_8);


        gridLayout->addWidget(ItemsStatus, 0, 1, 1, 1);

        DocumentsStatus = new QWidget(scrollAreaWidgetContents);
        DocumentsStatus->setObjectName("DocumentsStatus");
        DocumentsStatus->setMinimumSize(QSize(0, 500));
        DocumentsStatus->setMaximumSize(QSize(16777215, 16777215));
        DocumentsStatus->setCursor(QCursor(Qt::PointingHandCursor));
        DocumentsStatus->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color:  rgb(108, 109, 110);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QWidget:hover {\n"
"\n"
"    background-color: rgb(89, 90, 91);\n"
"\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(DocumentsStatus);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(10, 10, 10, 10);
        BTNStatus_2 = new QPushButton(DocumentsStatus);
        BTNStatus_2->setObjectName("BTNStatus_2");
        BTNStatus_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: transparent;\n"
"        background: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons/Documents.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTNStatus_2->setIcon(icon2);
        BTNStatus_2->setIconSize(QSize(20, 20));

        verticalLayout_7->addWidget(BTNStatus_2);

        DocumentChartView = new QVBoxLayout();
        DocumentChartView->setObjectName("DocumentChartView");
        DocumentChartView->setContentsMargins(0, 0, 0, 0);

        verticalLayout_7->addLayout(DocumentChartView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 3);
        DocumentsTotal = new QLabel(DocumentsStatus);
        DocumentsTotal->setObjectName("DocumentsTotal");
        DocumentsTotal->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    border: none;"));

        horizontalLayout_4->addWidget(DocumentsTotal);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        DocumentsRefresh = new QPushButton(DocumentsStatus);
        DocumentsRefresh->setObjectName("DocumentsRefresh");
        DocumentsRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    padding: 5px 15px; /* Padding around text */\n"
"    text-align: center; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"    font-size: 14px; /* Text size */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border: 2px solid white; /* White left border */\n"
"}"));

        horizontalLayout_4->addWidget(DocumentsRefresh);


        verticalLayout_7->addLayout(horizontalLayout_4);


        gridLayout->addWidget(DocumentsStatus, 0, 0, 1, 1);

        PaymentOutStatus = new QWidget(scrollAreaWidgetContents);
        PaymentOutStatus->setObjectName("PaymentOutStatus");
        PaymentOutStatus->setMinimumSize(QSize(300, 500));
        PaymentOutStatus->setMaximumSize(QSize(16777215, 16777215));
        PaymentOutStatus->setCursor(QCursor(Qt::PointingHandCursor));
        PaymentOutStatus->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color:  rgb(108, 109, 110);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QWidget:hover {\n"
"\n"
"    background-color: rgb(89, 90, 91);\n"
"\n"
"}"));
        verticalLayout_11 = new QVBoxLayout(PaymentOutStatus);
        verticalLayout_11->setSpacing(10);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(10, 10, 10, 10);
        BTNPaymentsOut = new QPushButton(PaymentOutStatus);
        BTNPaymentsOut->setObjectName("BTNPaymentsOut");
        BTNPaymentsOut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: transparent;\n"
"        background: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}"));
        BTNPaymentsOut->setIcon(icon);
        BTNPaymentsOut->setIconSize(QSize(20, 20));

        verticalLayout_11->addWidget(BTNPaymentsOut);

        PaymentsOutChartView = new QVBoxLayout();
        PaymentsOutChartView->setObjectName("PaymentsOutChartView");

        verticalLayout_11->addLayout(PaymentsOutChartView);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        PaymentsOutRefresh = new QPushButton(PaymentOutStatus);
        PaymentsOutRefresh->setObjectName("PaymentsOutRefresh");
        PaymentsOutRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    padding: 5px 15px; /* Padding around text */\n"
"    text-align: center; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"    font-size: 14px; /* Text size */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border: 2px solid white; /* White left border */\n"
"}"));

        horizontalLayout_9->addWidget(PaymentsOutRefresh);


        verticalLayout_11->addLayout(horizontalLayout_9);


        gridLayout->addWidget(PaymentOutStatus, 1, 0, 1, 1);


        qhboxlaoutPag0Status->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        AnalyseStatus = new QWidget(scrollAreaWidgetContents);
        AnalyseStatus->setObjectName("AnalyseStatus");
        AnalyseStatus->setMinimumSize(QSize(0, 600));
        AnalyseStatus->setCursor(QCursor(Qt::PointingHandCursor));
        AnalyseStatus->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color:  rgb(108, 109, 110);\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QWidget:hover {\n"
"\n"
"    background-color: rgb(140, 140, 140);\n"
"\n"
"}"));
        verticalLayout_15 = new QVBoxLayout(AnalyseStatus);
        verticalLayout_15->setObjectName("verticalLayout_15");
        pushButton_2 = new QPushButton(AnalyseStatus);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: transparent;\n"
"        background: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons/analyze.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(20, 20));

        verticalLayout_15->addWidget(pushButton_2);

        ResultchartView = new QHBoxLayout();
        ResultchartView->setObjectName("ResultchartView");
        ResultchartView->setContentsMargins(10, 10, 10, 1);

        verticalLayout_15->addLayout(ResultchartView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        resultRefresh = new QPushButton(AnalyseStatus);
        resultRefresh->setObjectName("resultRefresh");
        resultRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white; /* Default text color */\n"
"    border: 2px solid transparent; /* Default border */\n"
"    background-color: rgba(255, 255, 255, 0.1);\n"
"    padding: 5px 15px; /* Padding around text */\n"
"    text-align: center; /* Center text */\n"
"    text-decoration: none; /* Remove underline from text */\n"
"    font-size: 14px; /* Text size */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"    border: 2px solid white; /* White left border */\n"
"}"));

        horizontalLayout->addWidget(resultRefresh);


        verticalLayout_15->addLayout(horizontalLayout);


        verticalLayout_4->addWidget(AnalyseStatus);


        qhboxlaoutPag0Status->addLayout(verticalLayout_4);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(AnalyzeForm);

        QMetaObject::connectSlotsByName(AnalyzeForm);
    } // setupUi

    void retranslateUi(QWidget *AnalyzeForm)
    {
        AnalyzeForm->setWindowTitle(QCoreApplication::translate("AnalyzeForm", "Form", nullptr));
        OverviewsPageLabel_2->setText(QCoreApplication::translate("AnalyzeForm", "Analyse", nullptr));
        OverviewRefreshButton_2->setText(QCoreApplication::translate("AnalyzeForm", "Refresh All Charts", nullptr));
        BTNPaymentsIn->setText(QCoreApplication::translate("AnalyzeForm", "Payments in", nullptr));
        PaymentsInNewPayed->setText(QCoreApplication::translate("AnalyzeForm", "Refresh", nullptr));
        BTNStatus->setText(QCoreApplication::translate("AnalyzeForm", "Items", nullptr));
        ItemTotal->setText(QCoreApplication::translate("AnalyzeForm", "Total items: ", nullptr));
        ItemsRefresh->setText(QCoreApplication::translate("AnalyzeForm", "Refresh", nullptr));
        BTNStatus_2->setText(QCoreApplication::translate("AnalyzeForm", "Documents", nullptr));
        DocumentsTotal->setText(QCoreApplication::translate("AnalyzeForm", "Total Docs", nullptr));
        DocumentsRefresh->setText(QCoreApplication::translate("AnalyzeForm", "Refresh", nullptr));
        BTNPaymentsOut->setText(QCoreApplication::translate("AnalyzeForm", "Payments Out", nullptr));
        PaymentsOutRefresh->setText(QCoreApplication::translate("AnalyzeForm", "Refresh", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AnalyzeForm", "Analyses", nullptr));
        resultRefresh->setText(QCoreApplication::translate("AnalyzeForm", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnalyzeForm: public Ui_AnalyzeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZEFORM_H
