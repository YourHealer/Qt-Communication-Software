/****************************************************************************
** Meta object code from reading C++ file 'chooseuser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeeU/chooseuser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chooseuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChooseUser_t {
    QByteArrayData data[17];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChooseUser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChooseUser_t qt_meta_stringdata_ChooseUser = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChooseUser"
QT_MOC_LITERAL(1, 11, 15), // "sendWindowClose"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "sendAccount"
QT_MOC_LITERAL(4, 40, 13), // "DoubleClicked"
QT_MOC_LITERAL(5, 54, 13), // "getInitWindow"
QT_MOC_LITERAL(6, 68, 7), // "account"
QT_MOC_LITERAL(7, 76, 4), // "name"
QT_MOC_LITERAL(8, 81, 4), // "sign"
QT_MOC_LITERAL(9, 86, 4), // "head"
QT_MOC_LITERAL(10, 91, 10), // "getAccount"
QT_MOC_LITERAL(11, 102, 11), // "readMessage"
QT_MOC_LITERAL(12, 114, 16), // "tcpServerConnect"
QT_MOC_LITERAL(13, 131, 33), // "on_pushButtonGetNewFriend_cli..."
QT_MOC_LITERAL(14, 165, 37), // "on_listWidgetFriend_itemDoubl..."
QT_MOC_LITERAL(15, 203, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(16, 220, 4) // "item"

    },
    "ChooseUser\0sendWindowClose\0\0sendAccount\0"
    "DoubleClicked\0getInitWindow\0account\0"
    "name\0sign\0head\0getAccount\0readMessage\0"
    "tcpServerConnect\0on_pushButtonGetNewFriend_clicked\0"
    "on_listWidgetFriend_itemDoubleClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChooseUser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    2,   62,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    4,   68,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void ChooseUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChooseUser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWindowClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sendAccount((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->DoubleClicked(); break;
        case 3: _t->getInitWindow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: { QString _r = _t->getAccount((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->readMessage(); break;
        case 6: _t->tcpServerConnect(); break;
        case 7: _t->on_pushButtonGetNewFriend_clicked(); break;
        case 8: _t->on_listWidgetFriend_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChooseUser::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChooseUser::sendWindowClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChooseUser::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChooseUser::sendAccount)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChooseUser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChooseUser::DoubleClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChooseUser::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ChooseUser.data,
    qt_meta_data_ChooseUser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChooseUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChooseUser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChooseUser.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChooseUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ChooseUser::sendWindowClose(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChooseUser::sendAccount(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChooseUser::DoubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
