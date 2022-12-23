/****************************************************************************
** Meta object code from reading C++ file 'backstage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../LMS-v3/header/window/backstage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backstage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackStage_t {
    const uint offsetsAndSize[36];
    char stringdata0[380];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BackStage_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BackStage_t qt_meta_stringdata_BackStage = {
    {
QT_MOC_LITERAL(0, 9), // "BackStage"
QT_MOC_LITERAL(10, 13), // "SignoutSignal"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 25), // "on_sign_out_click_clicked"
QT_MOC_LITERAL(51, 29), // "on_packet_page_select_clicked"
QT_MOC_LITERAL(81, 27), // "on_user_page_select_clicked"
QT_MOC_LITERAL(109, 30), // "on_packet_search_click_clicked"
QT_MOC_LITERAL(140, 32), // "on_packet_search_refresh_clicked"
QT_MOC_LITERAL(173, 28), // "on_user_search_click_clicked"
QT_MOC_LITERAL(202, 30), // "on_user_search_refresh_clicked"
QT_MOC_LITERAL(233, 10), // "option_set"
QT_MOC_LITERAL(244, 3), // "row"
QT_MOC_LITERAL(248, 23), // "on_packet_alloc_clicked"
QT_MOC_LITERAL(272, 31), // "on_auto_allocation_stateChanged"
QT_MOC_LITERAL(304, 4), // "arg1"
QT_MOC_LITERAL(309, 22), // "on_user_delete_clicked"
QT_MOC_LITERAL(332, 19), // "on_user_add_clicked"
QT_MOC_LITERAL(352, 27) // "on_store_data_click_clicked"

    },
    "BackStage\0SignoutSignal\0\0"
    "on_sign_out_click_clicked\0"
    "on_packet_page_select_clicked\0"
    "on_user_page_select_clicked\0"
    "on_packet_search_click_clicked\0"
    "on_packet_search_refresh_clicked\0"
    "on_user_search_click_clicked\0"
    "on_user_search_refresh_clicked\0"
    "option_set\0row\0on_packet_alloc_clicked\0"
    "on_auto_allocation_stateChanged\0arg1\0"
    "on_user_delete_clicked\0on_user_add_clicked\0"
    "on_store_data_click_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackStage[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    1,  106,    2, 0x08,    9 /* Private */,
      12,    0,  109,    2, 0x08,   11 /* Private */,
      13,    1,  110,    2, 0x08,   12 /* Private */,
      15,    0,  113,    2, 0x08,   14 /* Private */,
      16,    0,  114,    2, 0x08,   15 /* Private */,
      17,    0,  115,    2, 0x08,   16 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BackStage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackStage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignoutSignal(); break;
        case 1: _t->on_sign_out_click_clicked(); break;
        case 2: _t->on_packet_page_select_clicked(); break;
        case 3: _t->on_user_page_select_clicked(); break;
        case 4: _t->on_packet_search_click_clicked(); break;
        case 5: _t->on_packet_search_refresh_clicked(); break;
        case 6: _t->on_user_search_click_clicked(); break;
        case 7: _t->on_user_search_refresh_clicked(); break;
        case 8: _t->option_set((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_packet_alloc_clicked(); break;
        case 10: _t->on_auto_allocation_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_user_delete_clicked(); break;
        case 12: _t->on_user_add_clicked(); break;
        case 13: _t->on_store_data_click_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackStage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackStage::SignoutSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BackStage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BackStage.offsetsAndSize,
    qt_meta_data_BackStage,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BackStage_t
, QtPrivate::TypeAndForceComplete<BackStage, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BackStage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackStage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackStage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BackStage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void BackStage::SignoutSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
