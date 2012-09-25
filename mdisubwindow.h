#ifndef MDISUBWINDOW_H
#define MDISUBWINDOW_H

#include <QWidget>
#include <QMdiSubWindow>

class MdiSubWindow : public QMdiSubWindow
{
Q_OBJECT
public:
    MdiSubWindow(QWidget *widget);
    ~MdiSubWindow();
    void closeEvent(QCloseEvent *closeEvent);
signals:
    void allClosed();
};

#endif // MDISUBWINDOW_H
