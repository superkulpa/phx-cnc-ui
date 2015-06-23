/****************************************************************************
** Meta object code from reading C++ file 'CXOperDirectionDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXOperDirectionDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXOperDirectionDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXOperDirectionDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      36,   22,   22,   22, 0x08,
      49,   22,   22,   22, 0x08,
      67,   22,   22,   22, 0x08,
      80,   22,   22,   22, 0x08,
      92,   22,   22,   22, 0x08,
     105,   22,   22,   22, 0x08,
     117,   22,   22,   22, 0x08,
     135,   22,   22,   22, 0x08,
     152,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXOperDirectionDialog[] = {
    "CXOperDirectionDialog\0\0onAbsolute()\0"
    "onRelative()\0onButtonClicked()\0"
    "onStepMove()\0onStepSet()\0onBurnMove()\0"
    "onBurnSet()\0onTechPointMove()\0"
    "onSetTechPoint()\0onAbsZeroMove()\0"
};

void CXOperDirectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXOperDirectionDialog *_t = static_cast<CXOperDirectionDialog *>(_o);
        switch (_id) {
        case 0: _t->onAbsolute(); break;
        case 1: _t->onRelative(); break;
        case 2: _t->onButtonClicked(); break;
        case 3: _t->onStepMove(); break;
        case 4: _t->onStepSet(); break;
        case 5: _t->onBurnMove(); break;
        case 6: _t->onBurnSet(); break;
        case 7: _t->onTechPointMove(); break;
        case 8: _t->onSetTechPoint(); break;
        case 9: _t->onAbsZeroMove(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CXOperDirectionDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXOperDirectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CXOperDirectionDialog,
      qt_meta_data_CXOperDirectionDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXOperDirectionDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXOperDirectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXOperDirectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXOperDirectionDialog))
        return static_cast<void*>(const_cast< CXOperDirectionDialog*>(this));
    if (!strcmp(_clname, "Ui::CXOperDirectionDialog"))
        return static_cast< Ui::CXOperDirectionDialog*>(const_cast< CXOperDirectionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CXOperDirectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
