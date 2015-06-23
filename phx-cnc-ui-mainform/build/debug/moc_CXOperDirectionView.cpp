/****************************************************************************
** Meta object code from reading C++ file 'CXOperDirectionView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXOperDirectionView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXOperDirectionView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXOperDirectionView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   21,   20,   20, 0x05,
     105,   84,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CXOperDirectionView[] = {
    "CXOperDirectionView\0\0aDirection\0"
    "directionChanged(OperDirectionView::eMoveDirection)\0"
    "aDirection,aVelocity\0"
    "directionChanged(OperDirectionView::eMoveDirection,eVelocity)\0"
};

void CXOperDirectionView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXOperDirectionView *_t = static_cast<CXOperDirectionView *>(_o);
        switch (_id) {
        case 0: _t->directionChanged((*reinterpret_cast< OperDirectionView::eMoveDirection(*)>(_a[1]))); break;
        case 1: _t->directionChanged((*reinterpret_cast< OperDirectionView::eMoveDirection(*)>(_a[1])),(*reinterpret_cast< eVelocity(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXOperDirectionView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXOperDirectionView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CXOperDirectionView,
      qt_meta_data_CXOperDirectionView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXOperDirectionView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXOperDirectionView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXOperDirectionView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXOperDirectionView))
        return static_cast<void*>(const_cast< CXOperDirectionView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CXOperDirectionView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CXOperDirectionView::directionChanged(OperDirectionView::eMoveDirection _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXOperDirectionView::directionChanged(OperDirectionView::eMoveDirection _t1, eVelocity _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
