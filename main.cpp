#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //dodaj sterownik do jpeg
    QString dir = QCoreApplication::applicationDirPath();
    dir.append("/plugins/imageformats");
    a.addLibraryPath(dir);

    MainWindow w;
    w.show();
    return a.exec();
}
