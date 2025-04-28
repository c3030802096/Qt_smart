/****************************************************************************
** Meta object code from reading C++ file 'device_ac.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myServer/device/device_ac.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device_ac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceAC_t {
    QByteArrayData data[14];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceAC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceAC_t qt_meta_stringdata_DeviceAC = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DeviceAC"
QT_MOC_LITERAL(1, 9, 12), // "sig_sendData"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "sockID"
QT_MOC_LITERAL(4, 30, 8), // "sendData"
QT_MOC_LITERAL(5, 39, 24), // "slot_temp_value_channged"
QT_MOC_LITERAL(6, 64, 12), // "currentValue"
QT_MOC_LITERAL(7, 77, 19), // "on_btn_mode_clicked"
QT_MOC_LITERAL(8, 97, 19), // "on_btn_wind_clicked"
QT_MOC_LITERAL(9, 117, 24), // "on_btn_wind_back_clicked"
QT_MOC_LITERAL(10, 142, 24), // "on_btn_mode_back_clicked"
QT_MOC_LITERAL(11, 167, 14), // "slot_btn_click"
QT_MOC_LITERAL(12, 182, 15), // "slot_slider_OFF"
QT_MOC_LITERAL(13, 198, 14) // "slot_slider_ON"

    },
    "DeviceAC\0sig_sendData\0\0sockID\0sendData\0"
    "slot_temp_value_channged\0currentValue\0"
    "on_btn_mode_clicked\0on_btn_wind_clicked\0"
    "on_btn_wind_back_clicked\0"
    "on_btn_mode_back_clicked\0slot_btn_click\0"
    "slot_slider_OFF\0slot_slider_ON"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceAC[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   64,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeviceAC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceAC *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_sendData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slot_temp_value_channged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btn_mode_clicked(); break;
        case 3: _t->on_btn_wind_clicked(); break;
        case 4: _t->on_btn_wind_back_clicked(); break;
        case 5: _t->on_btn_mode_back_clicked(); break;
        case 6: _t->slot_btn_click(); break;
        case 7: _t->slot_slider_OFF(); break;
        case 8: _t->slot_slider_ON(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceAC::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceAC::sig_sendData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceAC::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_DeviceAC.data,
    qt_meta_data_DeviceAC,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceAC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceAC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceAC.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DeviceAC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DeviceAC::sig_sendData(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
