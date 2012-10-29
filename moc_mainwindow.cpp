/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Oct 29 11:40:30 2012
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
      44,   14, // methods
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
      93,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     144,  139,   11,   11, 0x08,
     176,  174,   11,   11, 0x08,
     233,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     269,   11,   11,   11, 0x08,
     285,   11,   11,   11, 0x08,
     304,   11,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     359,   11,   11,   11, 0x08,
     376,   11,   11,   11, 0x08,
     394,   11,   11,   11, 0x08,
     402,   11,   11,   11, 0x08,
     411,   11,   11,   11, 0x08,
     418,   11,   11,   11, 0x08,
     426,   11,   11,   11, 0x08,
     450,   11,   11,   11, 0x08,
     462,   11,   11,   11, 0x08,
     470,   11,   11,   11, 0x08,
     482,   11,   11,   11, 0x08,
     490,   11,   11,   11, 0x08,
     499,   11,   11,   11, 0x08,
     515,   11,   11,   11, 0x08,
     535,   11,   11,   11, 0x08,
     548,   11,   11,   11, 0x08,
     563,   11,   11,   11, 0x08,
     586,  575,   11,   11, 0x08,
     637,  614,   11,   11, 0x08,
     673,  667,   11,   11, 0x08,
     700,  691,   11,   11, 0x08,
     755,  744,   11,   11, 0x08,
     793,  782,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openFile()\0saveFile()\0"
    "saveFileAs()\0about()\0quit()\0undo()\0"
    "redo()\0select()\0point()\0saveAlgorithm()\0"
    "openAlgorithm()\0saveProject()\0area\0"
    "dockMoved(Qt::DockWidgetArea)\0,\0"
    "mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates)\0"
    "convertToGrayscale()\0convertToRGB()\0"
    "setBrightness()\0smoothAverage3x3()\0"
    "smoothAverage5x5()\0smoothMedian3x3()\0"
    "smoothMedian5x5()\0smoothGaussian()\0"
    "smoothBilateral()\0erode()\0dilate()\0"
    "open()\0close()\0morphologicalGradient()\0"
    "threshold()\0sobel()\0laplacian()\0canny()\0"
    "scharr()\0showHistogram()\0equalizeHistogram()\0"
    "rankFilter()\0customFilter()\0allClosed()\0"
    "type,value\0previewBrightness(char,int)\0"
    "diameter,sigmaC,sigmaS\0"
    "previewBilateral(int,int,int)\0value\0"
    "previewCanny(int)\0divisor,\0"
    "previewCustomFilter(int,std::vector<float>)\0"
    "size,value\0previewRankFilter(int,int)\0"
    "mode,value\0previewThreshold(int,int)\0"
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
        case 9: saveAlgorithm(); break;
        case 10: openAlgorithm(); break;
        case 11: saveProject(); break;
        case 12: dockMoved((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 13: mdiWindowStateChanged((*reinterpret_cast< Qt::WindowStates(*)>(_a[1])),(*reinterpret_cast< Qt::WindowStates(*)>(_a[2]))); break;
        case 14: convertToGrayscale(); break;
        case 15: convertToRGB(); break;
        case 16: setBrightness(); break;
        case 17: smoothAverage3x3(); break;
        case 18: smoothAverage5x5(); break;
        case 19: smoothMedian3x3(); break;
        case 20: smoothMedian5x5(); break;
        case 21: smoothGaussian(); break;
        case 22: smoothBilateral(); break;
        case 23: erode(); break;
        case 24: dilate(); break;
        case 25: open(); break;
        case 26: close(); break;
        case 27: morphologicalGradient(); break;
        case 28: threshold(); break;
        case 29: sobel(); break;
        case 30: laplacian(); break;
        case 31: canny(); break;
        case 32: scharr(); break;
        case 33: showHistogram(); break;
        case 34: equalizeHistogram(); break;
        case 35: rankFilter(); break;
        case 36: customFilter(); break;
        case 37: allClosed(); break;
        case 38: previewBrightness((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: previewBilateral((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 40: previewCanny((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: previewCustomFilter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::vector<float>(*)>(_a[2]))); break;
        case 42: previewRankFilter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: previewThreshold((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 44;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
