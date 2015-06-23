/****************************************************************************
** Meta object code from reading C++ file 'CXTitleWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXTitleWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXTitleWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXTitleWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x0a,
      52,   45,   14,   14, 0x0a,
      76,   14,   14,   14, 0x08,
      88,   14,   14,   14, 0x08,
     104,   14,   14,   14, 0x08,
     147,  122,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXTitleWindow[] = {
    "CXTitleWindow\0\0aFileName\0onFileOpen(QString)\0"
    "aError\0onErrorReceive(QString)\0"
    "onControl()\0onBlockLimits()\0"
    "onStopOperation()\0aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
};

void CXTitleWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXTitleWindow *_t = static_cast<CXTitleWindow *>(_o);
        switch (_id) {
        case 0: _t->onFileOpen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onErrorReceive((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onControl(); break;
        case 3: _t->onBlockLimits(); break;
        case 4: _t->onStopOperation(); break;
        case 5: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXTitleWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXTitleWindow::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXTitleWindow,
      qt_meta_data_CXTitleWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXTitleWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXTitleWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXTitleWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXTitleWindow))
        return static_cast<void*>(const_cast< CXTitleWindow*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXTitleWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
