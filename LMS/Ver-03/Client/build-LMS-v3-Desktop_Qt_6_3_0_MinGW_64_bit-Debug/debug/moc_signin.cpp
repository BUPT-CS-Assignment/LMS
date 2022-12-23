/****************************************************************************
** Meta object code from reading C++ file 'signin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LMS-v3/header/window/signin.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Signin_t {
    const uint offsetsAndSize[18];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Signin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Signin_t qt_meta_stringdata_Signin = {
    {
QT_MOC_LITERAL(0, 6), // "Signin"
QT_MOC_LITERAL(7, 13), // "SigninSuccess"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 12), // "SigninManage"
QT_MOC_LITERAL(35, 15), // "SigninBackStage"
QT_MOC_LITERAL(51, 23), // "on_signin_click_clicked"
QT_MOC_LITERAL(75, 24), // "on_signup_switch_clicked"
QT_MOC_LITERAL(100, 23), // "on_signup_click_clicked"
QT_MOC_LITERAL(124, 18) // "on_go_back_clicked"

    },
    "Signin\0SigninSuccess\0\0SigninManage\0"
    "SigninBackStage\0on_signin_click_clicked\0"
    "on_signup_switch_clicked\0"
    "on_signup_click_clicked\0on_go_back_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Signin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    0,   58,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Signin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Signin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SigninSuccess(); break;
        case 1: _t->SigninManage(); break;
        case 2: _t->SigninBackStage(); break;
        case 3: _t->on_signin_click_clicked(); break;
        case 4: _t->on_signup_switch_clicked(); break;
        case 5: _t->on_signup_click_clicked(); break;
        case 6: _t->on_go_back_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Signin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Signin::SigninSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Signin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Signin::SigninManage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Signin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Signin::SigninBackStage)) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Signin::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Signin.offsetsAndSize,
    qt_meta_data_Signin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Signin_t
, QtPrivate::TypeAndForceComplete<Signin, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Signin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Signin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Signin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Signin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Signin::SigninSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Signin::SigninManage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Signin::SigninBackStage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
