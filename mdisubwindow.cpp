#include "mdisubwindow.h"
#include <QDebug>

MdiSubWindow::MdiSubWindow()
{
}

void MdiSubWindow::closeEvent(QCloseEvent *closeEvent) {
    qDebug() << "abc";
}
