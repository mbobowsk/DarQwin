#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "sizehinttabwidget.h"

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

private slots:
    void openFile();
    void saveFile();
    void saveFileAs();
    void about();
    void quit();
    void undo();
    void redo();
    void setBrightness();
    void dockMoved(Qt::DockWidgetArea area);
    void smoothAverage();
    void smoothMedian();
    void smoothGaussian();
    void smoothBilateral();
};

#endif // MAINWINDOW_H
