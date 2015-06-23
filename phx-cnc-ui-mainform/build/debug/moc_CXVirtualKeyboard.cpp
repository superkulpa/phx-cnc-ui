/****************************************************************************
** Meta object code from reading C++ file 'CXVirtualKeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXVirtualKeyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXVirtualKeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXVirtualKeyboard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   19,   18,   18, 0x08,
      60,   18,   18,   18, 0x08,
      76,   18,   18,   18, 0x08,
      85,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXVirtualKeyboard[] = {
    "CXVirtualKeyboard\0\0old,now\0"
    "onFocusChange(QWidget*,QWidget*)\0"
    "onButtonClick()\0onHide()\0onDelete()\0"
};

void CXVirtualKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXVirtualKeyboard *_t = static_cast<CXVirtualKeyboard *>(_o);
        switch (_id) {
        case 0: _t->onFocusChange((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->onButtonClick(); break;
        case 2: _t->onHide(); break;
        case 3: _t->onDelete(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXVirtualKeyboard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXVirtualKeyboard::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXVirtualKeyboard,
      qt_meta_data_CXVirtualKeyboard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXVirtualKeyboard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXVirtualKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXVirtualKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXVirtualKeyboard))
        return static_cast<void*>(const_cast< CXVirtualKeyboard*>(this));
    if (!strcmp(_clname, "Ui::CXVirtualKeyboard"))
        return static_cast< Ui::CXVirtualKeyboard*>(const_cast< CXVirtualKeyboard*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXVirtualKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
