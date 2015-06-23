/****************************************************************************
** Meta object code from reading C++ file 'CXParamui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXParamui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXParamui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXParamUi[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      22,   10,   10,   10, 0x08,
      33,   10,   10,   10, 0x08,
      54,   46,   10,   10, 0x08,
      76,   10,   10,   10, 0x08,
      94,   10,   90,   10, 0x08,
     107,   10,   10,   10, 0x08,
     118,   10,   10,   10, 0x08,
     125,   10,   10,   10, 0x08,
     136,   10,   10,   10, 0x08,
     157,  154,   10,   10, 0x08,
     199,   10,   10,   10, 0x08,
     222,   10,   10,   10, 0x08,
     243,  233,   10,   10, 0x08,
     279,  257,   10,   10, 0x08,
     328,  321,   10,   10, 0x08,
     403,  367,   10,   10, 0x08,
     451,  443,   90,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXParamUi[] = {
    "CXParamUi\0\0iniSaved()\0readKeys()\0"
    "readValues()\0aLayout\0clearLayout(QLayout*)\0"
    "onKeyChange()\0int\0updateData()\0"
    "repairDB()\0save()\0launchGC()\0"
    "onButtonClicked()\0,,\0"
    "onCommandReceive(QString,QString,QString)\0"
    "onReiniCompleted(bool)\0closeFtp()\0"
    "aIsUpload\0onClose(bool)\0aExitCode,aExitStatus\0"
    "onProcessFinish(int,QProcess::ExitStatus)\0"
    "aError\0onProcessError(QProcess::ProcessError)\0"
    "aIsUpload,files,member_onFtpSuccess\0"
    "loadFiles(bool,QStringList,const char*)\0"
    "_values\0executeDB(QString)\0"
};

void CXParamUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXParamUi *_t = static_cast<CXParamUi *>(_o);
        switch (_id) {
        case 0: _t->iniSaved(); break;
        case 1: _t->readKeys(); break;
        case 2: _t->readValues(); break;
        case 3: _t->clearLayout((*reinterpret_cast< QLayout*(*)>(_a[1]))); break;
        case 4: _t->onKeyChange(); break;
        case 5: { int _r = _t->updateData();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: _t->repairDB(); break;
        case 7: _t->save(); break;
        case 8: _t->launchGC(); break;
        case 9: _t->onButtonClicked(); break;
        case 10: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 11: _t->onReiniCompleted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->closeFtp(); break;
        case 13: _t->onClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->onProcessFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 15: _t->onProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 16: _t->loadFiles((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3]))); break;
        case 17: { int _r = _t->executeDB((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXParamUi::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXParamUi::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXParamUi,
      qt_meta_data_CXParamUi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXParamUi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXParamUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXParamUi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXParamUi))
        return static_cast<void*>(const_cast< CXParamUi*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXParamUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void CXParamUi::iniSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
