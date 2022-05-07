/****************************************************************************
** Meta object code from reading C++ file 'calc.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/calc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calc_t {
    const uint offsetsAndSize[32];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_calc_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_calc_t qt_meta_stringdata_calc = {
    {
QT_MOC_LITERAL(0, 4), // "calc"
QT_MOC_LITERAL(5, 12), // "DigitClicked"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 20), // "UnaryOperatorClicked"
QT_MOC_LITERAL(40, 23), // "AdditiveOperatorClicked"
QT_MOC_LITERAL(64, 29), // "MultiplicativeOperatorClicked"
QT_MOC_LITERAL(94, 12), // "EqualClicked"
QT_MOC_LITERAL(107, 12), // "PointClicked"
QT_MOC_LITERAL(120, 17), // "ChangeSignClicked"
QT_MOC_LITERAL(138, 16), // "BackspaceClicked"
QT_MOC_LITERAL(155, 5), // "Clear"
QT_MOC_LITERAL(161, 8), // "ClearAll"
QT_MOC_LITERAL(170, 11), // "ClearMemory"
QT_MOC_LITERAL(182, 10), // "ReadMemory"
QT_MOC_LITERAL(193, 9), // "SetMemory"
QT_MOC_LITERAL(203, 11) // "AddToMemory"

    },
    "calc\0DigitClicked\0\0UnaryOperatorClicked\0"
    "AdditiveOperatorClicked\0"
    "MultiplicativeOperatorClicked\0"
    "EqualClicked\0PointClicked\0ChangeSignClicked\0"
    "BackspaceClicked\0Clear\0ClearAll\0"
    "ClearMemory\0ReadMemory\0SetMemory\0"
    "AddToMemory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calc[] = {

 // content:
      10,       // revision
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
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    0,  107,    2, 0x08,   10 /* Private */,
      12,    0,  108,    2, 0x08,   11 /* Private */,
      13,    0,  109,    2, 0x08,   12 /* Private */,
      14,    0,  110,    2, 0x08,   13 /* Private */,
      15,    0,  111,    2, 0x08,   14 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<calc *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->DigitClicked(); break;
        case 1: _t->UnaryOperatorClicked(); break;
        case 2: _t->AdditiveOperatorClicked(); break;
        case 3: _t->MultiplicativeOperatorClicked(); break;
        case 4: _t->EqualClicked(); break;
        case 5: _t->PointClicked(); break;
        case 6: _t->ChangeSignClicked(); break;
        case 7: _t->BackspaceClicked(); break;
        case 8: _t->Clear(); break;
        case 9: _t->ClearAll(); break;
        case 10: _t->ClearMemory(); break;
        case 11: _t->ReadMemory(); break;
        case 12: _t->SetMemory(); break;
        case 13: _t->AddToMemory(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject calc::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_calc.offsetsAndSize,
    qt_meta_data_calc,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_calc_t
, QtPrivate::TypeAndForceComplete<calc, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *calc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_calc.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int calc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
