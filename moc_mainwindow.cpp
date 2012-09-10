/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Sep 10 18:05:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     114,  109,   11,   11, 0x08,
     146,  144,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     259,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     294,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openFile()\0saveFile()\0"
    "saveFileAs()\0about()\0quit()\0undo()\0"
    "redo()\0setBrightness()\0closeSubWindow()\0"
    "area\0dockMoved(Qt::DockWidgetArea)\0,\0"
    "mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates)\0"
    "smoothAverage3x3()\0smoothAverage5x5()\0"
    "smoothMedian3x3()\0smoothMedian5x5()\0"
    "smoothGaussian()\0smoothBilateral()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFile(); break;
        case 1: saveFile(); break;
        case 2: saveFileAs(); break;
        case 3: about(); break;
        case 4: quit(); break;
        case 5: undo(); break;
        case 6: redo(); break;
        case 7: setBrightness(); break;
        case 8: closeSubWindow(); break;
        case 9: dockMoved((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 10: mdiWindowStateChanged((*reinterpret_cast< Qt::WindowStates(*)>(_a[1])),(*reinterpret_cast< Qt::WindowStates(*)>(_a[2]))); break;
        case 11: smoothAverage3x3(); break;
        case 12: smoothAverage5x5(); break;
        case 13: smoothMedian3x3(); break;
        case 14: smoothMedian5x5(); break;
        case 15: smoothGaussian(); break;
        case 16: smoothBilateral(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
