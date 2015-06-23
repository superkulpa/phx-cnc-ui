/****************************************************************************
** Meta object code from reading C++ file 'CXGroupPanel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXGroupPanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXGroupPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXGroupPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      25,   13,   13,   13, 0x0a,
      44,   13,   13,   13, 0x0a,
      59,   13,   13,   13, 0x0a,
      75,   13,   13,   13, 0x0a,
      84,   13,   13,   13, 0x0a,
     103,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CXGroupPanel[] = {
    "CXGroupPanel\0\0setGroup()\0directoryCommand()\0"
    "macroCommand()\0macroCommand2()\0onExit()\0"
    "onDeviceEditShow()\0onDeviceEditHide()\0"
};

void CXGroupPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXGroupPanel *_t = static_cast<CXGroupPanel *>(_o);
        switch (_id) {
        case 0: _t->setGroup(); break;
        case 1: _t->directoryCommand(); break;
        case 2: _t->macroCommand(); break;
        case 3: _t->macroCommand2(); break;
        case 4: _t->onExit(); break;
        case 5: _t->onDeviceEditShow(); break;
        case 6: _t->onDeviceEditHide(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CXGroupPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXGroupPanel::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXGroupPanel,
      qt_meta_data_CXGroupPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXGroupPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXGroupPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXGroupPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXGroupPanel))
        return static_cast<void*>(const_cast< CXGroupPanel*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXGroupPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
