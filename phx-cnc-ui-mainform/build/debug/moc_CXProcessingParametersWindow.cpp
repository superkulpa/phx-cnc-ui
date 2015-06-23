/****************************************************************************
** Meta object code from reading C++ file 'CXProcessingParametersWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/CXProcessingParametersWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CXProcessingParametersWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CXProcessingParametersWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x08,
      41,   29,   29,   29, 0x08,
      54,   29,   29,   29, 0x08,
      75,   65,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CXProcessingParametersWindow[] = {
    "CXProcessingParametersWindow\0\0onLoadDB()\0"
    "onFileLoad()\0closeFtp()\0aIsUpload\0"
    "onAllFilesIsLoaded(bool)\0"
};

void CXProcessingParametersWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CXProcessingParametersWindow *_t = static_cast<CXProcessingParametersWindow *>(_o);
        switch (_id) {
        case 0: _t->onLoadDB(); break;
        case 1: _t->onFileLoad(); break;
        case 2: _t->closeFtp(); break;
        case 3: _t->onAllFilesIsLoaded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CXProcessingParametersWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CXProcessingParametersWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CXProcessingParametersWindow,
      qt_meta_data_CXProcessingParametersWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CXProcessingParametersWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CXProcessingParametersWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CXProcessingParametersWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CXProcessingParametersWindow))
        return static_cast<void*>(const_cast< CXProcessingParametersWindow*>(this));
    if (!strcmp(_clname, "Ui::CXProcessingParametersWindow"))
        return static_cast< Ui::CXProcessingParametersWindow*>(const_cast< CXProcessingParametersWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int CXProcessingParametersWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
