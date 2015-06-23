/****************************************************************************
** Meta object code from reading C++ file 'CXPathWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXPathWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXPathWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXPathWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   14,   13,   13, 0x0a,
      73,   56,   13,   13, 0x0a,
      99,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CXPathWindow[] = {
    "CXPathWindow\0\0aMainFile,aMoveFile\0"
    "load(QString,QString)\0aPos,aIsAbsolute\0"
    "setPosition(QPointF,bool)\0onMaximize()\0"
};

void CXPathWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXPathWindow *_t = static_cast<CXPathWindow *>(_o);
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->setPosition((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->onMaximize(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXPathWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXPathWindow::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXPathWindow,
      qt_meta_data_CXPathWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXPathWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXPathWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXPathWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXPathWindow))
        return static_cast<void*>(const_cast< CXPathWindow*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXPathWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
