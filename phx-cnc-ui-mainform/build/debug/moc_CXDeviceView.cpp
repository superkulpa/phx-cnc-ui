/****************************************************************************
** Meta object code from reading C++ file 'CXDeviceView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXDeviceView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXDeviceView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXDeviceView[] = {

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
      22,   14,   13,   13, 0x08,
      75,   55,   13,   13, 0x08,
     103,   13,   13,   13, 0x08,
     116,   13,   13,   13, 0x08,
     139,  130,   13,   13, 0x08,
     187,  162,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXDeviceView[] = {
    "CXDeviceView\0\0old,now\0"
    "onFocusChange(QWidget*,QWidget*)\0"
    "aIndex,aDescription\0setDescription(int,QString)\0"
    "editDevice()\0editChannel()\0aCommand\0"
    "onSendCommand(QString)\0aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
};

void CXDeviceView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXDeviceView *_t = static_cast<CXDeviceView *>(_o);
        switch (_id) {
        case 0: _t->onFocusChange((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->setDescription((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->editDevice(); break;
        case 3: _t->editChannel(); break;
        case 4: _t->onSendCommand((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXDeviceView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXDeviceView::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXDeviceView,
      qt_meta_data_CXDeviceView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXDeviceView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXDeviceView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXDeviceView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXDeviceView))
        return static_cast<void*>(const_cast< CXDeviceView*>(this));
    if (!strcmp(_clname, "Ui::CXDeviceView"))
        return static_cast< Ui::CXDeviceView*>(const_cast< CXDeviceView*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXDeviceView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
