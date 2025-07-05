/****************************************************************************
** Meta object code from reading C++ file 'dashboard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dashboard.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboard.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDashboardENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDashboardENDCLASS = QtMocHelpers::stringData(
    "Dashboard",
    "on_Overview_clicked",
    "",
    "on_Items_clicked",
    "on_Documents_clicked",
    "on_Vendors_clicked",
    "on_PaymentOut_clicked",
    "on_Customers_clicked",
    "on_Invoices_clicked",
    "on_PaymentIn_clicked",
    "on_Analys_clicked",
    "resizeEvent",
    "QResizeEvent*",
    "event"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDashboardENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    1,   83,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject Dashboard::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSDashboardENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDashboardENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDashboardENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dashboard, std::true_type>,
        // method 'on_Overview_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Items_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Documents_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Vendors_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PaymentOut_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Customers_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Invoices_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PaymentIn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Analys_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>
    >,
    nullptr
} };

void Dashboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dashboard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Overview_clicked(); break;
        case 1: _t->on_Items_clicked(); break;
        case 2: _t->on_Documents_clicked(); break;
        case 3: _t->on_Vendors_clicked(); break;
        case 4: _t->on_PaymentOut_clicked(); break;
        case 5: _t->on_Customers_clicked(); break;
        case 6: _t->on_Invoices_clicked(); break;
        case 7: _t->on_PaymentIn_clicked(); break;
        case 8: _t->on_Analys_clicked(); break;
        case 9: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Dashboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dashboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDashboardENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Dashboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
