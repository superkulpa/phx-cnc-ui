/****************************************************************************
** Meta object code from reading C++ file 'CXIniFileEditor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXIniFileEditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXIniFileEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXIniFileEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      41,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   53,   16,   16, 0x0a,
      83,   16,   16,   16, 0x0a,
      92,   16,   16,   16, 0x0a,
     106,   16,   16,   16, 0x0a,
     134,   16,   16,   16, 0x0a,
     147,   16,   16,   16, 0x0a,
     160,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CXIniFileEditor[] = {
    "CXIniFileEditor\0\0fileOpened(QModelIndex)\0"
    "fileSaved()\0aFileName\0onOpenFile(QString)\0"
    "onSave()\0reloadFiles()\0"
    "onItemActivate(QModelIndex)\0onOpenFile()\0"
    "onDownList()\0onUpList()\0"
};

void CXIniFileEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXIniFileEditor *_t = static_cast<CXIniFileEditor *>(_o);
        switch (_id) {
        case 0: _t->fileOpened((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->fileSaved(); break;
        case 2: _t->onOpenFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onSave(); break;
        case 4: _t->reloadFiles(); break;
        case 5: _t->onItemActivate((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->onOpenFile(); break;
        case 7: _t->onDownList(); break;
        case 8: _t->onUpList(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXIniFileEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXIniFileEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CXIniFileEditor,
      qt_meta_data_CXIniFileEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXIniFileEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXIniFileEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXIniFileEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXIniFileEditor))
        return static_cast<void*>(const_cast< CXIniFileEditor*>(this));
    if (!strcmp(_clname, "Ui::CXIniFileEditor"))
        return static_cast< Ui::CXIniFileEditor*>(const_cast< CXIniFileEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int CXIniFileEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CXIniFileEditor::fileOpened(const QModelIndex & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXIniFileEditor::fileSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
