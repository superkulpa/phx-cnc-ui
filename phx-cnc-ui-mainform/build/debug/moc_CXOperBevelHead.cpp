/****************************************************************************
** Meta object code from reading C++ file 'CXOperBevelHead.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXOperBevelHead.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXOperBevelHead.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXOperBevelHead[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   16,   16,   16, 0x08,
      48,   16,   16,   16, 0x08,
      88,   63,   16,   16, 0x08,
     130,   16,   16,   16, 0x08,
     147,   16,   16,   16, 0x08,
     164,   16,   16,   16, 0x08,
     182,   16,   16,   16, 0x08,
     202,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXOperBevelHead[] = {
    "CXOperBevelHead\0\0nextWindow()\0"
    "onButtonClicked()\0onNextWindow()\0"
    "aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
    "onAMoveClicked()\0onCMoveClicked()\0"
    "onToZeroClicked()\0onLockZeroClicked()\0"
    "onBlockMoveClicked()\0"
};

void CXOperBevelHead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXOperBevelHead *_t = static_cast<CXOperBevelHead *>(_o);
        switch (_id) {
        case 0: _t->nextWindow(); break;
        case 1: _t->onButtonClicked(); break;
        case 2: _t->onNextWindow(); break;
        case 3: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->onAMoveClicked(); break;
        case 5: _t->onCMoveClicked(); break;
        case 6: _t->onToZeroClicked(); break;
        case 7: _t->onLockZeroClicked(); break;
        case 8: _t->onBlockMoveClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXOperBevelHead::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXOperBevelHead::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXOperBevelHead,
      qt_meta_data_CXOperBevelHead, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXOperBevelHead::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXOperBevelHead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXOperBevelHead::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXOperBevelHead))
        return static_cast<void*>(const_cast< CXOperBevelHead*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXOperBevelHead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CXOperBevelHead::nextWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
