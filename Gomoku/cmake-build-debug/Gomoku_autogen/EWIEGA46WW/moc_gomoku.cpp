/****************************************************************************
** Meta object code from reading C++ file 'gomoku.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../gomoku.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gomoku.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gomoku_t {
    QByteArrayData data[17];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gomoku_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gomoku_t qt_meta_stringdata_Gomoku = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Gomoku"
QT_MOC_LITERAL(1, 7, 11), // "information"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "str"
QT_MOC_LITERAL(4, 24, 6), // "subWin"
QT_MOC_LITERAL(5, 31, 7), // "giveupF"
QT_MOC_LITERAL(6, 39, 5), // "agree"
QT_MOC_LITERAL(7, 45, 6), // "reject"
QT_MOC_LITERAL(8, 52, 7), // "gobackF"
QT_MOC_LITERAL(9, 60, 6), // "peaceF"
QT_MOC_LITERAL(10, 67, 8), // "send_msg"
QT_MOC_LITERAL(11, 76, 4), // "drop"
QT_MOC_LITERAL(12, 81, 5), // "start"
QT_MOC_LITERAL(13, 87, 15), // "informationShow"
QT_MOC_LITERAL(14, 103, 13), // "keyPressEvent"
QT_MOC_LITERAL(15, 117, 10), // "QKeyEvent*"
QT_MOC_LITERAL(16, 128, 1) // "e"

    },
    "Gomoku\0information\0\0str\0subWin\0giveupF\0"
    "agree\0reject\0gobackF\0peaceF\0send_msg\0"
    "drop\0start\0informationShow\0keyPressEvent\0"
    "QKeyEvent*\0e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gomoku[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   74,    2, 0x0a /* Public */,
       6,    0,   75,    2, 0x0a /* Public */,
       7,    0,   76,    2, 0x0a /* Public */,
       8,    0,   77,    2, 0x0a /* Public */,
       9,    0,   78,    2, 0x0a /* Public */,
      10,    0,   79,    2, 0x0a /* Public */,
      11,    2,   80,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    2,   86,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void Gomoku::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gomoku *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->giveupF(); break;
        case 2: _t->agree(); break;
        case 3: _t->reject(); break;
        case 4: _t->gobackF(); break;
        case 5: _t->peaceF(); break;
        case 6: _t->send_msg(); break;
        case 7: _t->drop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->start(); break;
        case 9: _t->informationShow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Gomoku::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gomoku::information)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Gomoku::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Gomoku.data,
    qt_meta_data_Gomoku,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Gomoku::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gomoku::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gomoku.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Gomoku::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Gomoku::information(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
