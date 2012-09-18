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
    void closeEvent(QCloseEvent *e);

private:
    Ui::MainWindow *ui;

    QListWidget *transformList;
    sizeHintTabWidget *tabWidget;
    QWidget *transformWidget;
    QWidget *helpWidget;
    QWidget *fsWidget;
    bool selectionMode; //true jeśli pracujemy w trybie oznaczania

    void createConnections();
    void createTabs();
    CVImage* getActiveImage();
    Caretaker* getActiveCaretaker();
    void saveToHistory(const CVImage &);
    void refreshGUI(CVImage &);
    QRect getSelection();

private slots:
    void openFile();
    void saveFile();
    void saveFileAs();
    void about();
    void quit();
    void undo();
    void redo();
    void select();
    void point();

    void dockMoved(Qt::DockWidgetArea area);
    void mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates);

    void setBrightness();
    void smoothAverage3x3();
    void smoothAverage5x5();
    void smoothMedian3x3();
    void smoothMedian5x5();
    void smoothGaussian();
    void smoothBilateral();
    void erode();
    void dilate();
    void open();
    void close();
    void morphologicalGradient();
    void threshold();
    void sobel();
    void laplacian();
    void canny();
};

#endif // MAINWINDOW_H
