/********************************************************************************
** Form generated from reading UI file 'PaymentsOut.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTSOUT_H
#define UI_PAYMENTSOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VendorsForm
{
public:
    QVBoxLayout *verticalLayoutMain;
    QHBoxLayout *horizontalLayoutTop;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *RefreshPaymentsOutBtn;
    QPushButton *InsertNewRowVendors;
    QPushButton *DeleteCurrentRowVendors;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;
    QVBoxLayout *verticalLayoutTables;
    QVBoxLayout *verticalLayoutVendors;
    QScrollArea *scrollAreaVendors;
    QWidget *scrollAreaWidgetContentsVendors;
    QVBoxLayout *verticalLayoutScrollVendors;
    QTableView *VendorsTableView;
    QVBoxLayout *verticalLayoutItemsBought;
    QHBoxLayout *horizontalLayout;
    QLabel *itemsBoughtLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *RefreshItemBoguthItemBtn;
    QPushButton *InsertNewRowItems;
    QPushButton *DeleteCurrentRowItems;
    QPushButton *VendorsItemSearchButton;
    QLineEdit *VendorsSearchEditLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *VendorsIDStatus;
    QLabel *VendorsNameStatus;
    QLabel *VendorsRecentChangesStatus;
    QScrollArea *scrollAreaItemsBought;
    QWidget *scrollAreaWidgetContentsItemsBought;
    QVBoxLayout *verticalLayoutScrollItemsBought;
    QTableView *ItemBoughtTableView;

    void setupUi(QWidget *VendorsForm)
    {
        if (VendorsForm->objectName().isEmpty())
            VendorsForm->setObjectName("VendorsForm");
        VendorsForm->resize(1166, 1015);
        VendorsForm->setStyleSheet(QString::fromUtf8("background-color: #2d2d2d; color: white;"));
        verticalLayoutMain = new QVBoxLayout(VendorsForm);
        verticalLayoutMain->setSpacing(2);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        verticalLayoutMain->setContentsMargins(1, 1, 1, 1);
        horizontalLayoutTop = new QHBoxLayout();
        horizontalLayoutTop->setObjectName("horizontalLayoutTop");
        horizontalLayoutTop->setContentsMargins(-1, 10, -1, -1);
        statusLabel = new QLabel(VendorsForm);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));
        statusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayoutTop->addWidget(statusLabel);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutTop->addItem(horizontalSpacer);

        RefreshPaymentsOutBtn = new QPushButton(VendorsForm);
        RefreshPaymentsOutBtn->setObjectName("RefreshPaymentsOutBtn");
        RefreshPaymentsOutBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayoutTop->addWidget(RefreshPaymentsOutBtn);

        InsertNewRowVendors = new QPushButton(VendorsForm);
        InsertNewRowVendors->setObjectName("InsertNewRowVendors");
        InsertNewRowVendors->setCursor(QCursor(Qt::PointingHandCursor));
        InsertNewRowVendors->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayoutTop->addWidget(InsertNewRowVendors);

        DeleteCurrentRowVendors = new QPushButton(VendorsForm);
        DeleteCurrentRowVendors->setObjectName("DeleteCurrentRowVendors");
        DeleteCurrentRowVendors->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteCurrentRowVendors->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayoutTop->addWidget(DeleteCurrentRowVendors);

        searchButton = new QPushButton(VendorsForm);
        searchButton->setObjectName("searchButton");
        searchButton->setCursor(QCursor(Qt::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayoutTop->addWidget(searchButton);

        searchLineEdit = new QLineEdit(VendorsForm);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(250, 0));
        searchLineEdit->setMaximumSize(QSize(250, 16777215));
        searchLineEdit->setCursor(QCursor(Qt::PointingHandCursor));
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

        verticalLayoutTables = new QVBoxLayout();
        verticalLayoutTables->setSpacing(3);
        verticalLayoutTables->setObjectName("verticalLayoutTables");
        verticalLayoutVendors = new QVBoxLayout();
        verticalLayoutVendors->setObjectName("verticalLayoutVendors");
        verticalLayoutVendors->setContentsMargins(0, 0, 0, 0);
        scrollAreaVendors = new QScrollArea(VendorsForm);
        scrollAreaVendors->setObjectName("scrollAreaVendors");
        scrollAreaVendors->setWidgetResizable(true);
        scrollAreaWidgetContentsVendors = new QWidget();
        scrollAreaWidgetContentsVendors->setObjectName("scrollAreaWidgetContentsVendors");
        scrollAreaWidgetContentsVendors->setGeometry(QRect(0, 0, 1158, 406));
        verticalLayoutScrollVendors = new QVBoxLayout(scrollAreaWidgetContentsVendors);
        verticalLayoutScrollVendors->setSpacing(0);
        verticalLayoutScrollVendors->setObjectName("verticalLayoutScrollVendors");
        verticalLayoutScrollVendors->setContentsMargins(0, 0, 0, 0);
        VendorsTableView = new QTableView(scrollAreaWidgetContentsVendors);
        VendorsTableView->setObjectName("VendorsTableView");
        VendorsTableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
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
        VendorsTableView->setAlternatingRowColors(true);
        VendorsTableView->horizontalHeader()->setStretchLastSection(true);
        VendorsTableView->verticalHeader()->setVisible(false);

        verticalLayoutScrollVendors->addWidget(VendorsTableView);

        scrollAreaVendors->setWidget(scrollAreaWidgetContentsVendors);

        verticalLayoutVendors->addWidget(scrollAreaVendors);


        verticalLayoutTables->addLayout(verticalLayoutVendors);

        verticalLayoutItemsBought = new QVBoxLayout();
        verticalLayoutItemsBought->setObjectName("verticalLayoutItemsBought");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 15, 0, 0);
        itemsBoughtLabel = new QLabel(VendorsForm);
        itemsBoughtLabel->setObjectName("itemsBoughtLabel");
        itemsBoughtLabel->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));
        itemsBoughtLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(itemsBoughtLabel);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        RefreshItemBoguthItemBtn = new QPushButton(VendorsForm);
        RefreshItemBoguthItemBtn->setObjectName("RefreshItemBoguthItemBtn");
        RefreshItemBoguthItemBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(RefreshItemBoguthItemBtn);

        InsertNewRowItems = new QPushButton(VendorsForm);
        InsertNewRowItems->setObjectName("InsertNewRowItems");
        InsertNewRowItems->setCursor(QCursor(Qt::PointingHandCursor));
        InsertNewRowItems->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(InsertNewRowItems);

        DeleteCurrentRowItems = new QPushButton(VendorsForm);
        DeleteCurrentRowItems->setObjectName("DeleteCurrentRowItems");
        DeleteCurrentRowItems->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteCurrentRowItems->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(DeleteCurrentRowItems);

        VendorsItemSearchButton = new QPushButton(VendorsForm);
        VendorsItemSearchButton->setObjectName("VendorsItemSearchButton");
        VendorsItemSearchButton->setCursor(QCursor(Qt::PointingHandCursor));
        VendorsItemSearchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(VendorsItemSearchButton);

        VendorsSearchEditLine = new QLineEdit(VendorsForm);
        VendorsSearchEditLine->setObjectName("VendorsSearchEditLine");
        VendorsSearchEditLine->setMinimumSize(QSize(250, 0));
        VendorsSearchEditLine->setMaximumSize(QSize(250, 16777215));
        VendorsSearchEditLine->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"    border-bottom: 1px solid white;\n"
"border-right : 5px solid transparent;\n"
"    color: white;\n"
"        padding: 12px;\n"
"    background-color: transparent;\n"
"    font-size: 16px;"));

        horizontalLayout->addWidget(VendorsSearchEditLine);


        verticalLayoutItemsBought->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        VendorsIDStatus = new QLabel(VendorsForm);
        VendorsIDStatus->setObjectName("VendorsIDStatus");
        VendorsIDStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_2->addWidget(VendorsIDStatus);

        VendorsNameStatus = new QLabel(VendorsForm);
        VendorsNameStatus->setObjectName("VendorsNameStatus");
        VendorsNameStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_2->addWidget(VendorsNameStatus);

        VendorsRecentChangesStatus = new QLabel(VendorsForm);
        VendorsRecentChangesStatus->setObjectName("VendorsRecentChangesStatus");
        VendorsRecentChangesStatus->setStyleSheet(QString::fromUtf8("color: white; font: 75 13pt \"MS Shell Dlg 2\";\n"
"                                margin: 4px 2px; /* Margin around button */\n"
"                                                                        "));

        horizontalLayout_2->addWidget(VendorsRecentChangesStatus);


        verticalLayoutItemsBought->addLayout(horizontalLayout_2);

        scrollAreaItemsBought = new QScrollArea(VendorsForm);
        scrollAreaItemsBought->setObjectName("scrollAreaItemsBought");
        scrollAreaItemsBought->setMinimumSize(QSize(0, 400));
        scrollAreaItemsBought->setFrameShape(QFrame::NoFrame);
        scrollAreaItemsBought->setWidgetResizable(true);
        scrollAreaWidgetContentsItemsBought = new QWidget();
        scrollAreaWidgetContentsItemsBought->setObjectName("scrollAreaWidgetContentsItemsBought");
        scrollAreaWidgetContentsItemsBought->setGeometry(QRect(0, 0, 1160, 400));
        verticalLayoutScrollItemsBought = new QVBoxLayout(scrollAreaWidgetContentsItemsBought);
        verticalLayoutScrollItemsBought->setSpacing(0);
        verticalLayoutScrollItemsBought->setObjectName("verticalLayoutScrollItemsBought");
        verticalLayoutScrollItemsBought->setContentsMargins(0, 10, 0, 15);
        ItemBoughtTableView = new QTableView(scrollAreaWidgetContentsItemsBought);
        ItemBoughtTableView->setObjectName("ItemBoughtTableView");
        ItemBoughtTableView->setStyleSheet(QString::fromUtf8("/* QTableView */\n"
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
        ItemBoughtTableView->setAlternatingRowColors(true);
        ItemBoughtTableView->horizontalHeader()->setStretchLastSection(true);
        ItemBoughtTableView->verticalHeader()->setVisible(false);

        verticalLayoutScrollItemsBought->addWidget(ItemBoughtTableView);

        scrollAreaItemsBought->setWidget(scrollAreaWidgetContentsItemsBought);

        verticalLayoutItemsBought->addWidget(scrollAreaItemsBought);


        verticalLayoutTables->addLayout(verticalLayoutItemsBought);


        verticalLayoutMain->addLayout(verticalLayoutTables);


        retranslateUi(VendorsForm);

        QMetaObject::connectSlotsByName(VendorsForm);
    } // setupUi

    void retranslateUi(QWidget *VendorsForm)
    {
        VendorsForm->setWindowTitle(QCoreApplication::translate("VendorsForm", "Form", nullptr));
        statusLabel->setText(QCoreApplication::translate("VendorsForm", "Payments Out", nullptr));
        RefreshPaymentsOutBtn->setText(QCoreApplication::translate("VendorsForm", "Refresh", nullptr));
        InsertNewRowVendors->setText(QCoreApplication::translate("VendorsForm", "Insert New Row", nullptr));
        DeleteCurrentRowVendors->setText(QCoreApplication::translate("VendorsForm", "Delete Current Row", nullptr));
        searchButton->setText(QCoreApplication::translate("VendorsForm", "Search", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("VendorsForm", "Enter vendor name...", nullptr));
        itemsBoughtLabel->setText(QCoreApplication::translate("VendorsForm", "Items Bought from Vendors", nullptr));
        RefreshItemBoguthItemBtn->setText(QCoreApplication::translate("VendorsForm", "Refresh", nullptr));
        InsertNewRowItems->setText(QCoreApplication::translate("VendorsForm", "Insert New Row", nullptr));
        DeleteCurrentRowItems->setText(QCoreApplication::translate("VendorsForm", "Delete Current Row", nullptr));
        VendorsItemSearchButton->setText(QCoreApplication::translate("VendorsForm", "Search", nullptr));
        VendorsSearchEditLine->setPlaceholderText(QCoreApplication::translate("VendorsForm", "Enter Item name...", nullptr));
        VendorsIDStatus->setText(QCoreApplication::translate("VendorsForm", "ID:", nullptr));
        VendorsNameStatus->setText(QCoreApplication::translate("VendorsForm", "Name:", nullptr));
        VendorsRecentChangesStatus->setText(QCoreApplication::translate("VendorsForm", "Recent Changes: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VendorsForm: public Ui_VendorsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTSOUT_H
