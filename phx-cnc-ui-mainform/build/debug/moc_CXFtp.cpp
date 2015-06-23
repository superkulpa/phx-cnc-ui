/****************************************************************************
** Meta object code from reading C++ file 'CXFtp.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/utils/CXFtp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXFtp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXFtp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    7,    6,    6, 0x05,
      40,    7,    6,    6, 0x05,
      72,   66,    6,    6, 0x05,
     111,  101,    6,    6, 0x05,
     134,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     157,  150,    6,    6, 0x0a,
     184,    6,    6,    6, 0x2a,
     200,  150,    6,    6, 0x0a,
     225,    6,    6,    6, 0x2a,
     246,  239,    6,    6, 0x08,
     278,  266,    6,    6, 0x08,
     313,  307,    6,    6, 0x08,
     345,  334,    6,    6, 0x08,
     383,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXFtp[] = {
    "CXFtp\0\0aMax\0progressMaximumChanged(int)\0"
    "progressValueChanged(int)\0aText\0"
    "progressTextChanged(QString)\0aIsUpload\0"
    "allFilesIsLoaded(bool)\0errorReceived()\0"
    "aFiles\0onFtpDownload(QStringList)\0"
    "onFtpDownload()\0onFtpUpload(QStringList)\0"
    "onFtpUpload()\0aState\0onStateChanged(int)\0"
    "id,aIsError\0onFtpCommandFinish(int,bool)\0"
    "aInfo\0onListInfo(QUrlInfo)\0done,total\0"
    "onDataTransferProgress(qint64,qint64)\0"
    "onReadyRead()\0"
};

void CXFtp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXFtp *_t = static_cast<CXFtp *>(_o);
        switch (_id) {
        case 0: _t->progressMaximumChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->progressValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->progressTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->allFilesIsLoaded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->errorReceived(); break;
        case 5: _t->onFtpDownload((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 6: _t->onFtpDownload(); break;
        case 7: _t->onFtpUpload((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 8: _t->onFtpUpload(); break;
        case 9: _t->onStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onFtpCommandFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->onListInfo((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 12: _t->onDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 13: _t->onReadyRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXFtp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXFtp::staticMetaObject = {
    { &QFtp::staticMetaObject, qt_meta_stringdata_CXFtp,
      qt_meta_data_CXFtp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXFtp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXFtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXFtp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXFtp))
        return static_cast<void*>(const_cast< CXFtp*>(this));
    return QFtp::qt_metacast(_clname);
}

int CXFtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFtp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CXFtp::progressMaximumChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXFtp::progressValueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CXFtp::progressTextChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CXFtp::allFilesIsLoaded(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CXFtp::errorReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
