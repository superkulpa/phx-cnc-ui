/****************************************************************************
** Meta object code from reading C++ file 'CXOperDirectionWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXOperDirectionWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXOperDirectionWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXOperDirectionWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      40,   23,   22,   22, 0x05,
      72,   70,   22,   22, 0x05,
     104,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,   22,   22,   22, 0x0a,
     138,   22,   22,   22, 0x08,
     148,   22,   22,   22, 0x08,
     157,   22,   22,   22, 0x08,
     169,   22,   22,   22, 0x08,
     199,  188,  180,   22, 0x08,
     254,  188,   22,   22, 0x08,
     328,  307,   22,   22, 0x08,
     401,  391,   22,   22, 0x08,
     429,   22,   22,   22, 0x08,
     441,   22,   22,   22, 0x08,
     455,   22,   22,   22, 0x08,
     470,   22,   22,   22, 0x08,
     510,  485,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXOperDirectionWindow[] = {
    "CXOperDirectionWindow\0\0aPos,aIsAbsolute\0"
    "positionChanged(QPointF,bool)\0,\0"
    "paramsChanged(bool,QStringList)\0"
    "nextWindow()\0onResetCoordinates()\0"
    "onStart()\0onStop()\0onXYClick()\0"
    "onFClick()\0QString\0aDirection\0"
    "getDirectionCommand(OperDirectionView::eMoveDirection)\0"
    "onDirectionChange(OperDirectionView::eMoveDirection)\0"
    "aDirection,aVelocity\0"
    "onDirectionChange(OperDirectionView::eMoveDirection,eVelocity)\0"
    "aVelocity\0onVelocityChange(eVelocity)\0"
    "onUpSpeed()\0onDownSpeed()\0onModeChange()\0"
    "onNextWindow()\0aSection,aCommand,aValue\0"
    "onCommandReceive(QString,QString,QString)\0"
};

void CXOperDirectionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXOperDirectionWindow *_t = static_cast<CXOperDirectionWindow *>(_o);
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->paramsChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 2: _t->nextWindow(); break;
        case 3: _t->onResetCoordinates(); break;
        case 4: _t->onStart(); break;
        case 5: _t->onStop(); break;
        case 6: _t->onXYClick(); break;
        case 7: _t->onFClick(); break;
        case 8: { QString _r = _t->getDirectionCommand((*reinterpret_cast< OperDirectionView::eMoveDirection(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: _t->onDirectionChange((*reinterpret_cast< OperDirectionView::eMoveDirection(*)>(_a[1]))); break;
        case 10: _t->onDirectionChange((*reinterpret_cast< OperDirectionView::eMoveDirection(*)>(_a[1])),(*reinterpret_cast< eVelocity(*)>(_a[2]))); break;
        case 11: _t->onVelocityChange((*reinterpret_cast< eVelocity(*)>(_a[1]))); break;
        case 12: _t->onUpSpeed(); break;
        case 13: _t->onDownSpeed(); break;
        case 14: _t->onModeChange(); break;
        case 15: _t->onNextWindow(); break;
        case 16: _t->onCommandReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXOperDirectionWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXOperDirectionWindow::staticMetaObject = {
    { &AXBaseWindow::staticMetaObject, qt_meta_stringdata_CXOperDirectionWindow,
      qt_meta_data_CXOperDirectionWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXOperDirectionWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXOperDirectionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXOperDirectionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXOperDirectionWindow))
        return static_cast<void*>(const_cast< CXOperDirectionWindow*>(this));
    return AXBaseWindow::qt_metacast(_clname);
}

int CXOperDirectionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AXBaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void CXOperDirectionWindow::positionChanged(const QPointF & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CXOperDirectionWindow::paramsChanged(bool _t1, const QStringList & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CXOperDirectionWindow::nextWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
