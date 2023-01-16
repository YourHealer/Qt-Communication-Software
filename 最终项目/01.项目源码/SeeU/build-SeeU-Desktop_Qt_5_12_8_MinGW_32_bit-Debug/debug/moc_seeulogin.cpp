/****************************************************************************
** Meta object code from reading C++ file 'seeulogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SeeU/seeulogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'seeulogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SeeULogin_t {
    QByteArrayData data[16];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeeULogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeeULogin_t qt_meta_stringdata_SeeULogin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SeeULogin"
QT_MOC_LITERAL(1, 10, 11), // "sendAccount"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "getClose"
QT_MOC_LITERAL(4, 32, 4), // "flag"
QT_MOC_LITERAL(5, 37, 16), // "getRegisterClose"
QT_MOC_LITERAL(6, 54, 12), // "getFindClose"
QT_MOC_LITERAL(7, 67, 5), // "login"
QT_MOC_LITERAL(8, 73, 13), // "login_success"
QT_MOC_LITERAL(9, 87, 16), // "remember_account"
QT_MOC_LITERAL(10, 104, 10), // "auto_login"
QT_MOC_LITERAL(11, 115, 16), // "register_account"
QT_MOC_LITERAL(12, 132, 13), // "find_password"
QT_MOC_LITERAL(13, 146, 13), // "connectServer"
QT_MOC_LITERAL(14, 160, 13), // "commitMessage"
QT_MOC_LITERAL(15, 174, 11) // "readMessage"

    },
    "SeeULogin\0sendAccount\0\0getClose\0flag\0"
    "getRegisterClose\0getFindClose\0login\0"
    "login_success\0remember_account\0"
    "auto_login\0register_account\0find_password\0"
    "connectServer\0commitMessage\0readMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeeULogin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   82,    2, 0x08 /* Private */,
       5,    1,   85,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SeeULogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SeeULogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAccount((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->getRegisterClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->getFindClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->login(); break;
        case 5: _t->login_success(); break;
        case 6: _t->remember_account(); break;
        case 7: _t->auto_login(); break;
        case 8: _t->register_account(); break;
        case 9: _t->find_password(); break;
        case 10: { bool _r = _t->connectServer();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->commitMessage(); break;
        case 12: _t->readMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SeeULogin::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SeeULogin::sendAccount)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SeeULogin::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_SeeULogin.data,
    qt_meta_data_SeeULogin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SeeULogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeeULogin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SeeULogin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SeeULogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SeeULogin::sendAccount(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
