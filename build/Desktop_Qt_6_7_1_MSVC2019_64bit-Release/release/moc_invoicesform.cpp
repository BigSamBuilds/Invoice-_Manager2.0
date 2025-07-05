/****************************************************************************
** Meta object code from reading C++ file 'invoicesform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../invoicesform.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'invoicesform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSInvoicesFormENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSInvoicesFormENDCLASS = QtMocHelpers::stringData(
    "InvoicesForm",
    "on_InvoiceSearchButtonCustomers_clicked",
    "",
    "on_InvoicesSearchLineEditCustomers_returnPressed",
    "on_InvoicesSearchLineEditCustomers_textChanged",
    "arg1",
    "on_InvoicesProductEditLine_returnPressed",
    "on_InvoicesProductEditLine_textChanged",
    "on_InvoicesSearchProduktItems_clicked",
    "on_generateInvoiceButton_clicked",
    "on_InvoiceDeleteRow_clicked",
    "on_invoiceTableView_clicked",
    "QModelIndex",
    "index",
    "on_InvoiceInsertNewRow_clicked",
    "on_pushButton_clicked",
    "on_ProductInsertNewRow_clicked",
    "on_productDeleteRow_clicked",
    "on_refreshInvoiceDetails_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSInvoicesFormENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    1,  100,    2, 0x08,    3 /* Private */,
       6,    0,  103,    2, 0x08,    5 /* Private */,
       7,    1,  104,    2, 0x08,    6 /* Private */,
       8,    0,  107,    2, 0x08,    8 /* Private */,
       9,    0,  108,    2, 0x08,    9 /* Private */,
      10,    0,  109,    2, 0x08,   10 /* Private */,
      11,    1,  110,    2, 0x08,   11 /* Private */,
      14,    0,  113,    2, 0x08,   13 /* Private */,
      15,    0,  114,    2, 0x08,   14 /* Private */,
      16,    0,  115,    2, 0x08,   15 /* Private */,
      17,    0,  116,    2, 0x08,   16 /* Private */,
      18,    0,  117,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject InvoicesForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSInvoicesFormENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSInvoicesFormENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSInvoicesFormENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<InvoicesForm, std::true_type>,
        // method 'on_InvoiceSearchButtonCustomers_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_InvoicesSearchLineEditCustomers_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_InvoicesSearchLineEditCustomers_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_InvoicesProductEditLine_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_InvoicesProductEditLine_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_InvoicesSearchProduktItems_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_generateInvoiceButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_InvoiceDeleteRow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_invoiceTableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_InvoiceInsertNewRow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ProductInsertNewRow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_productDeleteRow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_refreshInvoiceDetails_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void InvoicesForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InvoicesForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_InvoiceSearchButtonCustomers_clicked(); break;
        case 1: _t->on_InvoicesSearchLineEditCustomers_returnPressed(); break;
        case 2: _t->on_InvoicesSearchLineEditCustomers_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_InvoicesProductEditLine_returnPressed(); break;
        case 4: _t->on_InvoicesProductEditLine_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_InvoicesSearchProduktItems_clicked(); break;
        case 6: _t->on_generateInvoiceButton_clicked(); break;
        case 7: _t->on_InvoiceDeleteRow_clicked(); break;
        case 8: _t->on_invoiceTableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->on_InvoiceInsertNewRow_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_ProductInsertNewRow_clicked(); break;
        case 12: _t->on_productDeleteRow_clicked(); break;
        case 13: _t->on_refreshInvoiceDetails_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *InvoicesForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InvoicesForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSInvoicesFormENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InvoicesForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
