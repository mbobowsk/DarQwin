/****************************************************************************
** Meta object code from reading C++ file 'mdisubwindow.h'
**
** Created: Tue Sep 25 11:39:51 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mdisubwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdisubwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MdiSubWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MdiSubWindow[] = {
    "MdiSubWindow\0\0allClosed()\0"
};

const QMetaObject MdiSubWindow::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_MdiSubWindow,
      qt_meta_data_MdiSubWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MdiSubWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MdiSubWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MdiSubWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MdiSubWindow))
        return static_cast<void*>(const_cast< MdiSubWindow*>(this));
    return QMdiSubWindow::qt_metacast(_clname);
}

int MdiSubWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: allClosed(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MdiSubWindow::allClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
