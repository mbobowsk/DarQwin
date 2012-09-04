#ifndef MDISUBWINDOW_H
#define MDISUBWINDOW_H

#include <QWidget>
#include <QMdiSubWindow>

class MdiSubWindow : public QMdiSubWindow
{
public:
    MdiSubWindow();
    void closeEvent(QCloseEvent *closeEvent);
};

#endif // MDISUBWINDOW_H
