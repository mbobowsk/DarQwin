#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "sizehinttabwidget.h"
#include <QMdiSubWindow>
#include "cvimage.h"
#include "mdisubwindow.h"
#include "caretaker.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

    QListWidget *transformList;
    sizeHintTabWidget *tabWidget;
    QWidget *transformWidget;
    QWidget *helpWidget;
    QWidget *fsWidget;

    void createConnections();
    void createTabs();
    CVImage* getActiveImage();
    Caretaker* getActiveCaretaker();
    void saveToHistory(const CVImage &);

private slots:
    void openFile();
    void saveFile();
    void saveFileAs();
    void about();
    void quit();
    void undo();
    void redo();
    void setBrightness();
    void closeSubWindow();

    void dockMoved(Qt::DockWidgetArea area);
    void mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates);

    void smoothAverage3x3();
    void smoothAverage5x5();
    void smoothMedian3x3();
    void smoothMedian5x5();
    void smoothGaussian();
    void smoothBilateral();
};

#endif // MAINWINDOW_H
