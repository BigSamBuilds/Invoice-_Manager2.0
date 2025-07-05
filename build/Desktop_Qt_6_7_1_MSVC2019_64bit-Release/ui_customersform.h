/********************************************************************************
** Form generated from reading UI file 'customersform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSFORM_H
#define UI_CUSTOMERSFORM_H

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

class Ui_CustomersForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topLayout;
    QLabel *titleLabel;
    QLabel *CustomerPageStatus;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QTableView *customerTableView;

    void setupUi(QWidget *CustomersForm)
    {
        if (CustomersForm->objectName().isEmpty())
            CustomersForm->setObjectName("CustomersForm");
        CustomersForm->resize(1123, 971);
        CustomersForm->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d; color: white;"));
        verticalLayout = new QVBoxLayout(CustomersForm);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        topLayout->setContentsMargins(-1, 10, -1, -1);
        titleLabel = new QLabel(CustomersForm);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        topLayout->addWidget(titleLabel);

        CustomerPageStatus = new QLabel(CustomersForm);
        CustomerPageStatus->setObjectName("CustomerPageStatus");
        CustomerPageStatus->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 14px;\n"
"padding-left: 5px;\n"
""));

        topLayout->addWidget(CustomerPageStatus);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topLayout->addItem(horizontalSpacer);

        searchButton = new QPushButton(CustomersForm);
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

        topLayout->addWidget(searchButton);

        searchLineEdit = new QLineEdit(CustomersForm);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMaximumSize(QSize(250, 16777215));
        searchLineEdit->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"    border-bottom: 1px solid white;\n"
"border-right : 5px solid transparent;\n"
"    color: white;\n"
"        padding: 12px;\n"
"    background-color: transparent;\n"
"    font-size: 16px;"));

        topLayout->addWidget(searchLineEdit);


        verticalLayout->addLayout(topLayout);

        customerTableView = new QTableView(CustomersForm);
        customerTableView->setObjectName("customerTableView");
        customerTableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
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
        customerTableView->setAlternatingRowColors(true);
        customerTableView->horizontalHeader()->setStretchLastSection(true);
        customerTableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(customerTableView);


        retranslateUi(CustomersForm);

        QMetaObject::connectSlotsByName(CustomersForm);
    } // setupUi

    void retranslateUi(QWidget *CustomersForm)
    {
        CustomersForm->setWindowTitle(QCoreApplication::translate("CustomersForm", "Customers Management", nullptr));
        titleLabel->setText(QCoreApplication::translate("CustomersForm", "Customers", nullptr));
        CustomerPageStatus->setText(QCoreApplication::translate("CustomersForm", "Page: ", nullptr));
        searchButton->setText(QCoreApplication::translate("CustomersForm", "Search", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("CustomersForm", "Search...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomersForm: public Ui_CustomersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSFORM_H
