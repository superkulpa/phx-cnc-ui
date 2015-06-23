/****************************************************************************
** Meta object code from reading C++ file 'CXOperTechnology.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXOperTechnology.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXOperTechnology.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXOperTechnology[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   17,   17,   17, 0x08,
      72,   17,   17,   17, 0x08,
      83,   17,   17,   17, 0x08,
      95,   17,   17,   17, 0x08,
     105,   17,   17,   17, 0x08,
     114,   17,   17,   17, 0x08,
     122,   17,   17,   17, 0x08,
     137,   17,   17,   17, 0x08,
     174,  149,   17,   17, 0x08,
     216,   17,   17,   17, 0x08,
     232,   17,   17,   17, 0x08,
     253,   17,   17,   17, 0x08,
     284,  269,   17,   17, 0x08,
     310,   18,   17,   17, 0x08,
     334,   17,   17,   17, 0x08,
     342,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXOperTechnology[] = {
    "CXOperTechnology\0\0_tech\0"
    "eventTechnologyChanged(QString)\0"
    "OnTechConsole()\0onTClick()\0onZHClick()\0"
    "onStart()\0onStop()\0onSVR()\0onMarkerMode()\0"
    "onCutMode()\0aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
    "onButtonCheck()\0onTechnologyButton()\0"
    "onZTypeButton()\0_continueBreak\0"
    "onWarmUpConinueBreak(int)\0"
    "onTechDlgClose(QString)\0onZUp()\0"
    "onZDown()\0"
};

void CXOperTechnology::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXOperTechnology *_t = static_cast<CXOperTechnology *>(_o);
        switch (_id) {
        case 0: _t->eventTechnologyChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->OnTechConsole(); break;
        case 2: _t->onTClick(); break;
        case 3: _t->onZHClick(); break;
        case 4: _t->onStart(); break;
        case 5: _t->onStop(); break;
        case 6: _t->onSVR(); break;
        case 7: _t->onMarkerMode(); break;
        case 8: _t->onCutMode(); break;
        case 9: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->onButtonCheck(); break;
        case 11: _t->onTechnologyButton(); break;
        case 12: _t->onZTypeButton(); break;
        case 13: _t->onWarmUpConinueBreak((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->onTechDlgClose((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->onZUp(); break;
        case 16: _t->onZDown(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXOperTechnology::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXOperTechnology::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXOperTechnology,
      qt_meta_data_CXOperTechnology, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXOperTechnology::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXOperTechnology::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXOperTechnology::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXOperTechnology))
        return static_cast<void*>(const_cast< CXOperTechnology*>(this));
    if (!strcmp(_clname, "Ui::CXOperTechnology"))
        return static_cast< Ui::CXOperTechnology*>(const_cast< CXOperTechnology*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXOperTechnology::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void CXOperTechnology::eventTechnologyChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
