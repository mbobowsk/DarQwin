#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QListWidget>
#include "model.h"
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

    Model *model;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *imageMenu;
    QMenu *tuneMenu;


    QToolButton *openToolButton;
    QToolButton *saveToolButton;

    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *aboutAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *brightnessAct;

    QListWidget *transformList;
    sizeHintTabWidget *tabWidget;
    QWidget *transformWidget;
    QWidget *helpWidget;
    QWidget *fsWidget;

    void createMenu();
    void createAction();
    void createToolBar();
    void createDockAndTabs();

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

};

#endif // MAINWINDOW_H
