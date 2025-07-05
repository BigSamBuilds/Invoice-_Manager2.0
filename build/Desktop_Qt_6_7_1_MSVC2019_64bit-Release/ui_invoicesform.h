/********************************************************************************
** Form generated from reading UI file 'invoicesform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICESFORM_H
#define UI_INVOICESFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvoicesForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *InvoiceInsertNewRow;
    QPushButton *InvoiceDeleteRow;
    QPushButton *InvoiceSearchButtonCustomers;
    QLineEdit *InvoicesSearchLineEditCustomers;
    QTableView *invoiceTableView;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *InvoiceSendedProduct;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *refreshInvoiceDetails;
    QPushButton *ProductInsertNewRow;
    QPushButton *productDeleteRow;
    QPushButton *InvoicesSearchProduktItems;
    QLineEdit *InvoicesProductEditLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *InoicesCustomerIDStatus;
    QLabel *InvoicesCustomerNameStatus;
    QLabel *invoicesRecentChangesStatus;
    QTableView *InvoiceDetailsTableView;
    QHBoxLayout *bottomLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *generateInvoiceButton;

    void setupUi(QWidget *InvoicesForm)
    {
        if (InvoicesForm->objectName().isEmpty())
            InvoicesForm->setObjectName("InvoicesForm");
        InvoicesForm->resize(1122, 980);
        InvoicesForm->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d; color: white;"));
        verticalLayout = new QVBoxLayout(InvoicesForm);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        topLayout->setContentsMargins(-1, 10, -1, -1);
        titleLabel = new QLabel(InvoicesForm);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        topLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(InvoicesForm);
        pushButton->setObjectName("pushButton");
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                                color: white; /* Default text color */\n"
"                                border: 2px solid transparent; /* Default border */\n"
"                                background-color: rgba(255, 255, 255, 0.1);\n"
"                                padding: 15px 32px; /* Padding around text */\n"
"                                text-align: left; /* Center text */\n"
"                                text-decoration: none; /* Remove underline from text */\n"
"                                font-size: 14px; /* Text size */\n"
"\n"
"                            }\n"
"\n"
"                            QPushButton:hover {\n"
"                                background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"                                border-bottom: 2px solid white; /* White left border */\n"
"                            }"));

        topLayout->addWidget(pushButton);

        InvoiceInsertNewRow = new QPushButton(InvoicesForm);
        InvoiceInsertNewRow->setObjectName("InvoiceInsertNewRow");
        InvoiceInsertNewRow->setCursor(QCursor(Qt::PointingHandCursor));
        InvoiceInsertNewRow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                            color: white; /* Default text color */\n"
"                            border: 2px solid transparent; /* Default border */\n"
"                            background-color: rgba(255, 255, 255, 0.1);\n"
"                            padding: 15px 32px; /* Padding around text */\n"
"                            text-align: Center; /* Center text */\n"
"                            text-decoration: none; /* Remove underline from text */\n"
"                            font-size: 14px; /* Text size */\n"
"\n"
"                        }\n"
"\n"
"                        QPushButton:hover {\n"
"                            background-color: rgba(4, 255, 0, 30); /* White background with 50% opacity */\n"
"                            border-bottom: 2px solid rgb(12, 255, 0); /* White left border */\n"
"                        }"));

        topLayout->addWidget(InvoiceInsertNewRow);

        InvoiceDeleteRow = new QPushButton(InvoicesForm);
        InvoiceDeleteRow->setObjectName("InvoiceDeleteRow");
        InvoiceDeleteRow->setCursor(QCursor(Qt::PointingHandCursor));
        InvoiceDeleteRow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                            color: white; /* Default text color */\n"
"                            border: 2px solid transparent; /* Default border */\n"
"                            background-color: rgba(255, 255, 255, 0.1);\n"
"                            padding: 15px 32px; /* Padding around text */\n"
"                            text-align: Center; /* Center text */\n"
"                            text-decoration: none; /* Remove underline from text */\n"
"                            font-size: 14px; /* Text size */\n"
"\n"
"                        }\n"
"\n"
"                        QPushButton:hover {\n"
"                            background-color: rgba(255, 0, 0, 0.1); /* White background with 50% opacity */\n"
"                            border-bottom: 2px solid rgb(126, 0, 0); /* White left border */\n"
"                        }"));

        topLayout->addWidget(InvoiceDeleteRow);

        InvoiceSearchButtonCustomers = new QPushButton(InvoicesForm);
        InvoiceSearchButtonCustomers->setObjectName("InvoiceSearchButtonCustomers");
        InvoiceSearchButtonCustomers->setCursor(QCursor(Qt::PointingHandCursor));
        InvoiceSearchButtonCustomers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                                color: white; /* Default text color */\n"
"                                border: 2px solid transparent; /* Default border */\n"
"                                background-color: rgba(255, 255, 255, 0.1);\n"
"                                padding: 15px 32px; /* Padding around text */\n"
"                                text-align: left; /* Center text */\n"
"                                text-decoration: none; /* Remove underline from text */\n"
"                                font-size: 14px; /* Text size */\n"
"\n"
"                            }\n"
"\n"
"                            QPushButton:hover {\n"
"                                background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"                                border-bottom: 2px solid white; /* White left border */\n"
"                            }"));

        topLayout->addWidget(InvoiceSearchButtonCustomers);

        InvoicesSearchLineEditCustomers = new QLineEdit(InvoicesForm);
        InvoicesSearchLineEditCustomers->setObjectName("InvoicesSearchLineEditCustomers");
        InvoicesSearchLineEditCustomers->setMaximumSize(QSize(250, 16777215));
        InvoicesSearchLineEditCustomers->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"    border-bottom: 1px solid white;\n"
"border-right : 5px solid transparent;\n"
"    color: white;\n"
"        padding: 12px;\n"
"    background-color: transparent;\n"
"    font-size: 16px;"));

        topLayout->addWidget(InvoicesSearchLineEditCustomers);


        verticalLayout->addLayout(topLayout);

        invoiceTableView = new QTableView(InvoicesForm);
        invoiceTableView->setObjectName("invoiceTableView");
        invoiceTableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
"QTableView {\n"
"    border: 1px solid rgb(121, 121, 122);\n"
"    /* Dark border */\n"
"    background-color: #2C3E50;\n"
"    /* Dark background */\n"
"    color: #FFFFFF;\n"
"    /* White text */\n"
"    font: 12pt \"Segoe UI\";\n"
"    /* Font */\n"
"}\n"
"\n"
"/* QHeaderView::section (column headers) */\n"
"QHeaderView::section {\n"
"    background-color: rgb(66, 67, 68);\n"
"    /* Blue header background */\n"
"    color: #FFFFFF;\n"
"    /* White text */\n"
"    padding: 2px;\n"
"    border: 1px solid rgb(66, 67, 68);\n"
"    /* Blue border */\n"
"    font: bold 12pt \"Segoe UI\";\n"
"    /* Bold font */\n"
"}\n"
"\n"
"/* QTableView::item (table cells) */\n"
"QTableView::item {\n"
"    padding: 2px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* QTableView::item:selected (selected cells) */\n"
"QTableView::item:selected {\n"
"    background-color: rgb(66, 67, 68);\n"
"    /* Lighter blue for selected cells */\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"/* Alternate row colors */\n"
"QTableView:"
                        ":item:alternate {\n"
"    background-color: #34495E;\n"
"    /* Darker blue for alternate rows */\n"
"}\n"
"\n"
"\n"
"/* QTableView::item (table cells) */\n"
"QTableView::item {\n"
"    padding: 2px;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    /* Default font color (white) */\n"
"}\n"
"\n"
"\n"
"\n"
"/* QTableView::item:selected (selected cells) */\n"
"QTableView::item:selected {\n"
"    background-color: #43525c;\n"
"    /* Lighter blue for selected cells */\n"
"    color: #FFFFFF;\n"
"    /* White font color for selected cells */\n"
"}\n"
"\n"
"/* QTableView::item:focus (focused cells) */\n"
"QTableView::item:focus {\n"
"    background-color: #4b5963;\n"
"    /* Lighter blue for focused cells */\n"
"    color: #FFFFFF;\n"
"    /* White font color for focused cells */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    color: white;\n"
"}\n"
"\n"
"QScrollBar:vertical,\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background: rgba(255, 255, 255, 0);\n"
"    width: 14px;\n"
"    margin: 15px 0 15px 0;\n"
""
                        "    border-radius: 0px;\n"
"\n"
"}\n"
"\n"
"/*  HANDLE BAR VERTICAL */\n"
"QScrollBar::handle:vertical,\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: rgba(255, 255, 255, 0.472);\n"
"    min-height: 30px;\n"
"    border-radius: 7px;\n"
"\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover,\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background-color: rgba(255, 255, 255, 0.732);\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:pressed,\n"
"QScrollBar::handle:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.767);\n"
"}\n"
"\n"
"/* BTN TOP - SCROLLBAR */\n"
"QScrollBar::sub-line:vertical,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: none;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    height: 15px;\n"
"    border-top-left-radius: 7px;\n"
"    border-top-right-radius: 7px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover,\n"
"QScrollBar::sub-line:horizontal:hover {\n"
"    background-color: rg"
                        "ba(255, 255, 255, 0.458);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:pressed,\n"
"QScrollBar::sub-line:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.46);\n"
"}\n"
"\n"
"/* BTN BOTTOM - SCROLLBAR */\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::add-line:horizontal {\n"
"    border: none;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    height: 15px;\n"
"    border-bottom-left-radius: 7px;\n"
"    border-bottom-right-radius: 7px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover,\n"
"QScrollBar::add-line:horizontal:hover {\n"
"    background-color: rgba(255, 255, 255, 0.46);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:pressed,\n"
"QScrollBar::add-line:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.434);\n"
"}\n"
"\n"
"/* RESET ARROW */\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical,\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal"
                        " {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical,\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}"));
        invoiceTableView->setAlternatingRowColors(true);
        invoiceTableView->horizontalHeader()->setStretchLastSection(true);
        invoiceTableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(invoiceTableView);

        line = new QFrame(InvoicesForm);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8("background-color: white;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 15, 0, 0);
        InvoiceSendedProduct = new QLabel(InvoicesForm);
        InvoiceSendedProduct->setObjectName("InvoiceSendedProduct");
        InvoiceSendedProduct->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout->addWidget(InvoiceSendedProduct);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        refreshInvoiceDetails = new QPushButton(InvoicesForm);
        refreshInvoiceDetails->setObjectName("refreshInvoiceDetails");
        refreshInvoiceDetails->setCursor(QCursor(Qt::PointingHandCursor));
        refreshInvoiceDetails->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                                color: white; /* Default text color */\n"
"                                border: 2px solid transparent; /* Default border */\n"
"                                background-color: rgba(255, 255, 255, 0.1);\n"
"                                padding: 15px 32px; /* Padding around text */\n"
"                                text-align: left; /* Center text */\n"
"                                text-decoration: none; /* Remove underline from text */\n"
"                                font-size: 14px; /* Text size */\n"
"\n"
"                            }\n"
"\n"
"                            QPushButton:hover {\n"
"                                background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"                                border-bottom: 2px solid white; /* White left border */\n"
"                            }"));

        horizontalLayout->addWidget(refreshInvoiceDetails);

        ProductInsertNewRow = new QPushButton(InvoicesForm);
        ProductInsertNewRow->setObjectName("ProductInsertNewRow");
        ProductInsertNewRow->setCursor(QCursor(Qt::PointingHandCursor));
        ProductInsertNewRow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                            color: white; /* Default text color */\n"
"                            border: 2px solid transparent; /* Default border */\n"
"                            background-color: rgba(255, 255, 255, 0.1);\n"
"                            padding: 15px 32px; /* Padding around text */\n"
"                            text-align: Center; /* Center text */\n"
"                            text-decoration: none; /* Remove underline from text */\n"
"                            font-size: 14px; /* Text size */\n"
"\n"
"                        }\n"
"\n"
"                        QPushButton:hover {\n"
"                            background-color: rgba(4, 255, 0, 30); /* White background with 50% opacity */\n"
"                            border-bottom: 2px solid rgb(12, 255, 0); /* White left border */\n"
"                        }"));

        horizontalLayout->addWidget(ProductInsertNewRow);

        productDeleteRow = new QPushButton(InvoicesForm);
        productDeleteRow->setObjectName("productDeleteRow");
        productDeleteRow->setCursor(QCursor(Qt::PointingHandCursor));
        productDeleteRow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                            color: white; /* Default text color */\n"
"                            border: 2px solid transparent; /* Default border */\n"
"                            background-color: rgba(255, 255, 255, 0.1);\n"
"                            padding: 15px 32px; /* Padding around text */\n"
"                            text-align: Center; /* Center text */\n"
"                            text-decoration: none; /* Remove underline from text */\n"
"                            font-size: 14px; /* Text size */\n"
"\n"
"                        }\n"
"\n"
"                        QPushButton:hover {\n"
"                            background-color: rgba(255, 0, 0, 0.1); /* White background with 50% opacity */\n"
"                            border-bottom: 2px solid rgb(126, 0, 0); /* White left border */\n"
"                        }"));

        horizontalLayout->addWidget(productDeleteRow);

        InvoicesSearchProduktItems = new QPushButton(InvoicesForm);
        InvoicesSearchProduktItems->setObjectName("InvoicesSearchProduktItems");
        InvoicesSearchProduktItems->setCursor(QCursor(Qt::PointingHandCursor));
        InvoicesSearchProduktItems->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                                color: white; /* Default text color */\n"
"                                border: 2px solid transparent; /* Default border */\n"
"                                background-color: rgba(255, 255, 255, 0.1);\n"
"                                padding: 15px 32px; /* Padding around text */\n"
"                                text-align: left; /* Center text */\n"
"                                text-decoration: none; /* Remove underline from text */\n"
"                                font-size: 14px; /* Text size */\n"
"\n"
"                            }\n"
"\n"
"                            QPushButton:hover {\n"
"                                background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"                                border-bottom: 2px solid white; /* White left border */\n"
"                            }"));

        horizontalLayout->addWidget(InvoicesSearchProduktItems);

        InvoicesProductEditLine = new QLineEdit(InvoicesForm);
        InvoicesProductEditLine->setObjectName("InvoicesProductEditLine");
        InvoicesProductEditLine->setMaximumSize(QSize(250, 16777215));
        InvoicesProductEditLine->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"    border-bottom: 1px solid white;\n"
"border-right : 5px solid transparent;\n"
"    color: white;\n"
"        padding: 12px;\n"
"    background-color: transparent;\n"
"    font-size: 16px;"));

        horizontalLayout->addWidget(InvoicesProductEditLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(6, 10, 6, 0);
        InoicesCustomerIDStatus = new QLabel(InvoicesForm);
        InoicesCustomerIDStatus->setObjectName("InoicesCustomerIDStatus");
        InoicesCustomerIDStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_2->addWidget(InoicesCustomerIDStatus);

        InvoicesCustomerNameStatus = new QLabel(InvoicesForm);
        InvoicesCustomerNameStatus->setObjectName("InvoicesCustomerNameStatus");
        InvoicesCustomerNameStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_2->addWidget(InvoicesCustomerNameStatus);

        invoicesRecentChangesStatus = new QLabel(InvoicesForm);
        invoicesRecentChangesStatus->setObjectName("invoicesRecentChangesStatus");
        invoicesRecentChangesStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_2->addWidget(invoicesRecentChangesStatus);


        verticalLayout->addLayout(horizontalLayout_2);

        InvoiceDetailsTableView = new QTableView(InvoicesForm);
        InvoiceDetailsTableView->setObjectName("InvoiceDetailsTableView");
        InvoiceDetailsTableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
"QTableView {\n"
"    border: 1px solid rgb(121, 121, 122);\n"
"    /* Dark border */\n"
"    background-color: #2C3E50;\n"
"    /* Dark background */\n"
"    color: #FFFFFF;\n"
"    /* White text */\n"
"    font: 12pt \"Segoe UI\";\n"
"    /* Font */\n"
"}\n"
"\n"
"/* QHeaderView::section (column headers) */\n"
"QHeaderView::section {\n"
"    background-color: rgb(66, 67, 68);\n"
"    /* Blue header background */\n"
"    color: #FFFFFF;\n"
"    /* White text */\n"
"    padding: 2px;\n"
"    border: 1px solid rgb(66, 67, 68);\n"
"    /* Blue border */\n"
"    font: bold 12pt \"Segoe UI\";\n"
"    /* Bold font */\n"
"}\n"
"\n"
"/* QTableView::item (table cells) */\n"
"QTableView::item {\n"
"    padding: 2px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* QTableView::item:selected (selected cells) */\n"
"QTableView::item:selected {\n"
"    background-color: rgb(66, 67, 68);\n"
"    /* Lighter blue for selected cells */\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"/* Alternate row colors */\n"
"QTableView:"
                        ":item:alternate {\n"
"    background-color: #34495E;\n"
"    /* Darker blue for alternate rows */\n"
"}\n"
"\n"
"\n"
"/* QTableView::item (table cells) */\n"
"QTableView::item {\n"
"    padding: 2px;\n"
"    border: none;\n"
"    color: #FFFFFF;\n"
"    /* Default font color (white) */\n"
"}\n"
"\n"
"\n"
"\n"
"/* QTableView::item:selected (selected cells) */\n"
"QTableView::item:selected {\n"
"    background-color: #43525c;\n"
"    /* Lighter blue for selected cells */\n"
"    color: #FFFFFF;\n"
"    /* White font color for selected cells */\n"
"}\n"
"\n"
"/* QTableView::item:focus (focused cells) */\n"
"QTableView::item:focus {\n"
"    background-color: #4b5963;\n"
"    /* Lighter blue for focused cells */\n"
"    color: #FFFFFF;\n"
"    /* White font color for focused cells */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    color: white;\n"
"}\n"
"\n"
"QScrollBar:vertical,\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background: rgba(255, 255, 255, 0);\n"
"    width: 14px;\n"
"    margin: 15px 0 15px 0;\n"
""
                        "    border-radius: 0px;\n"
"\n"
"}\n"
"\n"
"/*  HANDLE BAR VERTICAL */\n"
"QScrollBar::handle:vertical,\n"
"QScrollBar::handle:horizontal {\n"
"    background-color: rgba(255, 255, 255, 0.472);\n"
"    min-height: 30px;\n"
"    border-radius: 7px;\n"
"\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover,\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background-color: rgba(255, 255, 255, 0.732);\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:pressed,\n"
"QScrollBar::handle:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.767);\n"
"}\n"
"\n"
"/* BTN TOP - SCROLLBAR */\n"
"QScrollBar::sub-line:vertical,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: none;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    height: 15px;\n"
"    border-top-left-radius: 7px;\n"
"    border-top-right-radius: 7px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover,\n"
"QScrollBar::sub-line:horizontal:hover {\n"
"    background-color: rg"
                        "ba(255, 255, 255, 0.458);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:pressed,\n"
"QScrollBar::sub-line:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.46);\n"
"}\n"
"\n"
"/* BTN BOTTOM - SCROLLBAR */\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::add-line:horizontal {\n"
"    border: none;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    height: 15px;\n"
"    border-bottom-left-radius: 7px;\n"
"    border-bottom-right-radius: 7px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover,\n"
"QScrollBar::add-line:horizontal:hover {\n"
"    background-color: rgba(255, 255, 255, 0.46);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:pressed,\n"
"QScrollBar::add-line:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.434);\n"
"}\n"
"\n"
"/* RESET ARROW */\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical,\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal"
                        " {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical,\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}"));
        InvoiceDetailsTableView->setAlternatingRowColors(true);
        InvoiceDetailsTableView->horizontalHeader()->setStretchLastSection(true);
        InvoiceDetailsTableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(InvoiceDetailsTableView);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setSpacing(0);
        bottomLayout->setObjectName("bottomLayout");
        bottomLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        bottomLayout->addItem(horizontalSpacer_3);

        generateInvoiceButton = new QPushButton(InvoicesForm);
        generateInvoiceButton->setObjectName("generateInvoiceButton");
        generateInvoiceButton->setCursor(QCursor(Qt::PointingHandCursor));
        generateInvoiceButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                                color: white; /* Default text color */\n"
"                                border: 2px solid transparent; /* Default border */\n"
"                                background-color: rgba(255, 255, 255, 0.1);\n"
"                                padding: 15px 32px; /* Padding around text */\n"
"                                text-align: left; /* Center text */\n"
"                                text-decoration: none; /* Remove underline from text */\n"
"                                font-size: 14px; /* Text size */\n"
"\n"
"                            }\n"
"\n"
"                            QPushButton:hover {\n"
"                                background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"                                border-bottom: 2px solid white; /* White left border */\n"
"                            }"));

        bottomLayout->addWidget(generateInvoiceButton);


        verticalLayout->addLayout(bottomLayout);


        retranslateUi(InvoicesForm);

        QMetaObject::connectSlotsByName(InvoicesForm);
    } // setupUi

    void retranslateUi(QWidget *InvoicesForm)
    {
        InvoicesForm->setWindowTitle(QCoreApplication::translate("InvoicesForm", "Invoices Management", nullptr));
        titleLabel->setText(QCoreApplication::translate("InvoicesForm", "Invoices", nullptr));
        pushButton->setText(QCoreApplication::translate("InvoicesForm", "Refresh", nullptr));
        InvoiceInsertNewRow->setText(QCoreApplication::translate("InvoicesForm", "Insert New Row", nullptr));
        InvoiceDeleteRow->setText(QCoreApplication::translate("InvoicesForm", "Delete Selected Row", nullptr));
        InvoiceSearchButtonCustomers->setText(QCoreApplication::translate("InvoicesForm", "Search", nullptr));
        InvoicesSearchLineEditCustomers->setPlaceholderText(QCoreApplication::translate("InvoicesForm", "Search invoice...", nullptr));
        InvoiceSendedProduct->setText(QCoreApplication::translate("InvoicesForm", "Products", nullptr));
        refreshInvoiceDetails->setText(QCoreApplication::translate("InvoicesForm", "Refresh", nullptr));
        ProductInsertNewRow->setText(QCoreApplication::translate("InvoicesForm", "Insert New Row", nullptr));
        productDeleteRow->setText(QCoreApplication::translate("InvoicesForm", "Delete Selected Row", nullptr));
        InvoicesSearchProduktItems->setText(QCoreApplication::translate("InvoicesForm", "Search", nullptr));
        InvoicesProductEditLine->setPlaceholderText(QCoreApplication::translate("InvoicesForm", "Search product...", nullptr));
        InoicesCustomerIDStatus->setText(QCoreApplication::translate("InvoicesForm", "ID:", nullptr));
        InvoicesCustomerNameStatus->setText(QCoreApplication::translate("InvoicesForm", "Name:", nullptr));
        invoicesRecentChangesStatus->setText(QCoreApplication::translate("InvoicesForm", "Date", nullptr));
        generateInvoiceButton->setText(QCoreApplication::translate("InvoicesForm", "Generate Invoice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvoicesForm: public Ui_InvoicesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICESFORM_H
