/****************************************************************************
** Meta object code from reading C++ file 'butterworthdialog.h'
**
** Created: Fri Nov 16 17:52:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "butterworthdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'butterworthdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ButterworthDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ButterworthDialog[] = {
    "ButterworthDialog\0"
};

const QMetaObject ButterworthDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ButterworthDialog,
      qt_meta_data_ButterworthDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ButterworthDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ButterworthDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ButterworthDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ButterworthDialog))
        return static_cast<void*>(const_cast< ButterworthDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ButterworthDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
