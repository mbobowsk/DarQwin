/****************************************************************************
** Meta object code from reading C++ file 'logicalfilterdialog.h'
**
** Created: Sat Dec 29 12:16:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "logicalfilterdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logicalfilterdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_logicalFilterDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      31,   28,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   20,   20,   20, 0x08,
      92,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_logicalFilterDialog[] = {
    "logicalFilterDialog\0\0help()\0,,\0"
    "preview(QString,QStringList,QStringList)\0"
    "helpButtonPressed()\0previewButtonPressed()\0"
};

const QMetaObject logicalFilterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_logicalFilterDialog,
      qt_meta_data_logicalFilterDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &logicalFilterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *logicalFilterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *logicalFilterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_logicalFilterDialog))
        return static_cast<void*>(const_cast< logicalFilterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int logicalFilterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: help(); break;
        case 1: preview((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 2: helpButtonPressed(); break;
        case 3: previewButtonPressed(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void logicalFilterDialog::help()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void logicalFilterDialog::preview(QString _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
