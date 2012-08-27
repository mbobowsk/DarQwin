#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "brightnessdialog.h"
#include "darqimage.h"
#include "model.h"
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include "imageprocessor.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new Model();
    setWindowTitle(tr("DarQwin"));
    createAction();
    createMenu();
    createToolBar();
    createDockAndTabs();
    const int width = QApplication::desktop()->width();
    const int height = QApplication::desktop()->height();
    resize(width,height);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::createAction() {
    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an image file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAct = new QAction(QIcon(":/images/save.png"),tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save image"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));

    saveAsAct = new QAction(tr("&Save as..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save image as new File"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("About Darqwin"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setStatusTip(tr("Exit Darqwin"));
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(quit()));

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    brightnessAct = new QAction(tr("&Brightness"), this);
    brightnessAct->setStatusTip(tr("Modify image's brightness"));
    connect(brightnessAct, SIGNAL(triggered()), this, SLOT(setBrightness()));

}

void MainWindow::createMenu()  {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(aboutAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);

    imageMenu = menuBar()->addMenu(tr("&Image"));

    tuneMenu = imageMenu->addMenu(tr("&Tune"));
    tuneMenu->addAction(brightnessAct);

}

void MainWindow::createToolBar() {
    ui->mainToolBar->addAction(openAct);
    ui->mainToolBar->addAction(saveAct);
}

void MainWindow::createDockAndTabs() {
    //dock widget
    dockWidget = new QDockWidget(tr("Control Panel"),this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);

    dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
    addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    connect(dockWidget,SIGNAL(dockLocationChanged(Qt::DockWidgetArea)),this,SLOT(dockMoved(Qt::DockWidgetArea)));

    //tabs
    tabWidget = new QTabWidget(dockWidget);
    tabWidget->setTabPosition(QTabWidget::East);

    //tabWidget->setMinimumWidth(200);


    dockWidget->setWidget(tabWidget);


    //transform
    transformWidget = new QWidget;
    tabWidget->addTab(transformWidget, tr("Transform"));

    transformList = new QListWidget(transformWidget);
        transformList->addItems(QStringList()
                 << "Transformation 1"
                 << "Transformation 2"
                 << "Transformation 3");

    //fs
    fsWidget = new QWidget;
    tabWidget->addTab(fsWidget, tr("Filesystem"));

    //help
    helpWidget = new QWidget;
    tabWidget->addTab(helpWidget, tr("Help"));


}



void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
         QImage image(fileName);
         if (image.isNull()) {
             QMessageBox::information(this, tr("Darqwin"),
                                      tr("Cannot load %1.").arg(fileName).append("\nUnsupported file format"));
                 return;
             }
     }
    else
        return;
    const int width = QApplication::desktop()->width();
    const int height = QApplication::desktop()->height();
    DarqImage *img = new DarqImage(fileName, width, height);
    model->images.push_back(img);
    ui->mdiArea->addSubWindow(img);
    img->show();
}

void MainWindow::saveFile() {
    qDebug("saveFile");
}

void MainWindow::saveFileAs() {
    qDebug("saveFileAs");
}

void MainWindow::about() {
    qDebug("about");
    QMessageBox::about(this, tr("About Darqwin"),
                 tr("<p>Darkroom Qt</p>\nDeveloped by Michal Bobowski 2012"));
}

void MainWindow::quit() {
    qDebug("quit");
}

void MainWindow::undo() {
    qDebug("undo");
}

void MainWindow::redo() {
    qDebug("redo");
}

void MainWindow::setBrightness() {
    qDebug("setBrightness");
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;

    }
    brightnessDialog dlg;
    char type;
    int value;
    if (dlg.exec())
    {
        value = dlg.getValue().second;
        type = dlg.getValue().first;
    }

    model->refresh();
    if ( model->images.empty() )
        return;
    

    if ( sub == NULL ) {
        qDebug("FUCK");
        return;
    }

    DarqImage *active = (DarqImage *)sub->widget();

    if ( active == NULL ) {
        qDebug("FUCK");
        return;
    }

    for ( int x = 0; x < active->image->width(); ++x) {
        for ( int y = 0; y < active->image->height(); ++y) {
            QRgb p = active->image->pixel(QPoint(x,y));
            int green = qGreen(p);
            int blue = qBlue(p);
            int red = qRed(p);

            if ( type == 'a' ) {
                green += value;
                blue += value;
                red += value;
            }
            else if ( type == 'r' )
                red += value;
            else if ( type == 'g' )
                green += value;
            else if ( type == 'b' )
                blue += value;

            if ( red > 255 )
                red = 255;
            else if ( red < 0 )
                red = 0;

            if ( green > 255 )
                green = 255;
            else if ( green < 0 )
                green = 0;

            if ( blue > 255 )
                blue = 255;
            else if ( blue < 0 )
                blue = 0;

            QRgb value = qRgb(red, green, blue);
            active->image->setPixel(x, y, value);
        }
    }
    active->imageLabel->clear();
    active->imageLabel->setPixmap(QPixmap::fromImage(*(active->image)));
}


void MainWindow::dockMoved(Qt::DockWidgetArea area) {
    if ( area == Qt::LeftDockWidgetArea )
        tabWidget->setTabPosition(QTabWidget::West);
    else if ( area == Qt::RightDockWidgetArea )
        tabWidget->setTabPosition(QTabWidget::East);
    else
        tabWidget->setTabPosition(QTabWidget::North);
}
