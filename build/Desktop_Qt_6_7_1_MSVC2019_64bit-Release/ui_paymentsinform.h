/********************************************************************************
** Form generated from reading UI file 'paymentsinform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTSINFORM_H
#define UI_PAYMENTSINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_PaymentsInForm
{
public:
    QVBoxLayout *verticalLayoutMain;
    QHBoxLayout *horizontalLayoutTop;
    QLabel *paymentsLabel;
    QLabel *tableViewPageStatus;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QLabel *SelectedRow;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SetInvoiceStatus;

    void setupUi(QWidget *PaymentsInForm)
    {
        if (PaymentsInForm->objectName().isEmpty())
            PaymentsInForm->setObjectName("PaymentsInForm");
        PaymentsInForm->resize(1080, 912);
        PaymentsInForm->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d; color: white;"));
        verticalLayoutMain = new QVBoxLayout(PaymentsInForm);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        verticalLayoutMain->setContentsMargins(10, 10, 10, 10);
        horizontalLayoutTop = new QHBoxLayout();
        horizontalLayoutTop->setObjectName("horizontalLayoutTop");
        horizontalLayoutTop->setContentsMargins(0, 0, 0, 0);
        paymentsLabel = new QLabel(PaymentsInForm);
        paymentsLabel->setObjectName("paymentsLabel");
        paymentsLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;"));
        paymentsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayoutTop->addWidget(paymentsLabel);

        tableViewPageStatus = new QLabel(PaymentsInForm);
        tableViewPageStatus->setObjectName("tableViewPageStatus");
        tableViewPageStatus->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 14px;\n"
"padding-left: 5px;\n"
""));

        horizontalLayoutTop->addWidget(tableViewPageStatus);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutTop->addItem(horizontalSpacer);

        searchButton = new QPushButton(PaymentsInForm);
        searchButton->setObjectName("searchButton");
        searchButton->setCursor(QCursor(Qt::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                            color: white; /* Default text color */\n"
"                            border: 2px solid transparent; /* Default border */\n"
"                            background-color: rgba(255, 255, 255, 0.1);\n"
"                            padding: 14px 3px; /* Padding around text */\n"
"                            text-align: left; /* Center text */\n"
"                            text-decoration: none; /* Remove underline from text */\n"
"                            font-size: 14px; /* Text size */\n"
"                                                        border-radius: 20px;\n"
"                                                        font-weight: bold;\n"
"\n"
"                        }\n"
"\n"
"                        QPushButton:hover {\n"
"                            background-color: rgba(255, 255, 255, 0.3); /* White background with 50% opacity */\n"
"                            border: 2px solid white; /* White left border */\n"
"                        }"));

        horizontalLayoutTop->addWidget(searchButton);

        searchLineEdit = new QLineEdit(PaymentsInForm);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(0, 0));
        searchLineEdit->setMaximumSize(QSize(250, 16777215));
        searchLineEdit->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"    border-bottom: 1px solid white;\n"
"border-right : 5px solid transparent;\n"
"    color: white;\n"
"        padding: 12px;\n"
"    background-color: transparent;\n"
"    font-size: 16px;"));

        horizontalLayoutTop->addWidget(searchLineEdit);


        verticalLayoutMain->addLayout(horizontalLayoutTop);

        tableView = new QTableView(PaymentsInForm);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
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
        tableView->setAlternatingRowColors(true);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayoutMain->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        SelectedRow = new QLabel(PaymentsInForm);
        SelectedRow->setObjectName("SelectedRow");
        SelectedRow->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 14px;\n"
"padding-left: 5px;\n"
""));

        horizontalLayout->addWidget(SelectedRow);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        SetInvoiceStatus = new QPushButton(PaymentsInForm);
        SetInvoiceStatus->setObjectName("SetInvoiceStatus");
        SetInvoiceStatus->setCursor(QCursor(Qt::PointingHandCursor));
        SetInvoiceStatus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(SetInvoiceStatus);


        verticalLayoutMain->addLayout(horizontalLayout);


        retranslateUi(PaymentsInForm);

        QMetaObject::connectSlotsByName(PaymentsInForm);
    } // setupUi

    void retranslateUi(QWidget *PaymentsInForm)
    {
        PaymentsInForm->setWindowTitle(QCoreApplication::translate("PaymentsInForm", "Form", nullptr));
        paymentsLabel->setText(QCoreApplication::translate("PaymentsInForm", "Payments In", nullptr));
        tableViewPageStatus->setText(QCoreApplication::translate("PaymentsInForm", "Page:", nullptr));
        searchButton->setText(QCoreApplication::translate("PaymentsInForm", "Search", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("PaymentsInForm", "Enter search term...", nullptr));
        SelectedRow->setText(QCoreApplication::translate("PaymentsInForm", "Select a row to change invoice status", nullptr));
        SetInvoiceStatus->setText(QCoreApplication::translate("PaymentsInForm", "Change invoice status to", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaymentsInForm: public Ui_PaymentsInForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTSINFORM_H
