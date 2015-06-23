/****************************************************************************
** Meta object code from reading C++ file 'CXWindowsManager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXWindowsManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXWindowsManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXWindowsManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   18,   17,   17, 0x0a,
      75,   65,   17,   17, 0x0a,
      91,   17,   17,   17, 0x0a,
     122,   17,   17,   17, 0x0a,
     181,  157,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXWindowsManager[] = {
    "CXWindowsManager\0\0,\0"
    "onKeyboardFinished(int,QProcess::ExitStatus)\0"
    "aIsFreeze\0setFreeze(bool)\0"
    "changeVisibleVirtualKeyboard()\0"
    "changeVisibleVirtualKeyboardNum0()\0"
    "aNewGeometry,aIsResized\0"
    "windowGeometryChange(QRect,bool)\0"
};

void CXWindowsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXWindowsManager *_t = static_cast<CXWindowsManager *>(_o);
        switch (_id) {
        case 0: _t->onKeyboardFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 1: _t->setFreeze((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->changeVisibleVirtualKeyboard(); break;
        case 3: _t->changeVisibleVirtualKeyboardNum0(); break;
        case 4: _t->windowGeometryChange((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXWindowsManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXWindowsManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CXWindowsManager,
      qt_meta_data_CXWindowsManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXWindowsManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXWindowsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXWindowsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXWindowsManager))
        return static_cast<void*>(const_cast< CXWindowsManager*>(this));
    return QObject::qt_metacast(_clname);
}

int CXWindowsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
