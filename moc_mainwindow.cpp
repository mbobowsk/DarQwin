/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Sep 26 18:11:08 2012
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
      32,   14, // methods
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
      85,   11,   11,   11, 0x08,
      98,   93,   11,   11, 0x08,
     130,  128,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     258,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     330,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     365,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     380,   11,   11,   11, 0x08,
     404,   11,   11,   11, 0x08,
     416,   11,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     436,   11,   11,   11, 0x08,
     444,   11,   11,   11, 0x08,
     453,   11,   11,   11, 0x08,
     469,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openFile()\0saveFile()\0"
    "saveFileAs()\0about()\0quit()\0undo()\0"
    "redo()\0select()\0point()\0area\0"
    "dockMoved(Qt::DockWidgetArea)\0,\0"
    "mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates)\0"
    "convertToGrayscale()\0convertToRGB()\0"
    "setBrightness()\0smoothAverage3x3()\0"
    "smoothAverage5x5()\0smoothMedian3x3()\0"
    "smoothMedian5x5()\0smoothGaussian()\0"
    "smoothBilateral()\0erode()\0dilate()\0"
    "open()\0close()\0morphologicalGradient()\0"
    "threshold()\0sobel()\0laplacian()\0canny()\0"
    "scharr()\0showHistogram()\0allClosed()\0"
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
        case 7: select(); break;
        case 8: point(); break;
        case 9: dockMoved((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 10: mdiWindowStateChanged((*reinterpret_cast< Qt::WindowStates(*)>(_a[1])),(*reinterpret_cast< Qt::WindowStates(*)>(_a[2]))); break;
        case 11: convertToGrayscale(); break;
        case 12: convertToRGB(); break;
        case 13: setBrightness(); break;
        case 14: smoothAverage3x3(); break;
        case 15: smoothAverage5x5(); break;
        case 16: smoothMedian3x3(); break;
        case 17: smoothMedian5x5(); break;
        case 18: smoothGaussian(); break;
        case 19: smoothBilateral(); break;
        case 20: erode(); break;
        case 21: dilate(); break;
        case 22: open(); break;
        case 23: close(); break;
        case 24: morphologicalGradient(); break;
        case 25: threshold(); break;
        case 26: sobel(); break;
        case 27: laplacian(); break;
        case 28: canny(); break;
        case 29: scharr(); break;
        case 30: showHistogram(); break;
        case 31: allClosed(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
