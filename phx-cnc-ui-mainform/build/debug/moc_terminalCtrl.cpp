/****************************************************************************
** Meta object code from reading C++ file 'terminalCtrl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/terminalCtrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terminalCtrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CTerminalCntrl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CTerminalCntrl[] = {
    "CTerminalCntrl\0\0finished()\0onStart()\0"
};

void CTerminalCntrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CTerminalCntrl *_t = static_cast<CTerminalCntrl *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->onStart(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CTerminalCntrl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CTerminalCntrl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CTerminalCntrl,
      qt_meta_data_CTerminalCntrl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CTerminalCntrl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CTerminalCntrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CTerminalCntrl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CTerminalCntrl))
        return static_cast<void*>(const_cast< CTerminalCntrl*>(this));
    return QObject::qt_metacast(_clname);
}

int CTerminalCntrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CTerminalCntrl::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
