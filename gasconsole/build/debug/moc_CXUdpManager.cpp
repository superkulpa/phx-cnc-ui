/****************************************************************************
** Meta object code from reading C++ file 'CXUdpManager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXUdpManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXUdpManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXUdpManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      39,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,   13,   13,   13, 0x08,
      99,   94,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXUdpManager[] = {
    "CXUdpManager\0\0aSection,aCommand,aValue\0"
    "commandReceived(QString,QString,QString)\0"
    "onReadyRead()\0_cmd\0onEchoCmd(QString)\0"
};

void CXUdpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXUdpManager *_t = static_cast<CXUdpManager *>(_o);
        switch (_id) {
        case 0: _t->commandReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->onReadyRead(); break;
        case 2: _t->onEchoCmd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXUdpManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXUdpManager::staticMetaObject = {
    { &QUdpSocket::staticMetaObject, qt_meta_stringdata_CXUdpManager,
      qt_meta_data_CXUdpManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXUdpManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXUdpManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXUdpManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXUdpManager))
        return static_cast<void*>(const_cast< CXUdpManager*>(this));
    return QUdpSocket::qt_metacast(_clname);
}

int CXUdpManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QUdpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CXUdpManager::commandReceived(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
