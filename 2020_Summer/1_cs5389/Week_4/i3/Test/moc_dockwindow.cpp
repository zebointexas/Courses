/****************************************************************************
** Meta object code from reading C++ file 'dockwindow.h'
**
** Created: Wed Jul 1 22:46:28 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dockwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dockwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DockWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      22,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DockWindow[] = {
    "DockWindow\0\0newFile()\0save()\0about()\0"
};

const QMetaObject DockWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DockWindow,
      qt_meta_data_DockWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DockWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DockWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DockWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DockWindow))
        return static_cast<void*>(const_cast< DockWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DockWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFile(); break;
        case 1: save(); break;
        case 2: about(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
