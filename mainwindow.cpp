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
#include "bilateraldialog.h"
#include "thresholddialog.h"
#include "cannydialog.h"

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
    ui->saveAction->setEnabled(false);
    ui->saveAsAction->setEnabled(false);
    ui->pointAction->setEnabled(false);
    selectionMode = false;
    //Full screen
    const int width = QApplication::desktop()->width();
    const int height = QApplication::desktop()->height();
    resize(width,height);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete transformList;
    delete tabWidget;
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
    connect(ui->selectAction, SIGNAL(triggered()), this, SLOT(select()));
    connect(ui->pointAction, SIGNAL(triggered()), this, SLOT(point()));
    connect(ui->brightnessAction, SIGNAL(triggered()), this, SLOT(setBrightness()));
    connect(ui->avg3x3Action, SIGNAL(triggered()), this, SLOT(smoothAverage3x3()));
    connect(ui->avg5x5Action, SIGNAL(triggered()), this, SLOT(smoothAverage5x5()));
    connect(ui->med3x3Action, SIGNAL(triggered()), this, SLOT(smoothMedian3x3()));
    connect(ui->med5x5Action, SIGNAL(triggered()), this, SLOT(smoothMedian5x5()));
    connect(ui->smoothGaussianAction, SIGNAL(triggered()), this, SLOT(smoothGaussian()));
    connect(ui->smoothBilateralAction, SIGNAL(triggered()), this, SLOT(smoothBilateral()));
    connect(ui->erodeAction, SIGNAL(triggered()), this, SLOT(erode()));
    connect(ui->dilateAction, SIGNAL(triggered()), this, SLOT(dilate()));
    connect(ui->openingAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->closeAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->gradientAction, SIGNAL(triggered()), this, SLOT(morphologicalGradient()));
    connect(ui->thresholdAction, SIGNAL(triggered()), this, SLOT(threshold()));
    connect(ui->sobelAction, SIGNAL(triggered()), this, SLOT(sobel()));
    connect(ui->laplacianAction, SIGNAL(triggered()), this, SLOT(laplacian()));
    connect(ui->cannyAction, SIGNAL(triggered()), this, SLOT(canny()));
    connect(ui->scharrAction, SIGNAL(triggered()), this, SLOT(scharr()));
    connect(ui->dockWidget,SIGNAL(dockLocationChanged(Qt::DockWidgetArea)),this,SLOT(dockMoved(Qt::DockWidgetArea)));
    connect(ui->grayscaleAction, SIGNAL(triggered()), this, SLOT(convertToGrayscale()));
    connect(ui->RGBAction, SIGNAL(triggered()), this, SLOT(convertToRGB()));
    connect(ui->showHistogramAction, SIGNAL(triggered()), this, SLOT(showHistogram()));
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
    CVImage *cvimg = new CVImage(fileName);
    DarqImage *img;
    if ( cvimg->mat.type() == CV_8UC1 ) {
        img = new DarqImage(fileName,imgId,selectionMode,cvimg->rgb);
        ui->grayscaleAction->setChecked(true);
    }
    else if ( cvimg->mat.type() == CV_8UC3 ) {
        img = new DarqImage(fileName,imgId,selectionMode,cvimg->mat);
        ui->RGBAction->setChecked(true);
    }
    cvimg->setObserver(img);
    Model::getInstance().images.insert(std::make_pair(imgId,cvimg));
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
    connect(sub,SIGNAL(allClosed()),this,SLOT(allClosed()));
    if ( imgWidth < width && imgHeight < height )
        sub->resize(imgWidth+10,imgHeight+30);
    else if ( imgWidth > width && imgHeight > height )
        sub->resize(width-75,height-50);
    else if ( imgWidth < width && imgHeight > height )
        sub->resize(imgWidth,height-50);
    else
        sub->resize(width-75,imgHeight);
    img->show();
    ui->undoAction->setEnabled(false);
    ui->redoAction->setEnabled(false);
}

void MainWindow::saveFile() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    DarqImage* img = (DarqImage *)sub->widget();
    getActiveImage()->save(img->path);
    ui->saveAction->setEnabled(false);
}

void MainWindow::saveFileAs() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    DarqImage* img = (DarqImage *)sub->widget();
    QString filePath = QFileDialog::getSaveFileName(this,"Save File",img->path,"Images(*.png *.xpm *.jpg *.JPG *.bmp);;All Files(*)");
    if ( !filePath.isNull() ) {
        getActiveImage()->save(filePath);
        img->path = filePath;
        sub->setWindowTitle(filePath);
        ui->saveAction->setEnabled(false);
    }
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About Darqwin"),
                 tr("<p>Darkroom Qt</p>\nDeveloped by Michał Bobowski 2012"));
}

void MainWindow::quit() {
    exit(0);
}

void MainWindow::undo() {
    CVImage *cvimage = getActiveImage();
    Caretaker *caretaker = getActiveCaretaker();
    ImageProcessor::getInstance().restore(*cvimage,caretaker->getUndoMemento(new Memento(cvimage->transforms,cvimage->mat)));
    refreshGUI(*cvimage);
    //Ustalenie stanu akcji undo/redo
    ui->redoAction->setEnabled(true);
    if ( getActiveCaretaker()->undoList.empty() ) {
        ui->saveAction->setEnabled(false);
        ui->undoAction->setEnabled(false);
    }
    else {
        ui->undoAction->setEnabled(true);
        ui->saveAction->setEnabled(true);
    }
    //Ustalenie stanu GUI w zależności czy obraz jest w RGB czy w grayscale
    if ( getActiveImage()->mat.type() == CV_8UC1 ) {
        ui->grayscaleAction->setChecked(true);
        ui->RGBAction->setChecked(false);
    }
    else {
        ui->grayscaleAction->setChecked(false);
        ui->RGBAction->setChecked(true);
    }
}

void MainWindow::redo() {
    CVImage *cvimage = getActiveImage();
    Caretaker *caretaker = getActiveCaretaker();
    ImageProcessor::getInstance().restore(*cvimage,caretaker->getRedoMemento(new Memento(cvimage->transforms,cvimage->mat)));
    refreshGUI(*cvimage);
    //Ustalenie stanu akcji undo/redo
    ui->undoAction->setEnabled(true);
    if ( getActiveCaretaker()->redoList.empty() )
        ui->redoAction->setEnabled(false);
    else
        ui->redoAction->setEnabled(true);
    //Ustalenie stanu GUI w zależności czy obraz jest w RGB czy w grayscale
    if ( getActiveImage()->mat.type() == CV_8UC1 ) {
        ui->grayscaleAction->setChecked(true);
        ui->RGBAction->setChecked(false);
    }
    else {
        ui->grayscaleAction->setChecked(false);
        ui->RGBAction->setChecked(true);
    }
}

void MainWindow::setBrightness() {
    CVImage *cvimage = getActiveImage();
    QMdiSubWindow *sub = ui->mdiArea->activeSubWindow();
    brightnessDialog dlg;
    char type;
    int value;
    if (cvimage->mat.type() == CV_8UC1)
        dlg.setGrayscaleButtons();
    if (dlg.exec() && dlg.getValue().second != 0) {
        value = dlg.getValue().second;
        type = dlg.getValue().first;
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().changeBrightness(*cvimage,type,value);
        refreshGUI(*cvimage);
    }
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

void MainWindow::mdiWindowStateChanged(Qt::WindowStates,Qt::WindowStates newState) {
    if ( newState == Qt::WindowActive ) {
        CVImage *cvimage = getActiveImage();
        transformList->clear();
        if ( cvimage == NULL )
            return;
        transformList->addItems(cvimage->transformStringList());
        // akcje undo/redo
        if ( getActiveCaretaker()->undoList.empty() )
            ui->undoAction->setEnabled(false);
        else
            ui->undoAction->setEnabled(true);
        if ( getActiveCaretaker()->redoList.empty() )
            ui->redoAction->setEnabled(false);
        else
            ui->redoAction->setEnabled(true);
        // akcja save
        QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
        if ( sub == NULL ) {
            QMessageBox::information(this, tr("Darqwin"),
                                     tr("No active subwindow"));
            return;
        }
        int id = ((DarqImage *)sub->widget())->id;
        if ( CaretakerModel::getInstance().caretakers.find(id)->second->undoList.empty() )
            ui->saveAction->setEnabled(false);
        else
            ui->saveAction->setEnabled(true);
        // akcje formatu obrazka
        if ( cvimage->mat.type() == CV_8UC1 ) {
            ui->grayscaleAction->setChecked(true);
            ui->RGBAction->setChecked(false);
        }
        else {
            ui->grayscaleAction->setChecked(false);
            ui->RGBAction->setChecked(true);
        }
    }
}

void MainWindow::smoothAverage3x3() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothAverage3x3(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothAverage5x5() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothAverage5x5(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothMedian3x3() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothMedian3x3(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothMedian5x5() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothMedian5x5(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothGaussian() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothGaussian(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothBilateral() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    BilateralDialog dlg;
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().smoothBilateral(*cvimage,dlg.getDiameter(),
                                                      dlg.getSigmaColor(),dlg.getSigmaSpace(),getSelection());
        refreshGUI(*cvimage);
    }
    ui->mdiArea->setActiveSubWindow(sub);
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

void MainWindow::refreshGUI(CVImage& cvimage) {
    transformList->clear();
    transformList->addItems(cvimage.transformStringList());
    ui->undoAction->setEnabled(true);
    ui->saveAction->setEnabled(true);
    ui->saveAsAction->setEnabled(true);
}

void MainWindow::select() {
    selectionMode = true;
    QList<QMdiSubWindow*> list = ui->mdiArea->subWindowList();
    for ( QList<QMdiSubWindow*>::iterator it = list.begin(); it != list.end(); it++ ) {
        DarqImage *current = (DarqImage*)(*it)->widget();
        current->selectionMode = true;
    }
    ui->selectAction->setEnabled(false);
    ui->pointAction->setEnabled(true);
}

void MainWindow::point() {
    selectionMode = false;
    QList<QMdiSubWindow*> list = ui->mdiArea->subWindowList();
    for ( QList<QMdiSubWindow*>::iterator it = list.begin(); it != list.end(); it++ ) {
        DarqImage *current = (DarqImage*)(*it)->widget();
        current->selectionMode = false;
    }
    ui->pointAction->setEnabled(false);
    ui->selectAction->setEnabled(true);
}

QRect MainWindow::getSelection() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();

    return ((DarqImage*)sub->widget())->getRect();
}

void MainWindow::erode() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().erode(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::dilate() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().dilate(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::open() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().open(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::close() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().close(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::morphologicalGradient() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().gradient(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::threshold() {
    ThresholdDialog dlg;
    int mode, value;
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        mode = dlg.getMode();
        value = dlg.getValue();
        ImageProcessor::getInstance().thresh(*cvimage,mode,value);
        refreshGUI(*cvimage);
    }
}

void MainWindow::sobel() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().sobel(*cvimage);
    refreshGUI(*cvimage);
    //wynikowy obraz jest w graysacale
    ui->grayscaleAction->setChecked(true);
    ui->RGBAction->setChecked(false);
}

void MainWindow::laplacian() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().laplace(*cvimage);
    refreshGUI(*cvimage);
    //wynikowy obraz jest w graysacale
    ui->grayscaleAction->setChecked(true);
    ui->RGBAction->setChecked(false);
}

void MainWindow::canny() {
    CannyDialog dlg;
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().canny(*cvimage,dlg.getValue());
        refreshGUI(*cvimage);
        //wynikowy obraz jest w graysacale
        ui->grayscaleAction->setChecked(true);
        ui->RGBAction->setChecked(false);
    }
}

void MainWindow::scharr() {
    CVImage *cvimage = getActiveImage();
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().scharr(*cvimage);
    refreshGUI(*cvimage);
    //wynikowy obraz jest w graysacale
    ui->grayscaleAction->setChecked(true);
    ui->RGBAction->setChecked(false);
}

void MainWindow::closeEvent(QCloseEvent *e) {
    std::map<int,Caretaker*> caretakers = CaretakerModel::getInstance().caretakers;
    for ( std::map<int,Caretaker*>::iterator it = caretakers.begin(); it != caretakers.end(); it++ ) {
        Caretaker *c = it->second;
        if ( !c->undoList.empty() ) {
            QMessageBox msgBox;
            msgBox.setText("One or more image(s) has been modified.");
            msgBox.setInformativeText("Close without saving?");
            msgBox.setStandardButtons( QMessageBox::Cancel | QMessageBox::Yes);
            msgBox.setDefaultButton(QMessageBox::Cancel);
            int ret = msgBox.exec();
            switch (ret) {
               case QMessageBox::Yes:
                   break;
               case QMessageBox::Cancel:
                   e->ignore();
                   return;
             }
        }
    }
}

void MainWindow::convertToGrayscale() {
    CVImage *cvimage = getActiveImage();
    if ( cvimage->mat.type() == CV_8UC1 )
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().convertToGrayscale(*cvimage);
    refreshGUI(*cvimage);
    ui->grayscaleAction->setChecked(true);
    ui->RGBAction->setChecked(false);
}

void MainWindow::convertToRGB() {
    CVImage *cvimage = getActiveImage();
    if ( cvimage->mat.type() == CV_8UC3 )
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().convertToRGB(*cvimage);
    refreshGUI(*cvimage);
    ui->grayscaleAction->setChecked(false);
    ui->RGBAction->setChecked(true);
}

void MainWindow::showHistogram() {
    qDebug("Show Histogram");
}

void MainWindow::allClosed() {
    transformList->clear();
    ui->saveAction->setEnabled(false);
    ui->saveAsAction->setEnabled(false);
    ui->undoAction->setEnabled(false);
    ui->redoAction->setEnabled(false);
    ui->grayscaleAction->setChecked(false);
    ui->RGBAction->setChecked(false);
}
