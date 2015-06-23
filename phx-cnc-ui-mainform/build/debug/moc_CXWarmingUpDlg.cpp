/****************************************************************************
** Meta object code from reading C++ file 'CXWarmingUpDlg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXWarmingUpDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXWarmingUpDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXWarmingUpDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   16,   15,   15, 0x05,
      55,   47,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   15,   15,   15, 0x08,
      93,   15,   15,   15, 0x08,
     116,   15,   15,   15, 0x08,
     138,   16,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXWarmingUpDlg[] = {
    "CXWarmingUpDlg\0\0_percent\0postStateWaiting(int)\0"
    "_action\0postCmdWaiting(int)\0"
    "onButtonClicked()\0onButtonClickedBreak()\0"
    "onButtonClickedStop()\0onWarmProcess(int)\0"
};

void CXWarmingUpDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXWarmingUpDlg *_t = static_cast<CXWarmingUpDlg *>(_o);
        switch (_id) {
        case 0: _t->postStateWaiting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->postCmdWaiting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onButtonClicked(); break;
        case 3: _t->onButtonClickedBreak(); break;
        case 4: _t->onButtonClickedStop(); break;
        case 5: _t->onWarmProcess((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXWarmingUpDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXWarmingUpDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CXWarmingUpDlg,
      qt_meta_data_CXWarmingUpDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXWarmingUpDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXWarmingUpDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXWarmingUpDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXWarmingUpDlg))
        return static_cast<void*>(const_cast< CXWarmingUpDlg*>(this));
    if (!strcmp(_clname, "Ui::WarmingUp"))
        return static_cast< Ui::WarmingUp*>(const_cast< CXWarmingUpDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CXWarmingUpDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CXWarmingUpDlg::postStateWaiting(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXWarmingUpDlg::postCmdWaiting(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
