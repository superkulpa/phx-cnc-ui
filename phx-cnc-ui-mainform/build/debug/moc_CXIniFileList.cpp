/****************************************************************************
** Meta object code from reading C++ file 'CXIniFileList.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXIniFileList.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXIniFileList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXIniFileList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x05,
      45,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   14,   14,   14, 0x0a,
      70,   14,   14,   14, 0x0a,
      83,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CXIniFileList[] = {
    "CXIniFileList\0\0aFileName\0fileOpened(QString)\0"
    "fileSaved()\0onOpenFile()\0onDownList()\0"
    "onUpList()\0"
};

void CXIniFileList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXIniFileList *_t = static_cast<CXIniFileList *>(_o);
        switch (_id) {
        case 0: _t->fileOpened((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->fileSaved(); break;
        case 2: _t->onOpenFile(); break;
        case 3: _t->onDownList(); break;
        case 4: _t->onUpList(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXIniFileList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXIniFileList::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXIniFileList,
      qt_meta_data_CXIniFileList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXIniFileList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXIniFileList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXIniFileList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXIniFileList))
        return static_cast<void*>(const_cast< CXIniFileList*>(this));
    if (!strcmp(_clname, "Ui::CXIniFileList"))
        return static_cast< Ui::CXIniFileList*>(const_cast< CXIniFileList*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXIniFileList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CXIniFileList::fileOpened(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXIniFileList::fileSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
