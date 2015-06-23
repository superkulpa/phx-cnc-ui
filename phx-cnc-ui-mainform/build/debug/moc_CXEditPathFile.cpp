/****************************************************************************
** Meta object code from reading C++ file 'CXEditPathFile.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXEditPathFile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXEditPathFile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXEditPathFile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      42,   33,   15,   15, 0x05,
      60,   15,   15,   15, 0x25,
      74,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      96,   86,   15,   15, 0x0a,
     114,   15,   15,   15, 0x0a,
     123,   15,   15,   15, 0x0a,
     152,  134,   15,   15, 0x0a,
     173,   15,   15,   15, 0x08,
     198,   86,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXEditPathFile[] = {
    "CXEditPathFile\0\0newFileCreated()\0"
    "aIsSaved\0textChanged(bool)\0textChanged()\0"
    "statSaved()\0aFileName\0openFile(QString)\0"
    "onSave()\0onSaveAs()\0aText,aLineNumber\0"
    "onError(QString,int)\0onCursorPositionChange()\0"
    "onSaveAs(QString)\0"
};

void CXEditPathFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXEditPathFile *_t = static_cast<CXEditPathFile *>(_o);
        switch (_id) {
        case 0: _t->newFileCreated(); break;
        case 1: _t->textChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->textChanged(); break;
        case 3: _t->statSaved(); break;
        case 4: _t->openFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onSave(); break;
        case 6: _t->onSaveAs(); break;
        case 7: _t->onError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onCursorPositionChange(); break;
        case 9: _t->onSaveAs((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXEditPathFile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXEditPathFile::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXEditPathFile,
      qt_meta_data_CXEditPathFile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXEditPathFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXEditPathFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXEditPathFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXEditPathFile))
        return static_cast<void*>(const_cast< CXEditPathFile*>(this));
    if (!strcmp(_clname, "Ui::CXEditPathFile"))
        return static_cast< Ui::CXEditPathFile*>(const_cast< CXEditPathFile*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXEditPathFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CXEditPathFile::newFileCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CXEditPathFile::textChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void CXEditPathFile::statSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
