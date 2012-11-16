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
#include "sizehintlistwidget.h"
#include "rankfilterdialog.h"
#include "customfilterdialog.h"
#include "algorithmparser.h"
#include "transformation.h"
#include "logicalfilterdialog.h"
#include "cutoffdialog.h"
#include "bandpassdialog.h"
#include "butterworthdialog.h"

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
    connect(ui->histogramAction, SIGNAL(triggered()), this, SLOT(showHistogram()));
    connect(ui->equalizeAction, SIGNAL(triggered()), this, SLOT(equalizeHistogram()));
    connect(ui->saveAlgorithmAction, SIGNAL(triggered()), this, SLOT(saveAlgorithm()));
    connect(ui->openAlgorithmAction, SIGNAL(triggered()), this, SLOT(openAlgorithm()));
    connect(ui->saveProjectAction, SIGNAL(triggered()), this, SLOT(saveProject()));
    connect(ui->rankFilterAction, SIGNAL(triggered()), this, SLOT(rankFilter()));
    connect(ui->customFilterAction, SIGNAL(triggered()), this, SLOT(customFilter()));
    connect(ui->logicalFilterAction, SIGNAL(triggered()), this, SLOT(logicalFilter()));
    connect(ui->FFTAction, SIGNAL(triggered()), this, SLOT(FFT()));
    connect(ui->idealHighPassAction, SIGNAL(triggered()), this, SLOT(idealHighPass()));
    connect(ui->idealLowPassAction, SIGNAL(triggered()), this, SLOT(idealLowPass()));
    connect(ui->gaussianHighPassAction, SIGNAL(triggered()), this, SLOT(gaussianHighPass()));
    connect(ui->gaussianLowPassAction, SIGNAL(triggered()), this, SLOT(gaussianLowPass()));
    connect(ui->butterworthHighPassFilter, SIGNAL(triggered()), this, SLOT(butterworthHighPass()));
    connect(ui->butterworthLowPassAction, SIGNAL(triggered()), this, SLOT(butterworthLowPass()));
    connect(ui->bandPassFilterAction, SIGNAL(triggered()), this, SLOT(bandPass()));
}

void MainWindow::createTabs() {
    tabWidget = new sizeHintTabWidget(ui->dockWidget);
    tabWidget->setTabPosition(QTabWidget::East);
    ui->dockWidget->setWidget(tabWidget);

    //transform tab
    transformWidget = new QWidget;
    tabWidget->addTab(transformWidget, tr("Transform"));
    transformList = new SizeHintListWidget(transformWidget);

    //help tab
    helpWidget = new QWidget;
    tabWidget->addTab(helpWidget, tr("Help"));
    webView = new QWebView(helpWidget);
    webView->load(QUrl("file:///home/preston/programy/DarQwin/help/index.html"));
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
    //Połączenie do wykrywania zamknięcia wszystkich okien
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
    ui->saveAsAction->setEnabled(true);
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
    getActiveCaretaker()->dirtyCounter = 0;
}

void MainWindow::saveFileAs() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    DarqImage* img = (DarqImage *)sub->widget();
    show_file_dialog:
    QString filePath = QFileDialog::getSaveFileName(this,"Save File",img->path);
    if ( !filePath.isNull() ) {
        if ( getActiveImage()->save(filePath) != 0 )
            goto show_file_dialog;
        img->path = filePath;
        sub->setWindowTitle(filePath);
        ui->saveAction->setEnabled(false);
        getActiveCaretaker()->dirtyCounter = 0;
    }
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About Darqwin"),
                 tr("<p>Darkroom Qt</p>\nCreated by Michal Bobowski 2012"));
}

void MainWindow::quit() {
    exit(0);
}

void MainWindow::undo() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    Caretaker *caretaker = getActiveCaretaker();
    ImageProcessor::getInstance().restore(*cvimage,caretaker->getUndoMemento(new Memento(cvimage->transforms,cvimage->mat)));
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
    ui->saveAction->setEnabled(true);
    ui->saveAsAction->setEnabled(true);
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
    if (cvimage == NULL)
        return;
    Caretaker *caretaker = getActiveCaretaker();
    ImageProcessor::getInstance().restore(*cvimage,caretaker->getRedoMemento(new Memento(cvimage->transforms,cvimage->mat)));
    transformList->clear();
    transformList->addItems(cvimage->transformStringList());
    ui->saveAction->setEnabled(true);
    ui->saveAsAction->setEnabled(true);
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
    if (cvimage == NULL)
        return;
    QMdiSubWindow *sub = ui->mdiArea->activeSubWindow();
    brightnessDialog dlg;
    connect(&dlg,SIGNAL(preview(char,int)),this,SLOT(previewBrightness(char,int)));
    char type;
    int value;
    if (cvimage->mat.type() == CV_8UC1)
        dlg.setGrayscaleButtons();
    if (dlg.exec() && dlg.getValue().second != 0) {
        value = dlg.getValue().second;
        type = dlg.getValue().first;
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().changeBrightness(*cvimage,type,value,true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
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
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothAverage3x3(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothAverage5x5() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothAverage5x5(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothMedian3x3() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothMedian3x3(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothMedian5x5() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().smoothMedian5x5(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::smoothGaussian() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
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
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewBilateral(int,int,int)));
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().smoothBilateral(*cvimage,dlg.getDiameter(),
                                                      dlg.getSigmaColor(),dlg.getSigmaSpace(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    else {
        CVImage *cvimage = getActiveImage();
        cvimage->notify();
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
    getActiveCaretaker()->dirtyCounter++;
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
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().erode(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::dilate() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
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
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().close(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::morphologicalGradient() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().gradient(*cvimage,getSelection());
    refreshGUI(*cvimage);
}

void MainWindow::threshold() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    ThresholdDialog dlg;
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewThreshold(int,int)));
    int mode, value;
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        mode = dlg.getMode();
        value = dlg.getValue();
        ImageProcessor::getInstance().thresh(*cvimage,mode,value,true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::sobel() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().sobel(*cvimage);
    refreshGUI(*cvimage);
    //wynikowy obraz jest w graysacale
    ui->grayscaleAction->setChecked(true);
    ui->RGBAction->setChecked(false);
}

void MainWindow::laplacian() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().laplace(*cvimage);
    refreshGUI(*cvimage);
    //wynikowy obraz jest w graysacale
    ui->grayscaleAction->setChecked(true);
    ui->RGBAction->setChecked(false);
}

void MainWindow::canny() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    CannyDialog dlg;
    connect(&dlg,SIGNAL(preview(int)),this,SLOT(previewCanny(int)));
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().canny(*cvimage,dlg.getValue(),true);
        refreshGUI(*cvimage);
        //wynikowy obraz jest w graysacale
        ui->grayscaleAction->setChecked(true);
        ui->RGBAction->setChecked(false);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::scharr() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
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
        if ( c->dirtyCounter != 0 ) {
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
    if (cvimage == NULL) {
        ui->grayscaleAction->setChecked(false);;
        return;
    }
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
    if (cvimage == NULL) {
        ui->RGBAction->setChecked(false);;
        return;
    }
    if ( cvimage->mat.type() == CV_8UC3 )
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().convertToRGB(*cvimage);
    refreshGUI(*cvimage);
    ui->grayscaleAction->setChecked(false);
    ui->RGBAction->setChecked(true);
}

void MainWindow::showHistogram() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    ImageProcessor::getInstance().showHistogram(*cvimage);
}

void MainWindow::equalizeHistogram() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    saveToHistory(*cvimage);
    ImageProcessor::getInstance().equalize(*cvimage);
    refreshGUI(*cvimage);
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

void MainWindow::saveAlgorithm() {
   if ( transformList->count() == 0 ) {
       QMessageBox::information(this, tr("Darqwin"),
                                tr("Transformation list is empty"));
       return;
   }
   QString filePath = QFileDialog::getSaveFileName(this,"Save Algorithm","algorithm.xml");
   if ( !filePath.isNull() ) {
       QFile file(filePath);
       if ( file.open(QIODevice::WriteOnly) ) {
           QTextStream stream( &file );
           stream << "<?xml version=\"1.0\" encoding=\"ASCII\" standalone=\"yes\"?>" << "\n";
           stream << "<algorithm>" << "\n";
           for ( std::list<Transformation*>::iterator it = getActiveImage()->transforms.begin(); it != getActiveImage()->transforms.end() ;it++ ) {
               QStringList lines = (*it)->getXML();
               for ( QStringList::Iterator iter = lines.begin(); iter != lines.end(); ++iter )
                   stream << *iter << "\n";
           }

           stream << "</algorithm>" << "\n";
           file.close();
       }
   }
}

void MainWindow::openAlgorithm() {
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Algorithm File"), QDir::currentPath());
    if ( fileName.isEmpty() )
        return;
    QDomDocument doc("mydocument");
    QFile file(fileName);
    if ( !file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("Cannot load %1.").arg(fileName).append("\nUnable to open file"));
        return;
    }
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    algorithmParser parser(doc);
    std::vector<Transformation*> transforms;
    if ( parser.parse(transforms) != 0 ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("Cannot load %1.").arg(fileName).append("\nParsing error occured"));
        //porządki
        for ( std::vector<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
            delete *it;
        }
        return;
    }

    for ( std::vector<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
        saveToHistory(*cvimage);
        if ( ImageProcessor::getInstance().processTransformation(*cvimage,*it) != 0 ) {
            //wystąpił błąd
            QMessageBox::information(this, tr("Darqwin"),
                                     tr("Processing error with file: %1.").arg(fileName).append("\nImage format does not meet algorithm requirments"));
        }
        refreshGUI(*cvimage);
        delete *it;
    }

}

void MainWindow::saveProject() {
   qDebug() << "Save Project";
}

void MainWindow::rankFilter() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
   rankFilterDialog dlg;
   connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewRankFilter(int,int)));
   if ( dlg.exec() ) {
       CVImage *cvimage = getActiveImage();
       saveToHistory(*cvimage);
       ImageProcessor::getInstance().rankFilter(*cvimage,getSelection(),dlg.getValue(),dlg.getSize(),true);
       refreshGUI(*cvimage);
   }
   else {
       getActiveImage()->notify();
   }
   ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::customFilter() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
    CustomFilterDialog dlg;
    connect(&dlg,SIGNAL(preview(int,std::vector<float>)),this,SLOT(previewCustomFilter(int,std::vector<float>)));
    if ( dlg.exec() ) {
        CVImage *cvimage = getActiveImage();
        saveToHistory(*cvimage);
        std::vector<float> params;
        dlg.getParams(params);
        ImageProcessor::getInstance().customFilter(*cvimage,getSelection(),params,dlg.getDivisor(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewBilateral(int diameter, int sigmaC, int sigmaS) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);
    ImageProcessor::getInstance().smoothBilateral(preview,diameter,sigmaC,sigmaS,getSelection(),false);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewBrightness(char type, int value) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);
    ImageProcessor::getInstance().changeBrightness(preview,type,value,false);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewCanny(int value) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);
    ImageProcessor::getInstance().canny(preview,value,false);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewRankFilter(int size, int value) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);
    ImageProcessor::getInstance().rankFilter(preview,getSelection(),size,value,false);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewThreshold(int mode, int value) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);
    ImageProcessor::getInstance().thresh(preview,mode,value,false);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewCustomFilter(int divisor,std::vector<float> vec) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);
    ImageProcessor::getInstance().customFilter(preview,getSelection(),vec,divisor,false);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::logicalFilter() {
    qDebug() << "Logical filter";
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    ImageProcessor::getInstance().logicalFilter(*cvimage,getSelection());
}

void MainWindow::FFT() {
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    ImageProcessor::getInstance().calculateFFT(*cvimage,getSelection());
}

void MainWindow::idealLowPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    CutoffDialog dlg(LOW_IDEAL);
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().idealLowPass(*cvimage,dlg.getCutoff(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::gaussianLowPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    CutoffDialog dlg(LOW_GAUSSIAN);
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().gaussianLowPass(*cvimage,dlg.getCutoff(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::idealHighPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    CutoffDialog dlg(HIGH_IDEAL);
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().idealHighPass(*cvimage,dlg.getCutoff(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::gaussianHighPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    CutoffDialog dlg(HIGH_GAUSSIAN);
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().gaussianHighPass(*cvimage,dlg.getCutoff(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::butterworthHighPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    ButterworthDialog dlg(BUTTERWORTH_HIGH_PASS);
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().butterworthHighPass(*cvimage,dlg.getCutoff(),dlg.getOrder(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::butterworthLowPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    saveToHistory(*cvimage);
    ButterworthDialog dlg(BUTTERWORTH_LOW_PASS);
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().butterworthLowPass(*cvimage,dlg.getCutoff(),dlg.getOrder(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::bandPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    saveToHistory(*cvimage);
    BandPassDialog dlg;
    if ( dlg.exec() ) {
        ImageProcessor::getInstance().bandPass(*cvimage,dlg.getInner(),dlg.getOuter(),getSelection());
    }
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}
