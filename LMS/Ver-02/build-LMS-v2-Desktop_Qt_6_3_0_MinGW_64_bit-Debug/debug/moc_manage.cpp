/****************************************************************************
** Meta object code from reading C++ file 'manage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LMS-v2/header/window/manage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Manage_t {
    const uint offsetsAndSize[38];
    char stringdata0[429];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Manage_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Manage_t qt_meta_stringdata_Manage = {
    {
QT_MOC_LITERAL(0, 6), // "Manage"
QT_MOC_LITERAL(7, 13), // "SignoutSignal"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 19), // "on_mng_user_clicked"
QT_MOC_LITERAL(42, 20), // "on_mng_check_clicked"
QT_MOC_LITERAL(63, 17), // "on_search_clicked"
QT_MOC_LITERAL(81, 18), // "on_refresh_clicked"
QT_MOC_LITERAL(100, 24), // "on_search_goback_clicked"
QT_MOC_LITERAL(125, 19), // "on_sign_out_clicked"
QT_MOC_LITERAL(145, 22), // "on_change_info_clicked"
QT_MOC_LITERAL(168, 28), // "on_change_info_click_clicked"
QT_MOC_LITERAL(197, 35), // "on_change_info_cancel_click_c..."
QT_MOC_LITERAL(233, 24), // "on_change_passwd_clicked"
QT_MOC_LITERAL(258, 30), // "on_change_passwd_click_clicked"
QT_MOC_LITERAL(289, 37), // "on_change_paaswd_cancel_click..."
QT_MOC_LITERAL(327, 19), // "on_recharge_clicked"
QT_MOC_LITERAL(347, 25), // "on_recharge_click_clicked"
QT_MOC_LITERAL(373, 32), // "on_recharge_cancel_click_clicked"
QT_MOC_LITERAL(406, 22) // "on_collect_all_clicked"

    },
    "Manage\0SignoutSignal\0\0on_mng_user_clicked\0"
    "on_mng_check_clicked\0on_search_clicked\0"
    "on_refresh_clicked\0on_search_goback_clicked\0"
    "on_sign_out_clicked\0on_change_info_clicked\0"
    "on_change_info_click_clicked\0"
    "on_change_info_cancel_click_clicked\0"
    "on_change_passwd_clicked\0"
    "on_change_passwd_click_clicked\0"
    "on_change_paaswd_cancel_click_clicked\0"
    "on_recharge_clicked\0on_recharge_click_clicked\0"
    "on_recharge_cancel_click_clicked\0"
    "on_collect_all_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Manage[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    0,  118,    2, 0x08,    3 /* Private */,
       5,    0,  119,    2, 0x08,    4 /* Private */,
       6,    0,  120,    2, 0x08,    5 /* Private */,
       7,    0,  121,    2, 0x08,    6 /* Private */,
       8,    0,  122,    2, 0x08,    7 /* Private */,
       9,    0,  123,    2, 0x08,    8 /* Private */,
      10,    0,  124,    2, 0x08,    9 /* Private */,
      11,    0,  125,    2, 0x08,   10 /* Private */,
      12,    0,  126,    2, 0x08,   11 /* Private */,
      13,    0,  127,    2, 0x08,   12 /* Private */,
      14,    0,  128,    2, 0x08,   13 /* Private */,
      15,    0,  129,    2, 0x08,   14 /* Private */,
      16,    0,  130,    2, 0x08,   15 /* Private */,
      17,    0,  131,    2, 0x08,   16 /* Private */,
      18,    0,  132,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Manage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Manage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignoutSignal(); break;
        case 1: _t->on_mng_user_clicked(); break;
        case 2: _t->on_mng_check_clicked(); break;
        case 3: _t->on_search_clicked(); break;
        case 4: _t->on_refresh_clicked(); break;
        case 5: _t->on_search_goback_clicked(); break;
        case 6: _t->on_sign_out_clicked(); break;
        case 7: _t->on_change_info_clicked(); break;
        case 8: _t->on_change_info_click_clicked(); break;
        case 9: _t->on_change_info_cancel_click_clicked(); break;
        case 10: _t->on_change_passwd_clicked(); break;
        case 11: _t->on_change_passwd_click_clicked(); break;
        case 12: _t->on_change_paaswd_cancel_click_clicked(); break;
        case 13: _t->on_recharge_clicked(); break;
        case 14: _t->on_recharge_click_clicked(); break;
        case 15: _t->on_recharge_cancel_click_clicked(); break;
        case 16: _t->on_collect_all_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Manage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Manage::SignoutSignal)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Manage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Manage.offsetsAndSize,
    qt_meta_data_Manage,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Manage_t
, QtPrivate::TypeAndForceComplete<Manage, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Manage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Manage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Manage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Manage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Manage::SignoutSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
