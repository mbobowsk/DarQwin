#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "brightnessdialog.h"
#include "darqimage.h"
#include <cv.h>
#include <cxcore.h>
#include "imageprocessor.h"
#include "cvimage.h"
#include "model.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("DarQwin"));
    createConnections();
    createTabs();
    //Full screen
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

void MainWindow::createConnections() {
    connect(ui->openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->saveAsAction, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    connect(ui->aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->exitAction, SIGNAL(triggered()), this, SLOT(quit()));
    connect(ui->undoAction, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->redoAction, SIGNAL(triggered()), this, SLOT(redo()));
    connect(ui->brightnessAction, SIGNAL(triggered()), this, SLOT(setBrightness()));
    connect(ui->smoothAverageAction, SIGNAL(triggered()), this, SLOT(smoothAverage()));
    connect(ui->smoothMedianAction, SIGNAL(triggered()), this, SLOT(smoothMedian()));
    connect(ui->smoothGaussianAction, SIGNAL(triggered()), this, SLOT(smoothGaussian()));
    connect(ui->smoothBilateralAction, SIGNAL(triggered()), this, SLOT(smoothBilateral()));
    connect(ui->dockWidget,SIGNAL(dockLocationChanged(Qt::DockWidgetArea)),this,SLOT(dockMoved(Qt::DockWidgetArea)));
}

void MainWindow::createTabs() {
    tabWidget = new sizeHintTabWidget(ui->dockWidget);
    tabWidget->setTabPosition(QTabWidget::East);
    ui->dockWidget->setWidget(tabWidget);

    //transform tab
    transformWidget = new QWidget;
    tabWidget->addTab(transformWidget, tr("Transform"));
    transformList = new QListWidget(transformWidget);
        transformList->addItems(QStringList()
                 << "Transformation 1"
                 << "Transformation 2"
                 << "Transformation 3");

    //fs tab
    fsWidget = new QWidget;
    tabWidget->addTab(fsWidget, tr("Filesystem"));

    //help tab
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

    DarqImage *img = new DarqImage(fileName);
    CVImage *mat = new CVImage(img);
    Model::getInstance().push_back(mat);
    //Ustalam estetyczny rozmiar okna
    const int width = ui->mdiArea->width();
    const int height = ui->mdiArea->height();
    const int imgWidth = img->width;
    const int imgHeight = img->height;
    QMdiSubWindow *sub = ui->mdiArea->addSubWindow(img);
    if ( imgWidth < width && imgHeight < height )
        sub->resize(imgWidth+10,imgHeight+30);
    else if ( imgWidth > width && imgHeight > height )
        sub->resize(width-75,height-50);
    else if ( imgWidth < width && imgHeight > height )
        sub->resize(imgWidth,height-50);
    else
        sub->resize(width-75,imgHeight);
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
                 tr("<p>Darkroom Qt</p>\nDeveloped by Michał Bobowski 2012"));
}

void MainWindow::quit() {
    exit(0);
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
    if (dlg.exec()) {
        value = dlg.getValue().second;
        type = dlg.getValue().first;
    }
    QString path = ((DarqImage *)sub->widget())->path;
    CVImage *cvimage = Model::getInstance().pathFind(path);
    ImageProcessor::getInstance().changeBrightness(cvimage,type,value);
}


void MainWindow::dockMoved(Qt::DockWidgetArea area) {
    if ( area == Qt::LeftDockWidgetArea )
        tabWidget->setTabPosition(QTabWidget::West);
    else if ( area == Qt::RightDockWidgetArea )
        tabWidget->setTabPosition(QTabWidget::East);
    else
        tabWidget->setTabPosition(QTabWidget::North);
}

void MainWindow::smoothAverage() {
    qDebug() << "Avg";
}

void MainWindow::smoothMedian() {
    qDebug() << "Med";
}

void MainWindow::smoothGaussian() {
    qDebug() << "Gau";
}

void MainWindow::smoothBilateral() {
    qDebug() << "Bil";
}
