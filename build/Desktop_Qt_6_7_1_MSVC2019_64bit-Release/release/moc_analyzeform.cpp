/****************************************************************************
** Meta object code from reading C++ file 'analyzeform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../analyzeform.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analyzeform.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAnalyzeFormENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAnalyzeFormENDCLASS = QtMocHelpers::stringData(
    "AnalyzeForm",
    "on_DocumentsRefresh_clicked",
    "",
    "on_ItemsRefresh_clicked",
    "on_PaymentsOutRefresh_clicked",
    "on_PaymentsInNewPayed_clicked",
    "on_resultRefresh_clicked",
    "on_OverviewRefreshButton_2_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAnalyzeFormENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AnalyzeForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAnalyzeFormENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAnalyzeFormENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAnalyzeFormENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AnalyzeForm, std::true_type>,
        // method 'on_DocumentsRefresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ItemsRefresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PaymentsOutRefresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PaymentsInNewPayed_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resultRefresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_OverviewRefreshButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AnalyzeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnalyzeForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_DocumentsRefresh_clicked(); break;
        case 1: _t->on_ItemsRefresh_clicked(); break;
        case 2: _t->on_PaymentsOutRefresh_clicked(); break;
        case 3: _t->on_PaymentsInNewPayed_clicked(); break;
        case 4: _t->on_resultRefresh_clicked(); break;
        case 5: _t->on_OverviewRefreshButton_2_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *AnalyzeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalyzeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAnalyzeFormENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AnalyzeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
