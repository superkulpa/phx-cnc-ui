/****************************************************************************
** Meta object code from reading C++ file 'CXPathView.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXPathView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXPathView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXPathView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   12,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,
      75,   11,   11,   11, 0x0a,
      96,   85,   11,   11, 0x0a,
     138,  121,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CXPathView[] = {
    "CXPathView\0\0aMainFile,aMoveFile\0"
    "load(QString,QString)\0fitInView()\0"
    "zoomIn()\0zoomOut()\0aIsVisible\0"
    "setPositionVisible(bool)\0aPos,aIsAbsolute\0"
    "setPosition(QPointF,bool)\0"
};

void CXPathView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXPathView *_t = static_cast<CXPathView *>(_o);
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->fitInView(); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        case 4: _t->setPositionVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setPosition((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXPathView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXPathView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CXPathView,
      qt_meta_data_CXPathView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXPathView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXPathView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXPathView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXPathView))
        return static_cast<void*>(const_cast< CXPathView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CXPathView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
