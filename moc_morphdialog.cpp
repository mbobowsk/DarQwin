/****************************************************************************
** Meta object code from reading C++ file 'morphdialog.h'
**
** Created: Thu Jan 3 13:23:14 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "morphdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'morphdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MorphDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   13,   12,   12, 0x05,
      55,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   12,   12,   12, 0x08,
      85,   12,   12,   12, 0x08,
     111,  105,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MorphDialog[] = {
    "MorphDialog\0\0size,iterations,type\0"
    "preview(int,int,int)\0help()\0"
    "previewButtonPressed()\0helpButtonPressed()\0"
    "value\0sizeOdd(int)\0"
};

const QMetaObject MorphDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MorphDialog,
      qt_meta_data_MorphDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MorphDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MorphDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MorphDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MorphDialog))
        return static_cast<void*>(const_cast< MorphDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MorphDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: preview((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: help(); break;
        case 2: previewButtonPressed(); break;
        case 3: helpButtonPressed(); break;
        case 4: sizeOdd((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MorphDialog::preview(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MorphDialog::help()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
