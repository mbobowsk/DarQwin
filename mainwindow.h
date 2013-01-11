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
#include "helpmodel.h"

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
    HelpModel *helpModel;

    void createConnections();
    void createTabs();
    void helpConfig();
    CVImage* getActiveImage();
    Caretaker* getActiveCaretaker();
    void saveToHistory(const CVImage &);
    void refreshGUI(CVImage &);
    QRect getSelection();

    // ostatnio używana ścieżka
    QString currentDir;


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
    void butterworthLowPass();
    void idealHighPass();
    void gaussianHighPass();
    void butterworthHighPass();
    void bandPass();
    void hsv();
    void resizeImg();
    void noise();
    void DCT();

    void allClosed();
    void listActivated(QListWidgetItem *item);
    void locateHelp();

    //PREVIEW
    void previewBrightness(char type, int value);
    void previewBilateral(int diameter, int sigmaC, int sigmaS);
    void previewCanny(int value);
    void previewCustomFilter(int divisor,std::vector<float>);
    void previewRankFilter(int size, int value);
    void previewThreshold(int mode, int value);
    void previewHsv(int hue, int saturation);
    void previewLogic(QString ifStr, QStringList thenStr, QStringList elseStr);
    //dla filtrów gaussa i idealnych
    void previewFourierCutoff(int cutoff, int mode);
    void previewFourierButterworth(int cutoff, int order, int mode);
    void previewBandPass(int inner, int outer);
    void previewMorph(int size, int iterations, int type);

    //HELP
    void helpCanny();
    void helpBilateral();
    void helpIdeal();
    void helpButterworth();
    void helpGauss();
    void helpResize();
    void helpCustom();
    void helpRank();
    void helpThresh();
    void helpLogic();
    void helpMorph();
};

#endif // MAINWINDOW_H
