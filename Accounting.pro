QT       += core gui \
    quick

QT += webenginewidgets

QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

QT_CHARTS_USE_NAMESPACE

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/database.cpp \
    Controller/enableforgeingkeysqlite.cpp \
    Controller/functiontools.cpp \
    Controller/staticinformations.cpp \
    Controller/tablecreator.cpp \
    PaymentsOut.cpp \
    Vendors2Form.cpp \
    analyzeform.cpp \
    booleancomboboxdelegate.cpp \
    customersform.cpp \
    documentsform.cpp \
    functools.cpp \
    invoicepdffileform.cpp \
    invoicesform.cpp \
    itemform.cpp \
    main.cpp \
    dashboard.cpp \
    overviewform.cpp \
    paginationmodel.cpp \
    paymentsinform.cpp

HEADERS += \
    Controller/database.h \
    Controller/enableforgeingkeysqlite.h \
    Controller/functiontools.h \
    Controller/staticinformations.h \
    Controller/tablecreator.h \
    PaymentsOut.h \
    Vendors2Form.h \
    analyzeform.h \
    booleancomboboxdelegate.h \
    customersform.h \
    dashboard.h \
    documentsform.h \
    functools.h \
    invoicepdffileform.h \
    invoicesform.h \
    itemform.h \
    overviewform.h \
    paginationmodel.h \
    paymentsinform.h

FORMS += \
    PaymentsOut.ui \
    Vendors2Form.ui \
    analyzeform.ui \
    customersform.ui \
    dashboard.ui \
    documentsform.ui \
    invoicepdffileform.ui \
    invoicesform.ui \
    itemform.ui \
    overviewform.ui \
    paymentsinform.ui


# QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt.exe $$shell_quote($$DESTDIR/$$shell_quote($$TARGET).exe) --no-compiler-runtime

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

RC_ICONS += IconW1.ico





