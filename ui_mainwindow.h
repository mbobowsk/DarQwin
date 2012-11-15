/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Nov 14 22:44:27 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *brightnessAction;
    QAction *aboutAction;
    QAction *smoothGaussianAction;
    QAction *smoothBilateralAction;
    QAction *avg3x3Action;
    QAction *avg5x5Action;
    QAction *med3x3Action;
    QAction *med5x5Action;
    QAction *pointAction;
    QAction *selectAction;
    QAction *erodeAction;
    QAction *dilateAction;
    QAction *openingAction;
    QAction *closeAction;
    QAction *gradientAction;
    QAction *thresholdAction;
    QAction *sobelAction;
    QAction *laplacianAction;
    QAction *cannyAction;
    QAction *grayscaleAction;
    QAction *RGBAction;
    QAction *scharrAction;
    QAction *histogramAction;
    QAction *equalizeAction;
    QAction *customFilterAction;
    QAction *logicalFilterAction;
    QAction *openAlgorithmAction;
    QAction *saveAlgorithmAction;
    QAction *saveProjectAction;
    QAction *rankFilterAction;
    QAction *FFTAction;
    QAction *idealLowPassAction;
    QAction *gaussianLowPassAction;
    QAction *idealHighPassAction;
    QAction *gaussianHighPassAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Tune;
    QMenu *menuFormat;
    QMenu *menu_Histogram;
    QMenu *menu_About;
    QMenu *menuProcess;
    QMenu *menuSmooth;
    QMenu *menu_Average;
    QMenu *menu_Median;
    QMenu *menuMorphology;
    QMenu *menuContours;
    QMenu *menu_Other;
    QMenu *menu_Transform;
    QMenu *menu_Low_Pass_Filter;
    QMenu *menu_High_Pass_Filter;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/open2.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save2.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon1);
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QString::fromUtf8("saveAsAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QString::fromUtf8("undoAction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undoAction->setIcon(icon2);
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName(QString::fromUtf8("redoAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redoAction->setIcon(icon3);
        brightnessAction = new QAction(MainWindow);
        brightnessAction->setObjectName(QString::fromUtf8("brightnessAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        smoothGaussianAction = new QAction(MainWindow);
        smoothGaussianAction->setObjectName(QString::fromUtf8("smoothGaussianAction"));
        smoothBilateralAction = new QAction(MainWindow);
        smoothBilateralAction->setObjectName(QString::fromUtf8("smoothBilateralAction"));
        avg3x3Action = new QAction(MainWindow);
        avg3x3Action->setObjectName(QString::fromUtf8("avg3x3Action"));
        avg5x5Action = new QAction(MainWindow);
        avg5x5Action->setObjectName(QString::fromUtf8("avg5x5Action"));
        med3x3Action = new QAction(MainWindow);
        med3x3Action->setObjectName(QString::fromUtf8("med3x3Action"));
        med5x5Action = new QAction(MainWindow);
        med5x5Action->setObjectName(QString::fromUtf8("med5x5Action"));
        pointAction = new QAction(MainWindow);
        pointAction->setObjectName(QString::fromUtf8("pointAction"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/point.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointAction->setIcon(icon4);
        selectAction = new QAction(MainWindow);
        selectAction->setObjectName(QString::fromUtf8("selectAction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/selection.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectAction->setIcon(icon5);
        erodeAction = new QAction(MainWindow);
        erodeAction->setObjectName(QString::fromUtf8("erodeAction"));
        dilateAction = new QAction(MainWindow);
        dilateAction->setObjectName(QString::fromUtf8("dilateAction"));
        openingAction = new QAction(MainWindow);
        openingAction->setObjectName(QString::fromUtf8("openingAction"));
        closeAction = new QAction(MainWindow);
        closeAction->setObjectName(QString::fromUtf8("closeAction"));
        gradientAction = new QAction(MainWindow);
        gradientAction->setObjectName(QString::fromUtf8("gradientAction"));
        thresholdAction = new QAction(MainWindow);
        thresholdAction->setObjectName(QString::fromUtf8("thresholdAction"));
        sobelAction = new QAction(MainWindow);
        sobelAction->setObjectName(QString::fromUtf8("sobelAction"));
        laplacianAction = new QAction(MainWindow);
        laplacianAction->setObjectName(QString::fromUtf8("laplacianAction"));
        cannyAction = new QAction(MainWindow);
        cannyAction->setObjectName(QString::fromUtf8("cannyAction"));
        grayscaleAction = new QAction(MainWindow);
        grayscaleAction->setObjectName(QString::fromUtf8("grayscaleAction"));
        grayscaleAction->setCheckable(true);
        RGBAction = new QAction(MainWindow);
        RGBAction->setObjectName(QString::fromUtf8("RGBAction"));
        RGBAction->setCheckable(true);
        scharrAction = new QAction(MainWindow);
        scharrAction->setObjectName(QString::fromUtf8("scharrAction"));
        histogramAction = new QAction(MainWindow);
        histogramAction->setObjectName(QString::fromUtf8("histogramAction"));
        equalizeAction = new QAction(MainWindow);
        equalizeAction->setObjectName(QString::fromUtf8("equalizeAction"));
        customFilterAction = new QAction(MainWindow);
        customFilterAction->setObjectName(QString::fromUtf8("customFilterAction"));
        logicalFilterAction = new QAction(MainWindow);
        logicalFilterAction->setObjectName(QString::fromUtf8("logicalFilterAction"));
        openAlgorithmAction = new QAction(MainWindow);
        openAlgorithmAction->setObjectName(QString::fromUtf8("openAlgorithmAction"));
        saveAlgorithmAction = new QAction(MainWindow);
        saveAlgorithmAction->setObjectName(QString::fromUtf8("saveAlgorithmAction"));
        saveProjectAction = new QAction(MainWindow);
        saveProjectAction->setObjectName(QString::fromUtf8("saveProjectAction"));
        rankFilterAction = new QAction(MainWindow);
        rankFilterAction->setObjectName(QString::fromUtf8("rankFilterAction"));
        FFTAction = new QAction(MainWindow);
        FFTAction->setObjectName(QString::fromUtf8("FFTAction"));
        idealLowPassAction = new QAction(MainWindow);
        idealLowPassAction->setObjectName(QString::fromUtf8("idealLowPassAction"));
        gaussianLowPassAction = new QAction(MainWindow);
        gaussianLowPassAction->setObjectName(QString::fromUtf8("gaussianLowPassAction"));
        idealHighPassAction = new QAction(MainWindow);
        idealHighPassAction->setObjectName(QString::fromUtf8("idealHighPassAction"));
        gaussianHighPassAction = new QAction(MainWindow);
        gaussianHighPassAction->setObjectName(QString::fromUtf8("gaussianHighPassAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mdiArea->sizePolicy().hasHeightForWidth());
        mdiArea->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Tune = new QMenu(menuBar);
        menu_Tune->setObjectName(QString::fromUtf8("menu_Tune"));
        menuFormat = new QMenu(menu_Tune);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        menu_Histogram = new QMenu(menu_Tune);
        menu_Histogram->setObjectName(QString::fromUtf8("menu_Histogram"));
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        menuProcess = new QMenu(menuBar);
        menuProcess->setObjectName(QString::fromUtf8("menuProcess"));
        menuSmooth = new QMenu(menuProcess);
        menuSmooth->setObjectName(QString::fromUtf8("menuSmooth"));
        menu_Average = new QMenu(menuSmooth);
        menu_Average->setObjectName(QString::fromUtf8("menu_Average"));
        menu_Median = new QMenu(menuSmooth);
        menu_Median->setObjectName(QString::fromUtf8("menu_Median"));
        menuMorphology = new QMenu(menuProcess);
        menuMorphology->setObjectName(QString::fromUtf8("menuMorphology"));
        menuContours = new QMenu(menuProcess);
        menuContours->setObjectName(QString::fromUtf8("menuContours"));
        menu_Other = new QMenu(menuProcess);
        menu_Other->setObjectName(QString::fromUtf8("menu_Other"));
        menu_Transform = new QMenu(menuBar);
        menu_Transform->setObjectName(QString::fromUtf8("menu_Transform"));
        menu_Low_Pass_Filter = new QMenu(menu_Transform);
        menu_Low_Pass_Filter->setObjectName(QString::fromUtf8("menu_Low_Pass_Filter"));
        menu_High_Pass_Filter = new QMenu(menu_Transform);
        menu_High_Pass_Filter->setObjectName(QString::fromUtf8("menu_High_Pass_Filter"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidget->setMinimumSize(QSize(56, 41));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidget_2 = new QWidget();
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(0, 0));
        dockWidget->setWidget(dockWidget_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Tune->menuAction());
        menuBar->addAction(menuProcess->menuAction());
        menuBar->addAction(menu_Transform->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menu_File->addAction(openAction);
        menu_File->addAction(saveAction);
        menu_File->addAction(saveAsAction);
        menu_File->addSeparator();
        menu_File->addAction(openAlgorithmAction);
        menu_File->addAction(saveAlgorithmAction);
        menu_File->addAction(saveProjectAction);
        menu_File->addSeparator();
        menu_File->addAction(exitAction);
        menu_Edit->addAction(undoAction);
        menu_Edit->addAction(redoAction);
        menu_Tune->addAction(brightnessAction);
        menu_Tune->addAction(menuFormat->menuAction());
        menu_Tune->addAction(menu_Histogram->menuAction());
        menuFormat->addAction(grayscaleAction);
        menuFormat->addAction(RGBAction);
        menu_Histogram->addAction(histogramAction);
        menu_Histogram->addAction(equalizeAction);
        menu_About->addAction(aboutAction);
        menuProcess->addAction(menuSmooth->menuAction());
        menuProcess->addAction(menuMorphology->menuAction());
        menuProcess->addAction(menuContours->menuAction());
        menuProcess->addAction(menu_Other->menuAction());
        menuProcess->addAction(thresholdAction);
        menuSmooth->addAction(menu_Average->menuAction());
        menuSmooth->addAction(menu_Median->menuAction());
        menuSmooth->addAction(smoothGaussianAction);
        menuSmooth->addAction(smoothBilateralAction);
        menu_Average->addAction(avg3x3Action);
        menu_Average->addAction(avg5x5Action);
        menu_Median->addAction(med3x3Action);
        menu_Median->addAction(med5x5Action);
        menuMorphology->addAction(erodeAction);
        menuMorphology->addAction(dilateAction);
        menuMorphology->addAction(openingAction);
        menuMorphology->addAction(closeAction);
        menuMorphology->addAction(gradientAction);
        menuContours->addAction(sobelAction);
        menuContours->addAction(laplacianAction);
        menuContours->addAction(cannyAction);
        menuContours->addAction(scharrAction);
        menu_Other->addAction(customFilterAction);
        menu_Other->addAction(rankFilterAction);
        menu_Other->addAction(logicalFilterAction);
        menu_Transform->addAction(FFTAction);
        menu_Transform->addAction(menu_Low_Pass_Filter->menuAction());
        menu_Transform->addAction(menu_High_Pass_Filter->menuAction());
        menu_Low_Pass_Filter->addAction(idealLowPassAction);
        menu_Low_Pass_Filter->addAction(gaussianLowPassAction);
        menu_High_Pass_Filter->addAction(idealHighPassAction);
        menu_High_Pass_Filter->addAction(gaussianHighPassAction);
        mainToolBar->addAction(openAction);
        mainToolBar->addAction(saveAction);
        mainToolBar->addAction(undoAction);
        mainToolBar->addAction(redoAction);
        mainToolBar->addAction(pointAction);
        mainToolBar->addAction(selectAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        openAction->setText(QApplication::translate("MainWindow", "&Open Image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        openAction->setToolTip(QApplication::translate("MainWindow", "Open an image file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        openAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        saveAction->setText(QApplication::translate("MainWindow", "&Save Image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveAction->setToolTip(QApplication::translate("MainWindow", "Save image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        saveAsAction->setText(QApplication::translate("MainWindow", "Save Image &As...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveAsAction->setToolTip(QApplication::translate("MainWindow", "Save image as new file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveAsAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        exitAction->setText(QApplication::translate("MainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        exitAction->setToolTip(QApplication::translate("MainWindow", "Exit Darqwin", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        undoAction->setText(QApplication::translate("MainWindow", "&Undo", 0, QApplication::UnicodeUTF8));
        undoAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        redoAction->setText(QApplication::translate("MainWindow", "&Redo", 0, QApplication::UnicodeUTF8));
        redoAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", 0, QApplication::UnicodeUTF8));
        brightnessAction->setText(QApplication::translate("MainWindow", "&Brightness", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        brightnessAction->setToolTip(QApplication::translate("MainWindow", "Modify image's brightness", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        aboutAction->setText(QApplication::translate("MainWindow", "About DarQwin", 0, QApplication::UnicodeUTF8));
        smoothGaussianAction->setText(QApplication::translate("MainWindow", "&Gaussian Blur", 0, QApplication::UnicodeUTF8));
        smoothBilateralAction->setText(QApplication::translate("MainWindow", "&Bilateral", 0, QApplication::UnicodeUTF8));
        avg3x3Action->setText(QApplication::translate("MainWindow", "3x3", 0, QApplication::UnicodeUTF8));
        avg5x5Action->setText(QApplication::translate("MainWindow", "5x5", 0, QApplication::UnicodeUTF8));
        med3x3Action->setText(QApplication::translate("MainWindow", "3x3", 0, QApplication::UnicodeUTF8));
        med5x5Action->setText(QApplication::translate("MainWindow", "5x5", 0, QApplication::UnicodeUTF8));
        pointAction->setText(QApplication::translate("MainWindow", "Point", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pointAction->setToolTip(QApplication::translate("MainWindow", "Go to default mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selectAction->setText(QApplication::translate("MainWindow", "Mark", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectAction->setToolTip(QApplication::translate("MainWindow", "Go to selection mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        erodeAction->setText(QApplication::translate("MainWindow", "&Erode", 0, QApplication::UnicodeUTF8));
        dilateAction->setText(QApplication::translate("MainWindow", "&Dilate", 0, QApplication::UnicodeUTF8));
        openingAction->setText(QApplication::translate("MainWindow", "&Open", 0, QApplication::UnicodeUTF8));
        closeAction->setText(QApplication::translate("MainWindow", "&Close", 0, QApplication::UnicodeUTF8));
        gradientAction->setText(QApplication::translate("MainWindow", "&Gradient", 0, QApplication::UnicodeUTF8));
        thresholdAction->setText(QApplication::translate("MainWindow", "&Threshold", 0, QApplication::UnicodeUTF8));
        sobelAction->setText(QApplication::translate("MainWindow", "&Sobel", 0, QApplication::UnicodeUTF8));
        laplacianAction->setText(QApplication::translate("MainWindow", "&Laplacian", 0, QApplication::UnicodeUTF8));
        cannyAction->setText(QApplication::translate("MainWindow", "&Canny", 0, QApplication::UnicodeUTF8));
        grayscaleAction->setText(QApplication::translate("MainWindow", "&Grayscale", 0, QApplication::UnicodeUTF8));
        RGBAction->setText(QApplication::translate("MainWindow", "&RGB", 0, QApplication::UnicodeUTF8));
        scharrAction->setText(QApplication::translate("MainWindow", "Schar&r", 0, QApplication::UnicodeUTF8));
        histogramAction->setText(QApplication::translate("MainWindow", "&Show", 0, QApplication::UnicodeUTF8));
        equalizeAction->setText(QApplication::translate("MainWindow", "&Equalize", 0, QApplication::UnicodeUTF8));
        customFilterAction->setText(QApplication::translate("MainWindow", "&Custom Filter", 0, QApplication::UnicodeUTF8));
        logicalFilterAction->setText(QApplication::translate("MainWindow", "&Logical Filter", 0, QApplication::UnicodeUTF8));
        openAlgorithmAction->setText(QApplication::translate("MainWindow", "&Open Algorithm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        openAlgorithmAction->setToolTip(QApplication::translate("MainWindow", "Open algorithm and apply it to active image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveAlgorithmAction->setText(QApplication::translate("MainWindow", "&Save Algorithm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveAlgorithmAction->setToolTip(QApplication::translate("MainWindow", "Save list of transformations as algorithm", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveProjectAction->setText(QApplication::translate("MainWindow", "&Save Project", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveProjectAction->setToolTip(QApplication::translate("MainWindow", "Save image with transformations list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        rankFilterAction->setText(QApplication::translate("MainWindow", "&Rank Filter", 0, QApplication::UnicodeUTF8));
        FFTAction->setText(QApplication::translate("MainWindow", "&Calculate FFT", 0, QApplication::UnicodeUTF8));
        idealLowPassAction->setText(QApplication::translate("MainWindow", "&Ideal", 0, QApplication::UnicodeUTF8));
        gaussianLowPassAction->setText(QApplication::translate("MainWindow", "&Gaussian", 0, QApplication::UnicodeUTF8));
        idealHighPassAction->setText(QApplication::translate("MainWindow", "&Ideal", 0, QApplication::UnicodeUTF8));
        gaussianHighPassAction->setText(QApplication::translate("MainWindow", "&Gaussian", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_Tune->setTitle(QApplication::translate("MainWindow", "&Image", 0, QApplication::UnicodeUTF8));
        menuFormat->setTitle(QApplication::translate("MainWindow", "&Format", 0, QApplication::UnicodeUTF8));
        menu_Histogram->setTitle(QApplication::translate("MainWindow", "&Histogram", 0, QApplication::UnicodeUTF8));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        menuProcess->setTitle(QApplication::translate("MainWindow", "&Process", 0, QApplication::UnicodeUTF8));
        menuSmooth->setTitle(QApplication::translate("MainWindow", "&Smooth", 0, QApplication::UnicodeUTF8));
        menu_Average->setTitle(QApplication::translate("MainWindow", "&Average", 0, QApplication::UnicodeUTF8));
        menu_Median->setTitle(QApplication::translate("MainWindow", "&Median", 0, QApplication::UnicodeUTF8));
        menuMorphology->setTitle(QApplication::translate("MainWindow", "&Morphology", 0, QApplication::UnicodeUTF8));
        menuContours->setTitle(QApplication::translate("MainWindow", "&Contours", 0, QApplication::UnicodeUTF8));
        menu_Other->setTitle(QApplication::translate("MainWindow", "&Other Filters", 0, QApplication::UnicodeUTF8));
        menu_Transform->setTitle(QApplication::translate("MainWindow", "&Fourier", 0, QApplication::UnicodeUTF8));
        menu_Low_Pass_Filter->setTitle(QApplication::translate("MainWindow", "&Low-Pass Filter", 0, QApplication::UnicodeUTF8));
        menu_High_Pass_Filter->setTitle(QApplication::translate("MainWindow", "&High-Pass Filter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
