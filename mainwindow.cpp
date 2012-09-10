#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "brightnessdialog.h"
#include "darqimage.h"
#include <cv.h>
#include <cxcore.h>
#include "imageprocessor.h"
#include "model.h"
#include "caretakermodel.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("DarQwin"));
    createConnections();
    createTabs();
    ui->undoAction->setEnabled(false);
    ui->redoAction->setEnabled(false);
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
    connect(ui->avg3x3Action, SIGNAL(triggered()), this, SLOT(smoothAverage3x3()));
    connect(ui->avg5x5Action, SIGNAL(triggered()), this, SLOT(smoothAverage5x5()));
    connect(ui->med3x3Action, SIGNAL(triggered()), this, SLOT(smoothMedian3x3()));
    connect(ui->med5x5Action, SIGNAL(triggered()), this, SLOT(smoothMedian5x5()));
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

    int imgId = Model::getInstance().nextId();
    DarqImage *img = new DarqImage(fileName,imgId);
    CVImage *mat = new CVImage(img);
    Model::getInstance().images.insert(std::make_pair(imgId,mat));
    //Ustalam estetyczny rozmiar okna
    const int width = ui->mdiArea->width();
    const int height = ui->mdiArea->height();
    const int imgWidth = img->width;
    const int imgHeight = img->height;
    MdiSubWindow *sub = new MdiSubWindow(ui->mdiArea);
    sub->setWidget(img);
    ui->mdiArea->addSubWindow(sub);
    connect(sub,SIGNAL(windowStateChanged(Qt::WindowStates,Qt::WindowStates)),this,SLOT(mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates)));
    CaretakerModel::getInstance().caretakers.insert(std::make_pair(imgId,new Caretaker()));

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
    CVImage *cvimage = getActiveImage();
    Caretaker *caretaker = getActiveCaretaker();
    ImageProcessor::getInstance().restore(*cvimage,caretaker->getUndoMemento());
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
}

void MainWindow::redo() {
    qDebug("redo");
}

void MainWindow::setBrightness() {
    CVImage *cvimage = getActiveImage();
    QMdiSubWindow *sub = ui->mdiArea->activeSubWindow();
    brightnessDialog dlg;
    char type;
    int value;
    if (dlg.exec()) {
        value = dlg.getValue().second;
        type = dlg.getValue().first;
    }
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().changeBrightness(*cvimage,type,value);
    ui->mdiArea->setActiveSubWindow(sub);
}


void MainWindow::dockMoved(Qt::DockWidgetArea area) {
    if ( area == Qt::LeftDockWidgetArea )
        tabWidget->setTabPosition(QTabWidget::West);
    else if ( area == Qt::RightDockWidgetArea )
        tabWidget->setTabPosition(QTabWidget::East);
    else
        tabWidget->setTabPosition(QTabWidget::North);
}

void MainWindow::mdiWindowStateChanged(Qt::WindowStates oldState,Qt::WindowStates newState) {
    if ( newState == Qt::WindowActive ) {
        CVImage *cvimage = getActiveImage();
        transformList->clear();
        if ( cvimage == NULL )
            return;
        transformList->addItems(cvimage->transformStringList());
        //Ustalenie czy można wykonać akcje undo i redo
        if ( getActiveCaretaker()->undoList.empty() )
            ui->undoAction->setEnabled(false);
        else
            ui->undoAction->setEnabled(true);
        if ( getActiveCaretaker()->redoList.empty() )
            ui->redoAction->setEnabled(false);
        else
            ui->redoAction->setEnabled(true);
    }
    //jeśli zamykamy ostatni obrazek
    else if ( Model::getInstance().images.size() == 0 )
        transformList->clear();
}

void MainWindow::smoothAverage3x3() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothAverage3x3(*cvimage);
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
}

void MainWindow::smoothAverage5x5() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothAverage5x5(*cvimage);
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
}

void MainWindow::smoothMedian3x3() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothMedian3x3(*cvimage);
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
}

void MainWindow::smoothMedian5x5() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothMedian5x5(*cvimage);
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
}

void MainWindow::smoothGaussian() {
    qDebug() << "Gau";
}

void MainWindow::smoothBilateral() {
    qDebug() << "Bil";
}

CVImage* MainWindow::getActiveImage() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return NULL;
    }
    int id = ((DarqImage *)sub->widget())->id;
    return Model::getInstance().images.find(id)->second;
}

Caretaker* MainWindow::getActiveCaretaker() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    int id = ((DarqImage *)sub->widget())->id;
    return CaretakerModel::getInstance().caretakers.find(id)->second;
}

void MainWindow::saveToHistory(const CVImage& cvimage) {
    Caretaker *caretaker = getActiveCaretaker();
    caretaker->undoList.push_back(new Memento(cvimage.transforms,cvimage.mat));
}

void MainWindow::closeSubWindow() {
    qDebug() << "abc";
}
