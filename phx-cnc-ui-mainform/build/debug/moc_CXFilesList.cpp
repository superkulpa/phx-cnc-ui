/****************************************************************************
** Meta object code from reading C++ file 'CXFilesList.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXFilesList.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXFilesList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXFilesList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   13,   12,   12, 0x05,
      63,   43,   12,   12, 0x05,
      92,   43,   12,   12, 0x05,
     127,   13,   12,   12, 0x05,
     152,  146,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     180,   12,   12,   12, 0x0a,
     206,  198,   12,   12, 0x0a,
     230,   12,   12,   12, 0x0a,
     239,   12,   12,   12, 0x0a,
     252,   12,   12,   12, 0x08,
     280,   12,   12,   12, 0x08,
     291,   12,   12,   12, 0x08,
     304,   12,   12,   12, 0x08,
     315,   12,   12,   12, 0x08,
     324,   12,   12,   12, 0x08,
     361,  344,   12,   12, 0x08,
     415,   12,  403,   12, 0x08,
     446,  439,   12,   12, 0x08,
     465,   12,   12,   12, 0x28,
     481,   12,   12,   12, 0x08,
     508,  499,   12,   12, 0x08,
     550,  528,   12,   12, 0x08,
     599,  592,   12,   12, 0x08,
     661,  646,  638,   12, 0x08,
     689,   12,   12,   12, 0x08,
     700,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXFilesList[] = {
    "CXFilesList\0\0aFileName\0fileOpened(QString)\0"
    "aMainFile,aMoveFile\0fileCreated(QString,QString)\0"
    "fileManageCreated(QString,QString)\0"
    "fileSaved(QString)\0aText\0"
    "compileTextChanged(QString)\0"
    "onCreateNewFile()\0aButton\0"
    "setButton(QPushButton*)\0onTurn()\0"
    "onStatSave()\0onItemActivate(QModelIndex)\0"
    "onReturn()\0onDownList()\0onUpList()\0"
    "onOpen()\0onDirectoryLoaded()\0"
    "current,previous\0"
    "onCurrentChanged(QModelIndex,QModelIndex)\0"
    "QModelIndex\0setCurrentItemToFirst()\0"
    "_clear\0onCompileFile(int)\0onCompileFile()\0"
    "onLoadCheckFile()\0aIsSaved\0"
    "onTextChanged(bool)\0aExitCode,aExitStatus\0"
    "onProcessFinish(int,QProcess::ExitStatus)\0"
    "aError\0onProcessError(QProcess::ProcessError)\0"
    "QString\0aAttributeName\0"
    "getConfigAttribute(QString)\0onAccept()\0"
    "onSave()\0"
};

void CXFilesList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXFilesList *_t = static_cast<CXFilesList *>(_o);
        switch (_id) {
        case 0: _t->fileOpened((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->fileCreated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->fileManageCreated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->fileSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->compileTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onCreateNewFile(); break;
        case 6: _t->setButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 7: _t->onTurn(); break;
        case 8: _t->onStatSave(); break;
        case 9: _t->onItemActivate((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->onReturn(); break;
        case 11: _t->onDownList(); break;
        case 12: _t->onUpList(); break;
        case 13: _t->onOpen(); break;
        case 14: _t->onDirectoryLoaded(); break;
        case 15: _t->onCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 16: { QModelIndex _r = _t->setCurrentItemToFirst();
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = _r; }  break;
        case 17: _t->onCompileFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->onCompileFile(); break;
        case 19: _t->onLoadCheckFile(); break;
        case 20: _t->onTextChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->onProcessFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 22: _t->onProcessError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 23: { QString _r = _t->getConfigAttribute((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 24: _t->onAccept(); break;
        case 25: _t->onSave(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXFilesList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXFilesList::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXFilesList,
      qt_meta_data_CXFilesList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXFilesList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXFilesList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXFilesList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXFilesList))
        return static_cast<void*>(const_cast< CXFilesList*>(this));
    if (!strcmp(_clname, "Ui::CXFilesList"))
        return static_cast< Ui::CXFilesList*>(const_cast< CXFilesList*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXFilesList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void CXFilesList::fileOpened(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXFilesList::fileCreated(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CXFilesList::fileManageCreated(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CXFilesList::fileSaved(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CXFilesList::compileTextChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
