/****************************************************************************
** Meta object code from reading C++ file 'AXBaseWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/AXBaseWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AXBaseWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AXBaseWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   14,   13,   13, 0x05,
      62,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_AXBaseWindow[] = {
    "AXBaseWindow\0\0aNewRect,aIsResized\0"
    "geometryChanged(QRect,bool)\0closed()\0"
};

void AXBaseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AXBaseWindow *_t = static_cast<AXBaseWindow *>(_o);
        switch (_id) {
        case 0: _t->geometryChanged((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->closed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AXBaseWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AXBaseWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AXBaseWindow,
      qt_meta_data_AXBaseWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AXBaseWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AXBaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AXBaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AXBaseWindow))
        return static_cast<void*>(const_cast< AXBaseWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int AXBaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AXBaseWindow::geometryChanged(const QRect & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AXBaseWindow::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
