#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "sizehinttabwidget.h"
#include <QMdiSubWindow>
#include "cvimage.h"
#include "mdisubwindow.h"
#include "caretaker.h"
#include "sizehintlistwidget.h"
#include <QWebView>

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

    SizeHintListWidget *transformList;
    sizeHintTabWidget *tabWidget;
    QWidget *transformWidget;
    QWidget *helpWidget;
    bool selectionMode; //true jeśli pracujemy w trybie oznaczania
    QWebView *webView;

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
    
    void saveAlgorithm();
    void openAlgorithm();
    void saveProject();

    void dockMoved(Qt::DockWidgetArea area);
    void mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates);

    void convertToGrayscale();
    void convertToRGB();

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
    void scharr();
    void showHistogram();
    void equalizeHistogram();
    void rankFilter();
    void customFilter();
    void logicalFilter();
    void FFT();
    void idealLowPass();
    void gaussianLowPass();
    void idealHighPass();
    void gaussianHighPass();

    void allClosed();

    void previewBrightness(char type, int value);
    void previewBilateral(int diameter, int sigmaC, int sigmaS);
    void previewCanny(int value);
    void previewCustomFilter(int divisor,std::vector<float>);
    void previewRankFilter(int size, int value);
    void previewThreshold(int mode, int value);
};

#endif // MAINWINDOW_H
