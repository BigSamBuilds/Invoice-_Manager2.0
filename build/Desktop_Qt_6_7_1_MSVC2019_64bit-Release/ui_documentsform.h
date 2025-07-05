/********************************************************************************
** Form generated from reading UI file 'documentsform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTSFORM_H
#define UI_DOCUMENTSFORM_H

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

class Ui_DocumentsForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *buttonLayout;
    QLabel *StatuspageLabel;
    QLabel *PageStatusLabelDocument;
    QSpacerItem *horizontalSpacer;
    QPushButton *DownloadAsPDF;
    QPushButton *deleteButton;
    QPushButton *viewButton;
    QPushButton *DocumentsSearchButton;
    QLineEdit *DocumentsSearchLineEdit;
    QTableView *DocumentTableView;

    void setupUi(QWidget *DocumentsForm)
    {
        if (DocumentsForm->objectName().isEmpty())
            DocumentsForm->setObjectName("DocumentsForm");
        DocumentsForm->resize(1456, 940);
        verticalLayout = new QVBoxLayout(DocumentsForm);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(6);
        buttonLayout->setObjectName("buttonLayout");
        StatuspageLabel = new QLabel(DocumentsForm);
        StatuspageLabel->setObjectName("StatuspageLabel");
        StatuspageLabel->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;"));

        buttonLayout->addWidget(StatuspageLabel);

        PageStatusLabelDocument = new QLabel(DocumentsForm);
        PageStatusLabelDocument->setObjectName("PageStatusLabelDocument");
        PageStatusLabelDocument->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"    color:white;\n"
"    font-family: Arial, Helvetica, sans-serif;\n"
"    font-size: 14px;\n"
"padding-left: 5px;\n"
""));

        buttonLayout->addWidget(PageStatusLabelDocument);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        DownloadAsPDF = new QPushButton(DocumentsForm);
        DownloadAsPDF->setObjectName("DownloadAsPDF");
        DownloadAsPDF->setCursor(QCursor(Qt::PointingHandCursor));
        DownloadAsPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        buttonLayout->addWidget(DownloadAsPDF);

        deleteButton = new QPushButton(DocumentsForm);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"                            background-color: rgba(255, 0, 0, 30); /* White background with 50% opacity */\n"
"                            border-bottom: 2px solid rgb(100, 14, 14); /* White left border */\n"
"                        }"));

        buttonLayout->addWidget(deleteButton);

        viewButton = new QPushButton(DocumentsForm);
        viewButton->setObjectName("viewButton");
        viewButton->setCursor(QCursor(Qt::PointingHandCursor));
        viewButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"                            background-color: rgba(21, 0, 255, 30); /* White background with 50% opacity */\n"
"                            border-bottom: 2px solid rgb(0, 0, 255); /* White left border */\n"
"                        }"));

        buttonLayout->addWidget(viewButton);

        DocumentsSearchButton = new QPushButton(DocumentsForm);
        DocumentsSearchButton->setObjectName("DocumentsSearchButton");
        DocumentsSearchButton->setCursor(QCursor(Qt::PointingHandCursor));
        DocumentsSearchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        buttonLayout->addWidget(DocumentsSearchButton);

        DocumentsSearchLineEdit = new QLineEdit(DocumentsForm);
        DocumentsSearchLineEdit->setObjectName("DocumentsSearchLineEdit");
        DocumentsSearchLineEdit->setMaximumSize(QSize(250, 16777215));
        DocumentsSearchLineEdit->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"    border-bottom: 1px solid white;\n"
"border-right : 5px solid transparent;\n"
"    color: white;\n"
"        padding: 12px;\n"
"    background-color: transparent;\n"
"    font-size: 16px;"));

        buttonLayout->addWidget(DocumentsSearchLineEdit);


        verticalLayout->addLayout(buttonLayout);

        DocumentTableView = new QTableView(DocumentsForm);
        DocumentTableView->setObjectName("DocumentTableView");
        DocumentTableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
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
        DocumentTableView->horizontalHeader()->setStretchLastSection(true);
        DocumentTableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(DocumentTableView);


        retranslateUi(DocumentsForm);

        QMetaObject::connectSlotsByName(DocumentsForm);
    } // setupUi

    void retranslateUi(QWidget *DocumentsForm)
    {
        DocumentsForm->setWindowTitle(QCoreApplication::translate("DocumentsForm", "Form", nullptr));
        DocumentsForm->setStyleSheet(QCoreApplication::translate("DocumentsForm", "background-color: #2d2d2d; color: white;", nullptr));
        StatuspageLabel->setText(QCoreApplication::translate("DocumentsForm", "  Documents", nullptr));
        PageStatusLabelDocument->setText(QCoreApplication::translate("DocumentsForm", "Page:", nullptr));
        DownloadAsPDF->setText(QCoreApplication::translate("DocumentsForm", "Download As PDF", nullptr));
        deleteButton->setText(QCoreApplication::translate("DocumentsForm", "Delete", nullptr));
        viewButton->setText(QCoreApplication::translate("DocumentsForm", "View", nullptr));
        DocumentsSearchButton->setText(QCoreApplication::translate("DocumentsForm", "Search", nullptr));
        DocumentsSearchLineEdit->setPlaceholderText(QCoreApplication::translate("DocumentsForm", "Document search...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocumentsForm: public Ui_DocumentsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTSFORM_H
