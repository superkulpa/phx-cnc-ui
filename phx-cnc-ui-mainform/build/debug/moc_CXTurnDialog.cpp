/****************************************************************************
** Meta object code from reading C++ file 'CXTurnDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXTurnDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXTurnDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXTurnDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   13,   13,   13, 0x08,
      48,   13,   13,   13, 0x08,
      66,   13,   13,   13, 0x08,
      88,   13,   13,   13, 0x08,
     103,   13,   13,   13, 0x08,
     118,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXTurnDialog[] = {
    "CXTurnDialog\0\0compileNeeded()\0"
    "onButtonClicked()\0onWriteRotation()\0"
    "onCalculateRotation()\0onWriteFlipX()\0"
    "onWriteFlipY()\0onWriteScale()\0"
};

void CXTurnDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXTurnDialog *_t = static_cast<CXTurnDialog *>(_o);
        switch (_id) {
        case 0: _t->compileNeeded(); break;
        case 1: _t->onButtonClicked(); break;
        case 2: _t->onWriteRotation(); break;
        case 3: _t->onCalculateRotation(); break;
        case 4: _t->onWriteFlipX(); break;
        case 5: _t->onWriteFlipY(); break;
        case 6: _t->onWriteScale(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CXTurnDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXTurnDialog::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXTurnDialog,
      qt_meta_data_CXTurnDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXTurnDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXTurnDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXTurnDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXTurnDialog))
        return static_cast<void*>(const_cast< CXTurnDialog*>(this));
    if (!strcmp(_clname, "Ui::CXTurnDialog"))
        return static_cast< Ui::CXTurnDialog*>(const_cast< CXTurnDialog*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXTurnDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CXTurnDialog::compileNeeded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
