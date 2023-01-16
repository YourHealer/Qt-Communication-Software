/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeeU/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_User_t {
    QByteArrayData data[15];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_User_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_User_t qt_meta_stringdata_User = {
    {
QT_MOC_LITERAL(0, 0, 4), // "User"
QT_MOC_LITERAL(1, 5, 11), // "sendAccount"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "fileComes"
QT_MOC_LITERAL(4, 28, 10), // "getAccount"
QT_MOC_LITERAL(5, 39, 5), // "user1"
QT_MOC_LITERAL(6, 45, 5), // "user2"
QT_MOC_LITERAL(7, 51, 11), // "sendMessage"
QT_MOC_LITERAL(8, 63, 11), // "readMessage"
QT_MOC_LITERAL(9, 75, 16), // "tcpServerConnect"
QT_MOC_LITERAL(10, 92, 4), // "send"
QT_MOC_LITERAL(11, 97, 25), // "on_readFileButton_clicked"
QT_MOC_LITERAL(12, 123, 27), // "on_selectFileButton_clicked"
QT_MOC_LITERAL(13, 151, 25), // "on_sendFileButton_clicked"
QT_MOC_LITERAL(14, 177, 8) // "sendData"

    },
    "User\0sendAccount\0\0fileComes\0getAccount\0"
    "user1\0user2\0sendMessage\0readMessage\0"
    "tcpServerConnect\0send\0on_readFileButton_clicked\0"
    "on_selectFileButton_clicked\0"
    "on_sendFileButton_clicked\0sendData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_User[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   73,    2, 0x0a /* Public */,
       7,    0,   78,    2, 0x0a /* Public */,
       8,    0,   79,    2, 0x0a /* Public */,
       9,    0,   80,    2, 0x0a /* Public */,
      10,    0,   81,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,
      13,    0,   84,    2, 0x0a /* Public */,
      14,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
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

void User::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<User *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAccount((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->fileComes(); break;
        case 2: _t->getAccount((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendMessage(); break;
        case 4: _t->readMessage(); break;
        case 5: _t->tcpServerConnect(); break;
        case 6: _t->send(); break;
        case 7: _t->on_readFileButton_clicked(); break;
        case 8: _t->on_selectFileButton_clicked(); break;
        case 9: _t->on_sendFileButton_clicked(); break;
        case 10: _t->sendData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (User::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User::sendAccount)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (User::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&User::fileComes)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject User::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_User.data,
    qt_meta_data_User,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *User::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_User.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int User::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void User::sendAccount(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void User::fileComes()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
