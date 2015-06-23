/****************************************************************************
** Meta object code from reading C++ file 'CXParametersWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXParametersWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXParametersWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXParametersWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   19,   19,   19, 0x0a,
      58,   19,   19,   19, 0x0a,
      82,   19,   19,   19, 0x0a,
      99,   19,   19,   19, 0x0a,
     122,   19,   19,   19, 0x0a,
     149,  139,   19,   19, 0x0a,
     170,  164,   19,   19, 0x0a,
     205,  195,   19,   19, 0x0a,
     224,   19,   19,   19, 0x0a,
     237,   19,   19,   19, 0x0a,
     258,  252,   19,   19, 0x0a,
     281,   19,   19,   19, 0x08,
     322,  297,   19,   19, 0x08,
     380,  364,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXParametersWindow[] = {
    "CXParametersWindow\0\0_error\0"
    "uploadCompleted(int)\0onUtils()\0"
    "loadParametersFromFtp()\0loadParameters()\0"
    "saveParametersAnyway()\0saveParameters()\0"
    "aIsSystem\0makeTabs(bool)\0aText\0"
    "setProgressText(QString)\0aIsUpload\0"
    "onFtpSuccess(bool)\0onFtpError()\0"
    "showSettings()\0_tech\0setTechnology(QString)\0"
    "buttonClicked()\0aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
    "aIsUpload,files\0loadFiles(bool,QStringList)\0"
};

void CXParametersWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXParametersWindow *_t = static_cast<CXParametersWindow *>(_o);
        switch (_id) {
        case 0: _t->uploadCompleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onUtils(); break;
        case 2: _t->loadParametersFromFtp(); break;
        case 3: _t->loadParameters(); break;
        case 4: _t->saveParametersAnyway(); break;
        case 5: _t->saveParameters(); break;
        case 6: _t->makeTabs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setProgressText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onFtpSuccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->onFtpError(); break;
        case 10: _t->showSettings(); break;
        case 11: _t->setTechnology((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->buttonClicked(); break;
        case 13: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 14: _t->loadFiles((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXParametersWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXParametersWindow::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXParametersWindow,
      qt_meta_data_CXParametersWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXParametersWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXParametersWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXParametersWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXParametersWindow))
        return static_cast<void*>(const_cast< CXParametersWindow*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXParametersWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CXParametersWindow::uploadCompleted(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
