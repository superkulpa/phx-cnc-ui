/****************************************************************************
** Meta object code from reading C++ file 'CXAdditionalOperDirectionWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXAdditionalOperDirectionWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXAdditionalOperDirectionWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXAdditionalOperDirectionWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   32,   32,   32, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   32,   32,   32, 0x0a,
      61,   32,   32,   32, 0x0a,
      77,   32,   32,   32, 0x0a,
      95,   32,   32,   32, 0x0a,
     115,   32,   32,   32, 0x0a,
     154,  132,   32,   32, 0x0a,
     224,  199,   32,   32, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CXAdditionalOperDirectionWindow[] = {
    "CXAdditionalOperDirectionWindow\0\0"
    "backWindow()\0onBackWindow()\0onBlockFollow()\0"
    "onStartKeyboard()\0onComporativeMove()\0"
    "onAbsoluteMove()\0aExitCode,aExitStatus\0"
    "onKeyboardFinished(int,QProcess::ExitStatus)\0"
    "aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
};

void CXAdditionalOperDirectionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXAdditionalOperDirectionWindow *_t = static_cast<CXAdditionalOperDirectionWindow *>(_o);
        switch (_id) {
        case 0: _t->backWindow(); break;
        case 1: _t->onBackWindow(); break;
        case 2: _t->onBlockFollow(); break;
        case 3: _t->onStartKeyboard(); break;
        case 4: _t->onComporativeMove(); break;
        case 5: _t->onAbsoluteMove(); break;
        case 6: _t->onKeyboardFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXAdditionalOperDirectionWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXAdditionalOperDirectionWindow::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXAdditionalOperDirectionWindow,
      qt_meta_data_CXAdditionalOperDirectionWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXAdditionalOperDirectionWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXAdditionalOperDirectionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXAdditionalOperDirectionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXAdditionalOperDirectionWindow))
        return static_cast<void*>(const_cast< CXAdditionalOperDirectionWindow*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXAdditionalOperDirectionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CXAdditionalOperDirectionWindow::backWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
