/****************************************************************************
** Meta object code from reading C++ file 'rankfilterdialog.h'
**
** Created: Sat Oct 13 22:54:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rankfilterdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rankfilterdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rankFilterDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   17,   17,   17, 0x08,
      65,   17,   17,   17, 0x08,
      84,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rankFilterDialog[] = {
    "rankFilterDialog\0\0size,value\0"
    "preview(int,int)\0button3x3Pressed()\0"
    "button5x5Pressed()\0previewButtonPressed()\0"
};

const QMetaObject rankFilterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rankFilterDialog,
      qt_meta_data_rankFilterDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rankFilterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rankFilterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rankFilterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rankFilterDialog))
        return static_cast<void*>(const_cast< rankFilterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int rankFilterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: preview((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: button3x3Pressed(); break;
        case 2: button5x5Pressed(); break;
        case 3: previewButtonPressed(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void rankFilterDialog::preview(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
