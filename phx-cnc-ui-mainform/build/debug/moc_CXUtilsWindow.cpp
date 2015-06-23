/****************************************************************************
** Meta object code from reading C++ file 'CXUtilsWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXUtilsWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXUtilsWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXUtilsWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      49,   27,   14,   14, 0x08,
      98,   91,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXUtilsWindow[] = {
    "CXUtilsWindow\0\0onExecute()\0"
    "aExitCode,aExitStatus\0"
    "onProcessFinish(int,QProcess::ExitStatus)\0"
    "aError\0onProcessError(QProcess::ProcessError)\0"
};

void CXUtilsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXUtilsWindow *_t = static_cast<CXUtilsWindow *>(_o);
        switch (_id) {
        case 0: _t->onExecute(); break;
        case 1: _t->onProcessFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 2: _t->onProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXUtilsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXUtilsWindow::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXUtilsWindow,
      qt_meta_data_CXUtilsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXUtilsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXUtilsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXUtilsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXUtilsWindow))
        return static_cast<void*>(const_cast< CXUtilsWindow*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXUtilsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
