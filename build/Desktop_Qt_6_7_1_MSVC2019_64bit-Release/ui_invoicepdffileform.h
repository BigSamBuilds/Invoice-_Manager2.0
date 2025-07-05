/********************************************************************************
** Form generated from reading UI file 'invoicepdffileform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICEPDFFILEFORM_H
#define UI_INVOICEPDFFILEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvoicePDFFileForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *headerLayout;
    QLabel *companyNameLabel;
    QHBoxLayout *topDetailsLayout;
    QVBoxLayout *leftDetailsLayout;
    QLineEdit *addressLineEdit;
    QLineEdit *postnumberLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *vat_numberQlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *mobileQLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *phone_QLineEdit;
    QLineEdit *email_QLineEdit;
    QLineEdit *website_QLineEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *rightDetailsLayout;
    QHBoxLayout *dateLayout;
    QLabel *dateLabel;
    QLineEdit *dateLineEdit;
    QHBoxLayout *invoiceNumberLayout;
    QLabel *invoiceNumberLabel;
    QLineEdit *invoiceNumberLineEdit;
    QHBoxLayout *billToLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *billToLabel;
    QTextEdit *billToTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QTableView *tableView;
    QHBoxLayout *bottomDetailsLayout;
    QVBoxLayout *leftBottomLayout;
    QHBoxLayout *accountLayout;
    QLabel *accountLabel;
    QLineEdit *accountLineEdit;
    QSpacerItem *verticalSpacerLeft1;
    QHBoxLayout *sortCodeLayout;
    QLabel *sortCodeLabel;
    QLineEdit *sortCodeLineEdit;
    QHBoxLayout *bankLayout;
    QLabel *bankLabel;
    QLineEdit *bankLineEdit;
    QTextEdit *bankAddressTextEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *rightBottomLayout;
    QHBoxLayout *subtotalLayout;
    QLabel *subtotalLabel;
    QLineEdit *subtotalLineEdit;
    QHBoxLayout *vatLayoutBottom;
    QLabel *vatBottomLabel;
    QLineEdit *vatPercentLineEdit;
    QLabel *percentLabel;
    QLineEdit *vatAmountLineEdit;
    QHBoxLayout *discountLayout;
    QLabel *discountLabel;
    QLineEdit *discountLineEdit;
    QHBoxLayout *totalDiscountLayout;
    QLabel *totalDiscountLabel;
    QLineEdit *totalDiscountLineEdit;
    QSpacerItem *verticalSpacerRight1;
    QHBoxLayout *totalLayout;
    QLabel *totalLabel;
    QLineEdit *totalLineEdit;
    QHBoxLayout *balanceDueLayout;
    QLabel *balanceDueLabel;
    QLineEdit *balanceDueLineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *SaveInfo;
    QPushButton *PrintSaveButton;
    QPushButton *SaveTheInvoice;

    void setupUi(QWidget *InvoicePDFFileForm)
    {
        if (InvoicePDFFileForm->objectName().isEmpty())
            InvoicePDFFileForm->setObjectName("InvoicePDFFileForm");
        InvoicePDFFileForm->resize(867, 1092);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        InvoicePDFFileForm->setWindowIcon(icon);
        InvoicePDFFileForm->setStyleSheet(QString::fromUtf8("background: white;"));
        verticalLayout = new QVBoxLayout(InvoicePDFFileForm);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        headerLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        companyNameLabel = new QLabel(InvoicePDFFileForm);
        companyNameLabel->setObjectName("companyNameLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Alegreya SC")});
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(false);
        companyNameLabel->setFont(font);
        companyNameLabel->setStyleSheet(QString::fromUtf8("color: blue;\n"
"font: 28pt \"Alegreya SC\";\n"
"font-weight: bold;"));

        headerLayout->addWidget(companyNameLabel);


        verticalLayout->addLayout(headerLayout);

        topDetailsLayout = new QHBoxLayout();
        topDetailsLayout->setObjectName("topDetailsLayout");
        topDetailsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        leftDetailsLayout = new QVBoxLayout();
        leftDetailsLayout->setSpacing(6);
        leftDetailsLayout->setObjectName("leftDetailsLayout");
        addressLineEdit = new QLineEdit(InvoicePDFFileForm);
        addressLineEdit->setObjectName("addressLineEdit");
        addressLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        leftDetailsLayout->addWidget(addressLineEdit);

        postnumberLineEdit = new QLineEdit(InvoicePDFFileForm);
        postnumberLineEdit->setObjectName("postnumberLineEdit");
        postnumberLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        leftDetailsLayout->addWidget(postnumberLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(InvoicePDFFileForm);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout_2->addWidget(label);

        vat_numberQlineEdit = new QLineEdit(InvoicePDFFileForm);
        vat_numberQlineEdit->setObjectName("vat_numberQlineEdit");
        vat_numberQlineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout_2->addWidget(vat_numberQlineEdit);


        leftDetailsLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(InvoicePDFFileForm);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout_3->addWidget(label_2);

        mobileQLineEdit = new QLineEdit(InvoicePDFFileForm);
        mobileQLineEdit->setObjectName("mobileQLineEdit");
        mobileQLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout_3->addWidget(mobileQLineEdit);


        leftDetailsLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(InvoicePDFFileForm);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(label_3);

        phone_QLineEdit = new QLineEdit(InvoicePDFFileForm);
        phone_QLineEdit->setObjectName("phone_QLineEdit");
        phone_QLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout_4->addWidget(phone_QLineEdit);


        leftDetailsLayout->addLayout(horizontalLayout_4);

        email_QLineEdit = new QLineEdit(InvoicePDFFileForm);
        email_QLineEdit->setObjectName("email_QLineEdit");
        email_QLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        leftDetailsLayout->addWidget(email_QLineEdit);

        website_QLineEdit = new QLineEdit(InvoicePDFFileForm);
        website_QLineEdit->setObjectName("website_QLineEdit");
        website_QLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        leftDetailsLayout->addWidget(website_QLineEdit);


        topDetailsLayout->addLayout(leftDetailsLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topDetailsLayout->addItem(horizontalSpacer);

        rightDetailsLayout = new QVBoxLayout();
        rightDetailsLayout->setObjectName("rightDetailsLayout");
        dateLayout = new QHBoxLayout();
        dateLayout->setObjectName("dateLayout");
        dateLabel = new QLabel(InvoicePDFFileForm);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        dateLayout->addWidget(dateLabel);

        dateLineEdit = new QLineEdit(InvoicePDFFileForm);
        dateLineEdit->setObjectName("dateLineEdit");
        dateLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        dateLayout->addWidget(dateLineEdit);


        rightDetailsLayout->addLayout(dateLayout);

        invoiceNumberLayout = new QHBoxLayout();
        invoiceNumberLayout->setObjectName("invoiceNumberLayout");
        invoiceNumberLabel = new QLabel(InvoicePDFFileForm);
        invoiceNumberLabel->setObjectName("invoiceNumberLabel");
        invoiceNumberLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        invoiceNumberLayout->addWidget(invoiceNumberLabel);

        invoiceNumberLineEdit = new QLineEdit(InvoicePDFFileForm);
        invoiceNumberLineEdit->setObjectName("invoiceNumberLineEdit");
        invoiceNumberLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        invoiceNumberLayout->addWidget(invoiceNumberLineEdit);


        rightDetailsLayout->addLayout(invoiceNumberLayout);

        billToLayout = new QHBoxLayout();
        billToLayout->setSpacing(0);
        billToLayout->setObjectName("billToLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        billToLabel = new QLabel(InvoicePDFFileForm);
        billToLabel->setObjectName("billToLabel");
        billToLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(billToLabel);

        billToTextEdit = new QTextEdit(InvoicePDFFileForm);
        billToTextEdit->setObjectName("billToTextEdit");
        billToTextEdit->setMaximumSize(QSize(16777215, 120));
        billToTextEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(billToTextEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        billToLayout->addLayout(verticalLayout_2);


        rightDetailsLayout->addLayout(billToLayout);


        topDetailsLayout->addLayout(rightDetailsLayout);


        verticalLayout->addLayout(topDetailsLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(InvoicePDFFileForm);
        tableView->setObjectName("tableView");
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
"QTableView {\n"
"    border: 1px solid rgb(121, 121, 122); /* Dark border */\n"
"    background-color: rgb(255, 255, 255); /* White background */\n"
"    color: black; /* Black text */\n"
"    font: 12pt \"Segoe UI\"; /* Font */\n"
"}\n"
"\n"
"/* QHeaderView::section (column headers) */\n"
"QHeaderView::section {\n"
"    background-color: rgb(52, 73, 94); /* Blue header background */\n"
"    color: #FFFFFF; /* White text */\n"
"    padding: 2px;\n"
"    border: 1px solid rgb(66, 67, 68); /* Blue border */\n"
"    font: bold 12pt \"Segoe UI\"; /* Bold font */\n"
"}\n"
"\n"
"/* QTableView::item (table cells) */\n"
"QTableView::item {\n"
"    padding: 2px;\n"
"    border: none;\n"
"    color: black; /* Black font color */\n"
"}\n"
"\n"
"/* QTableView::item:selected (selected cells) */\n"
"QTableView::item:selected {\n"
"    background-color: rgb(192, 192, 192); /* Light gray for selected cells */\n"
"    color: black; /* Black font color for selected cells */\n"
"}\n"
"\n"
"/* Alternate row c"
                        "olors */\n"
"QTableView::item:alternate {\n"
"    background-color: rgb(226, 226, 226); /* Light gray for alternate rows */\n"
"}\n"
"\n"
"/* QTableView::item:focus (focused cells) */\n"
"QTableView::item:focus {\n"
"    background-color: rgb(192, 192, 192); /* Light gray for focused cells */\n"
"    color: black; /* Black font color for focused cells */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    color: black; /* Black text in QLineEdit */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    border: none;\n"
"    background: rgba(255, 255, 255, 0);\n"
"    width: 14px;\n"
"    margin: 15px 0 15px 0;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"/* HANDLE BAR VERTICAL */\n"
"QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"    background-color: gray; /* Gray handle bar */\n"
"    min-height: 30px;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover, QScrollBar::handle:horizontal:hover {\n"
"    background-color: darkgray; /* Darker gray on hover */\n"
"}\n"
"\n"
"QSc"
                        "rollBar::handle:vertical:pressed, QScrollBar::handle:horizontal:pressed {\n"
"    background-color: darkgray; /* Darker gray on press */\n"
"}\n"
"\n"
"/* BTN TOP - SCROLLBAR */\n"
"QScrollBar::sub-line:vertical, QScrollBar::sub-line:horizontal {\n"
"    border: none;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    height: 15px;\n"
"    border-top-left-radius: 7px;\n"
"    border-top-right-radius: 7px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover, QScrollBar::sub-line:horizontal:hover {\n"
"    background-color: rgba(255, 255, 255, 0.458);\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:pressed, QScrollBar::sub-line:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.46);\n"
"}\n"
"\n"
"/* BTN BOTTOM - SCROLLBAR */\n"
"QScrollBar::add-line:vertical, QScrollBar::add-line:horizontal {\n"
"    border: none;\n"
"    background-color: rgba(255, 255, 255, 0);\n"
"    height: 15px;\n"
"    border-bottom-left-radius: 7px"
                        ";\n"
"    border-bottom-right-radius: 7px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover, QScrollBar::add-line:horizontal:hover {\n"
"    background-color: rgba(255, 255, 255, 0.46);\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:pressed, QScrollBar::add-line:horizontal:pressed {\n"
"    background-color: rgba(255, 255, 255, 0.434);\n"
"}\n"
"\n"
"/* RESET ARROW */\n"
"QScrollBar::up-arrow:vertical,\n"
"QScrollBar::down-arrow:vertical,\n"
"QScrollBar::up-arrow:horizontal,\n"
"QScrollBar::down-arrow:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical,\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
""));
        tableView->setFrameShape(QFrame::NoFrame);
        tableView->setAlternatingRowColors(true);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        horizontalLayout_5->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout_5);

        bottomDetailsLayout = new QHBoxLayout();
        bottomDetailsLayout->setObjectName("bottomDetailsLayout");
        bottomDetailsLayout->setSizeConstraint(QLayout::SetFixedSize);
        leftBottomLayout = new QVBoxLayout();
        leftBottomLayout->setObjectName("leftBottomLayout");
        accountLayout = new QHBoxLayout();
        accountLayout->setObjectName("accountLayout");
        accountLabel = new QLabel(InvoicePDFFileForm);
        accountLabel->setObjectName("accountLabel");
        accountLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        accountLayout->addWidget(accountLabel);

        accountLineEdit = new QLineEdit(InvoicePDFFileForm);
        accountLineEdit->setObjectName("accountLineEdit");
        accountLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        accountLayout->addWidget(accountLineEdit);


        leftBottomLayout->addLayout(accountLayout);

        verticalSpacerLeft1 = new QSpacerItem(0, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        leftBottomLayout->addItem(verticalSpacerLeft1);

        sortCodeLayout = new QHBoxLayout();
        sortCodeLayout->setObjectName("sortCodeLayout");
        sortCodeLabel = new QLabel(InvoicePDFFileForm);
        sortCodeLabel->setObjectName("sortCodeLabel");
        sortCodeLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        sortCodeLayout->addWidget(sortCodeLabel);

        sortCodeLineEdit = new QLineEdit(InvoicePDFFileForm);
        sortCodeLineEdit->setObjectName("sortCodeLineEdit");
        sortCodeLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        sortCodeLayout->addWidget(sortCodeLineEdit);


        leftBottomLayout->addLayout(sortCodeLayout);

        bankLayout = new QHBoxLayout();
        bankLayout->setObjectName("bankLayout");
        bankLabel = new QLabel(InvoicePDFFileForm);
        bankLabel->setObjectName("bankLabel");
        bankLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        bankLayout->addWidget(bankLabel);

        bankLineEdit = new QLineEdit(InvoicePDFFileForm);
        bankLineEdit->setObjectName("bankLineEdit");
        bankLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        bankLayout->addWidget(bankLineEdit);


        leftBottomLayout->addLayout(bankLayout);

        bankAddressTextEdit = new QTextEdit(InvoicePDFFileForm);
        bankAddressTextEdit->setObjectName("bankAddressTextEdit");
        bankAddressTextEdit->setMaximumSize(QSize(16777215, 60));
        bankAddressTextEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        leftBottomLayout->addWidget(bankAddressTextEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftBottomLayout->addItem(verticalSpacer);


        bottomDetailsLayout->addLayout(leftBottomLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        bottomDetailsLayout->addItem(horizontalSpacer_2);

        rightBottomLayout = new QVBoxLayout();
        rightBottomLayout->setObjectName("rightBottomLayout");
        rightBottomLayout->setContentsMargins(0, -1, -1, 0);
        subtotalLayout = new QHBoxLayout();
        subtotalLayout->setObjectName("subtotalLayout");
        subtotalLabel = new QLabel(InvoicePDFFileForm);
        subtotalLabel->setObjectName("subtotalLabel");
        subtotalLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        subtotalLayout->addWidget(subtotalLabel);

        subtotalLineEdit = new QLineEdit(InvoicePDFFileForm);
        subtotalLineEdit->setObjectName("subtotalLineEdit");
        subtotalLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        subtotalLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        subtotalLayout->addWidget(subtotalLineEdit);


        rightBottomLayout->addLayout(subtotalLayout);

        vatLayoutBottom = new QHBoxLayout();
        vatLayoutBottom->setSpacing(0);
        vatLayoutBottom->setObjectName("vatLayoutBottom");
        vatBottomLabel = new QLabel(InvoicePDFFileForm);
        vatBottomLabel->setObjectName("vatBottomLabel");
        vatBottomLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        vatLayoutBottom->addWidget(vatBottomLabel);

        vatPercentLineEdit = new QLineEdit(InvoicePDFFileForm);
        vatPercentLineEdit->setObjectName("vatPercentLineEdit");
        vatPercentLineEdit->setMaximumSize(QSize(50, 16777215));
        vatPercentLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        vatPercentLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        vatLayoutBottom->addWidget(vatPercentLineEdit);

        percentLabel = new QLabel(InvoicePDFFileForm);
        percentLabel->setObjectName("percentLabel");
        percentLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        vatLayoutBottom->addWidget(percentLabel);

        vatAmountLineEdit = new QLineEdit(InvoicePDFFileForm);
        vatAmountLineEdit->setObjectName("vatAmountLineEdit");
        vatAmountLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        vatAmountLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        vatLayoutBottom->addWidget(vatAmountLineEdit);


        rightBottomLayout->addLayout(vatLayoutBottom);

        discountLayout = new QHBoxLayout();
        discountLayout->setObjectName("discountLayout");
        discountLabel = new QLabel(InvoicePDFFileForm);
        discountLabel->setObjectName("discountLabel");
        discountLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        discountLayout->addWidget(discountLabel);

        discountLineEdit = new QLineEdit(InvoicePDFFileForm);
        discountLineEdit->setObjectName("discountLineEdit");
        discountLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        discountLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        discountLayout->addWidget(discountLineEdit);


        rightBottomLayout->addLayout(discountLayout);

        totalDiscountLayout = new QHBoxLayout();
        totalDiscountLayout->setObjectName("totalDiscountLayout");
        totalDiscountLabel = new QLabel(InvoicePDFFileForm);
        totalDiscountLabel->setObjectName("totalDiscountLabel");
        totalDiscountLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        totalDiscountLayout->addWidget(totalDiscountLabel);

        totalDiscountLineEdit = new QLineEdit(InvoicePDFFileForm);
        totalDiscountLineEdit->setObjectName("totalDiscountLineEdit");
        totalDiscountLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        totalDiscountLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        totalDiscountLayout->addWidget(totalDiscountLineEdit);


        rightBottomLayout->addLayout(totalDiscountLayout);

        verticalSpacerRight1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightBottomLayout->addItem(verticalSpacerRight1);

        totalLayout = new QHBoxLayout();
        totalLayout->setObjectName("totalLayout");
        totalLabel = new QLabel(InvoicePDFFileForm);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        totalLayout->addWidget(totalLabel);

        totalLineEdit = new QLineEdit(InvoicePDFFileForm);
        totalLineEdit->setObjectName("totalLineEdit");
        totalLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        totalLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        totalLayout->addWidget(totalLineEdit);


        rightBottomLayout->addLayout(totalLayout);

        balanceDueLayout = new QHBoxLayout();
        balanceDueLayout->setObjectName("balanceDueLayout");
        balanceDueLabel = new QLabel(InvoicePDFFileForm);
        balanceDueLabel->setObjectName("balanceDueLabel");
        balanceDueLabel->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));

        balanceDueLayout->addWidget(balanceDueLabel);

        balanceDueLineEdit = new QLineEdit(InvoicePDFFileForm);
        balanceDueLineEdit->setObjectName("balanceDueLineEdit");
        balanceDueLineEdit->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: transparent;\n"
"border: none;\n"
"font-weight: bold;"));
        balanceDueLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        balanceDueLayout->addWidget(balanceDueLineEdit);


        rightBottomLayout->addLayout(balanceDueLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightBottomLayout->addItem(verticalSpacer_2);


        bottomDetailsLayout->addLayout(rightBottomLayout);


        verticalLayout->addLayout(bottomDetailsLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(10, 10, 10, 10);
        SaveInfo = new QPushButton(InvoicePDFFileForm);
        SaveInfo->setObjectName("SaveInfo");
        SaveInfo->setCursor(QCursor(Qt::PointingHandCursor));
        SaveInfo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(67, 67, 67);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: white;\n"
"}"));

        horizontalLayout_6->addWidget(SaveInfo);

        PrintSaveButton = new QPushButton(InvoicePDFFileForm);
        PrintSaveButton->setObjectName("PrintSaveButton");
        PrintSaveButton->setCursor(QCursor(Qt::PointingHandCursor));
        PrintSaveButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(67, 67, 67);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: white;\n"
"}"));

        horizontalLayout_6->addWidget(PrintSaveButton);

        SaveTheInvoice = new QPushButton(InvoicePDFFileForm);
        SaveTheInvoice->setObjectName("SaveTheInvoice");
        SaveTheInvoice->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(67, 67, 67);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: white;\n"
"}"));

        horizontalLayout_6->addWidget(SaveTheInvoice);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(InvoicePDFFileForm);

        QMetaObject::connectSlotsByName(InvoicePDFFileForm);
    } // setupUi

    void retranslateUi(QWidget *InvoicePDFFileForm)
    {
        InvoicePDFFileForm->setWindowTitle(QCoreApplication::translate("InvoicePDFFileForm", "Invoices Management", nullptr));
        companyNameLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Stitch Alterations LTD", nullptr));
        addressLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "Address", nullptr));
        postnumberLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "Post Number", nullptr));
        label->setText(QCoreApplication::translate("InvoicePDFFileForm", "VAT Number:", nullptr));
        vat_numberQlineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "VAT 1234...", nullptr));
        label_2->setText(QCoreApplication::translate("InvoicePDFFileForm", "Mobile:", nullptr));
        mobileQLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "0123241...", nullptr));
        label_3->setText(QCoreApplication::translate("InvoicePDFFileForm", "Phone:", nullptr));
        phone_QLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "076564...", nullptr));
        email_QLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "Email@example.com", nullptr));
        website_QLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "www.example.com", nullptr));
        dateLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Date:", nullptr));
        dateLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "24/2/2", nullptr));
        invoiceNumberLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Invoice Number:", nullptr));
        invoiceNumberLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "S123...", nullptr));
        billToLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Bill To:", nullptr));
        billToTextEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "Jon Doe", nullptr));
        accountLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Account:", nullptr));
        accountLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "1234..", nullptr));
        sortCodeLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Sort Code:", nullptr));
        sortCodeLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "123456..", nullptr));
        bankLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Bank:", nullptr));
        bankLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "123456..", nullptr));
        bankAddressTextEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "Bank Address", nullptr));
        subtotalLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Subtotal: \302\243", nullptr));
        subtotalLineEdit->setText(QString());
        subtotalLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "123456...", nullptr));
        vatBottomLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "VAT: \302\243", nullptr));
        vatPercentLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "Percent", nullptr));
        percentLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "%   ", nullptr));
        vatAmountLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "12312..", nullptr));
        discountLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Discount: %", nullptr));
        discountLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "12341234..", nullptr));
        totalDiscountLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Total Discount: \302\243", nullptr));
        totalDiscountLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "234", nullptr));
        totalLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Total: \302\243", nullptr));
        totalLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "234234..", nullptr));
        balanceDueLabel->setText(QCoreApplication::translate("InvoicePDFFileForm", "Balance Due: \302\243", nullptr));
        balanceDueLineEdit->setPlaceholderText(QCoreApplication::translate("InvoicePDFFileForm", "123123..", nullptr));
        SaveInfo->setText(QCoreApplication::translate("InvoicePDFFileForm", "Save your information", nullptr));
        PrintSaveButton->setText(QCoreApplication::translate("InvoicePDFFileForm", "Print This Page as PDF", nullptr));
        SaveTheInvoice->setText(QCoreApplication::translate("InvoicePDFFileForm", "Save To Documents", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvoicePDFFileForm: public Ui_InvoicePDFFileForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICEPDFFILEFORM_H
