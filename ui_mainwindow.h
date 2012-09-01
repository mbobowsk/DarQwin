/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Aug 29 18:08:10 2012
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
    QAction *smoothAverageAction;
    QAction *smoothMedianAction;
    QAction *smoothGaussianAction;
    QAction *smoothBilateralAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Tune;
    QMenu *menu_About;
    QMenu *menuFilter;
    QMenu *menuSmooth;
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
        icon.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon1);
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QString::fromUtf8("saveAsAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QString::fromUtf8("undoAction"));
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName(QString::fromUtf8("redoAction"));
        brightnessAction = new QAction(MainWindow);
        brightnessAction->setObjectName(QString::fromUtf8("brightnessAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        smoothAverageAction = new QAction(MainWindow);
        smoothAverageAction->setObjectName(QString::fromUtf8("smoothAverageAction"));
        smoothMedianAction = new QAction(MainWindow);
        smoothMedianAction->setObjectName(QString::fromUtf8("smoothMedianAction"));
        smoothGaussianAction = new QAction(MainWindow);
        smoothGaussianAction->setObjectName(QString::fromUtf8("smoothGaussianAction"));
        smoothBilateralAction = new QAction(MainWindow);
        smoothBilateralAction->setObjectName(QString::fromUtf8("smoothBilateralAction"));
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
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        menuFilter = new QMenu(menuBar);
        menuFilter->setObjectName(QString::fromUtf8("menuFilter"));
        menuSmooth = new QMenu(menuFilter);
        menuSmooth->setObjectName(QString::fromUtf8("menuSmooth"));
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
        menuBar->addAction(menuFilter->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menu_File->addAction(openAction);
        menu_File->addAction(saveAction);
        menu_File->addAction(saveAsAction);
        menu_File->addSeparator();
        menu_File->addAction(exitAction);
        menu_Edit->addAction(undoAction);
        menu_Edit->addAction(redoAction);
        menu_Tune->addAction(brightnessAction);
        menu_About->addAction(aboutAction);
        menuFilter->addAction(menuSmooth->menuAction());
        menuSmooth->addAction(smoothAverageAction);
        menuSmooth->addAction(smoothMedianAction);
        menuSmooth->addAction(smoothGaussianAction);
        menuSmooth->addAction(smoothBilateralAction);
        mainToolBar->addAction(openAction);
        mainToolBar->addAction(saveAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        openAction->setText(QApplication::translate("MainWindow", "&Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        openAction->setToolTip(QApplication::translate("MainWindow", "Open an image file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        openAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        saveAction->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveAction->setToolTip(QApplication::translate("MainWindow", "Save image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        saveAsAction->setText(QApplication::translate("MainWindow", "Save &As...", 0, QApplication::UnicodeUTF8));
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
        smoothAverageAction->setText(QApplication::translate("MainWindow", "&Average", 0, QApplication::UnicodeUTF8));
        smoothMedianAction->setText(QApplication::translate("MainWindow", "&Median", 0, QApplication::UnicodeUTF8));
        smoothGaussianAction->setText(QApplication::translate("MainWindow", "&Gaussian Blur", 0, QApplication::UnicodeUTF8));
        smoothBilateralAction->setText(QApplication::translate("MainWindow", "&Bilateral", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_Tune->setTitle(QApplication::translate("MainWindow", "&Image", 0, QApplication::UnicodeUTF8));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        menuFilter->setTitle(QApplication::translate("MainWindow", "&Filter", 0, QApplication::UnicodeUTF8));
        menuSmooth->setTitle(QApplication::translate("MainWindow", "&Smooth", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
