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
#include "hsvdialog.h"
#include "resizedialog.h"
#include "noisedialog.h"
#include "morphdialog.h"
#include "sizehintwebview.h"

#include "transbilateral.h"
#include "transbrightness.h"
#include "transcanny.h"
#include "transcustomfilter.h"
#include "transfourierhigh.h"
#include "transfourierlow.h"
#include "transbandpass.h"
#include "transhsv.h"
#include "transrankfilter.h"
#include "translogical.h"
#include "transopen.h"
#include "transclose.h"
#include "transdilate.h"
#include "transerode.h"
#include "transgradient.h"

#include <highgui.h>

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("DarQwin"));
    createConnections();
    helpConfig();
    createTabs();
    ui->undoAction->setEnabled(false);
    ui->redoAction->setEnabled(false);
    ui->saveAction->setEnabled(false);
    ui->saveAsAction->setEnabled(false);
    ui->pointAction->setEnabled(false);
    selectionMode = false;
    //Full screen
    showMaximized();

    webView->setFixedHeight(QApplication::desktop()->height() - 200);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete transformList;
    delete tabWidget;
    delete helpModel;
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
    connect(ui->hueSaturationAction, SIGNAL(triggered()), this, SLOT(hsv()));
    connect(ui->resizeAction, SIGNAL(triggered()), this, SLOT(resizeImg()));
    connect(ui->noiseAction, SIGNAL(triggered()), this, SLOT(noise()));
    connect(ui->DCTAction, SIGNAL(triggered()), this, SLOT(DCT()));
    connect(ui->locateHelpAction, SIGNAL(triggered()), this, SLOT(locateHelp()));
}

void MainWindow::helpConfig() {
    QDomDocument doc("mydocument");
    QFile file("config.xml");
    if ( !file.open(QIODevice::ReadOnly)) {
        QString info = "Config file not found - creating config.xml.";
        info.append('\n');
        info.append("Fill the file with URLs or use 'Settings' menu to locate help index");
        QMessageBox::information(this, tr("Darqwin"),
                                 info);

        helpModel = new HelpModel();
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        helpModel->createConfig(out,QString(""));
        file.close();
        return;
    }

    if (!doc.setContent(&file)) {
        file.close();
        return;
    }

    helpModel = new HelpModel(doc);
    file.close();
}

void MainWindow::createTabs() {
    tabWidget = new sizeHintTabWidget(ui->dockWidget);
    tabWidget->setTabPosition(QTabWidget::East);
    ui->dockWidget->setWidget(tabWidget);

    //transform tab
    transformWidget = new QWidget;
    tabWidget->addTab(transformWidget, tr("Transform"));
    transformList = new SizeHintListWidget(transformWidget);
    connect(transformList,SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(listActivated(QListWidgetItem*)));

    //help tab
    helpWidget = new QWidget;
    tabWidget->addTab(helpWidget, tr("Help"));
    webView = new SizeHintWebView(helpWidget);
    QString path = helpModel->find(CONFIG_INDEX);
    if ( path != "" ) {
        webView->load(QUrl(path));
    }
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
        sub->resize(imgWidth+10,imgHeight+36);
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
                       QString::fromUtf8("<p>Darkroom Qt</p>\nCreated by Michał Bobowski 2012"));
}

void MainWindow::quit() {
    exit(0);
}

void MainWindow::undo() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    Caretaker *caretaker = getActiveCaretaker();
    Memento* undoMem = caretaker->getUndoMemento(new Memento(cvimage->transforms,cvimage->mat));
    ImageProcessor::getInstance().restore(*cvimage,undoMem,true);
    delete undoMem;
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
        ui->menu_Transform->setEnabled(true);
    }
    else {
        ui->grayscaleAction->setChecked(false);
        ui->RGBAction->setChecked(true);
        ui->menu_Transform->setEnabled(false);
    }
}

void MainWindow::redo() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    Caretaker *caretaker = getActiveCaretaker();
    Memento* redoMem = caretaker->getRedoMemento(new Memento(cvimage->transforms,cvimage->mat));
    ImageProcessor::getInstance().restore(*cvimage,redoMem,true);
    delete redoMem;
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
        ui->menu_Transform->setEnabled(true);
    }
    else {
        ui->grayscaleAction->setChecked(false);
        ui->RGBAction->setChecked(true);
        ui->menu_Transform->setEnabled(false);
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
        ImageProcessor::getInstance().changeBrightness(*cvimage,type,value,getSelection(),true);
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
        if ( CaretakerModel::getInstance().caretakers.find(id)->second->dirtyCounter == 0 )
            ui->saveAction->setEnabled(false);
        else
            ui->saveAction->setEnabled(true);
        // akcje zależne od formatu obrazka
        if ( cvimage->mat.type() == CV_8UC1 ) {
            ui->grayscaleAction->setChecked(true);
            ui->RGBAction->setChecked(false);
            ui->menu_Transform->setEnabled(true);
            ui->hueSaturationAction->setEnabled(false);
        }
        else {
            ui->grayscaleAction->setChecked(false);
            ui->RGBAction->setChecked(true);
            ui->menu_Transform->setDisabled(true);
            ui->hueSaturationAction->setEnabled(true);
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
    connect(&dlg,SIGNAL(help()),this,SLOT(helpBilateral()));
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
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;

    MorphDialog dlg(ERODE);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewMorph(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpMorph()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().erode(*cvimage,dlg.getIterations(),dlg.getSize(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::dilate() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;

    MorphDialog dlg(DILATE);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewMorph(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpMorph()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().dilate(*cvimage,dlg.getIterations(),dlg.getSize(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::open() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;

    MorphDialog dlg(OPEN);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewMorph(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpMorph()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().open(*cvimage,dlg.getIterations(),dlg.getSize(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::close() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;

    MorphDialog dlg(CLOSE);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewMorph(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpMorph()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().close(*cvimage,dlg.getIterations(),dlg.getSize(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::morphologicalGradient() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;

    MorphDialog dlg(GRADIENT);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewMorph(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpMorph()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().gradient(*cvimage,dlg.getIterations(),dlg.getSize(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
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
    connect(&dlg,SIGNAL(help()),this,SLOT(helpThresh()));
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
    connect(&dlg,SIGNAL(help()),this,SLOT(helpCanny()));
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
    ui->hueSaturationAction->setEnabled(false);
    ui->menu_Transform->setEnabled(true);
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
    ui->hueSaturationAction->setEnabled(true);
    ui->menu_Transform->setEnabled(false);
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

void MainWindow::rankFilter() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( sub == NULL ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("No active subwindow"));
        return;
    }
   rankFilterDialog dlg;
   connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewRankFilter(int,int)));
   connect(&dlg,SIGNAL(help()),this,SLOT(helpRank()));
   if ( dlg.exec() ) {
       QProgressDialog *progress = new QProgressDialog("Operation in progress...",QString(),0,100,this);
       progress->show();
       progress->setModal(true);
       CVImage *cvimage = getActiveImage();
       saveToHistory(*cvimage);
       ImageProcessor::getInstance().rankFilter(*cvimage,getSelection(),dlg.getValue(),dlg.getSize(),true,progress);
       refreshGUI(*cvimage);
       delete progress;
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
    connect(&dlg,SIGNAL(help()),this,SLOT(helpCustom()));
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
    ImageProcessor::getInstance().changeBrightness(preview,type,value,getSelection(),false);
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
    QProgressDialog *progress = new QProgressDialog("Operation in progress...",QString(),0,100,this);
    progress->show();
    progress->setModal(true);
    ImageProcessor::getInstance().rankFilter(preview,getSelection(),value,size,false,progress);
    if ( preview.mat.type() == CV_8UC3 )
        darqimg->repaint(preview.mat,false);
    else {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    delete progress;
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
    CVImage *cvimage = getActiveImage();
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    if ( cvimage == NULL )
        return;

    bool rgb = true;
    if ( getActiveImage()->mat.type() == CV_8UC1 )
        rgb = false;
    logicalFilterDialog dlg(rgb);
    connect(&dlg,SIGNAL(preview(QString,QStringList,QStringList)),this,SLOT(previewLogic(QString,QStringList,QStringList)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpLogic()));
    show_dlg_logic:
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        // na podstawie kodu błędu określam komunikat
        QProgressDialog *progress = new QProgressDialog("Operation in progress...",QString(),0,100,this);
        progress->show();
        progress->setModal(true);
        int result = ImageProcessor::getInstance().logicalFilter(*cvimage, dlg.getIf(), dlg.getThen(), dlg.getElse(),
                                                         getSelection(), true, progress);
        delete progress;
        if ( result == 1 ) {
            QMessageBox::information(this, tr("Darqwin"),
                                     tr("Error").append("\nParse error in Then/Else statement"));
            goto show_dlg_logic;
        }
        else if ( result == 2 ) {
            QMessageBox::information(this, tr("Darqwin"),
                                     tr("Error").append("\nParse error in If statement"));
            goto show_dlg_logic;
        }

        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
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

    CutoffDialog dlg(LOW_IDEAL);
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewFourierCutoff(int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpIdeal()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().idealLowPass(*cvimage,dlg.getCutoff(),getSelection(),true);
    }
    getActiveImage()->notify();
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::gaussianLowPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;

    CutoffDialog dlg(LOW_GAUSSIAN);
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewFourierCutoff(int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpGauss()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().gaussianLowPass(*cvimage,dlg.getCutoff(),getSelection(),true);
    }
    getActiveImage()->notify();
    refreshGUI(*cvimage);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::idealHighPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;

    CutoffDialog dlg(HIGH_IDEAL);
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewFourierCutoff(int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpIdeal()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().idealHighPass(*cvimage,dlg.getCutoff(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    getActiveImage()->notify();
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::gaussianHighPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;

    CutoffDialog dlg(HIGH_GAUSSIAN);
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewFourierCutoff(int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpGauss()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().gaussianHighPass(*cvimage,dlg.getCutoff(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    getActiveImage()->notify();
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::butterworthHighPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;

    ButterworthDialog dlg(BUTTERWORTH_HIGH_PASS);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewFourierButterworth(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpButterworth()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().butterworthHighPass(*cvimage,dlg.getCutoff(),dlg.getOrder(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    getActiveImage()->notify();
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::butterworthLowPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;

    ButterworthDialog dlg(BUTTERWORTH_LOW_PASS);
    connect(&dlg,SIGNAL(preview(int,int,int)),this,SLOT(previewFourierButterworth(int,int,int)));
    connect(&dlg,SIGNAL(help()),this,SLOT(helpButterworth()));
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().butterworthLowPass(*cvimage,dlg.getCutoff(),dlg.getOrder(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    getActiveImage()->notify();
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::bandPass() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;

    BandPassDialog dlg;
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewBandPass(int,int)));
    show_dlg:
    if ( dlg.exec() ) {
        if ( dlg.getInner() >= dlg.getOuter() ) {
        QMessageBox::information(this, tr("Darqwin"),
                                 tr("Error").append("\nInner radius must be lower than outer"));
        goto show_dlg;
        }
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().bandPass(*cvimage,dlg.getInner(),dlg.getOuter(),getSelection(),true);
        refreshGUI(*cvimage);
    }
    getActiveImage()->notify();
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewFourierCutoff(int cutoff, int mode) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);

    if ( mode == LOW_IDEAL )
        ImageProcessor::getInstance().idealLowPass(preview, cutoff, getSelection() ,false);
    else if ( mode == LOW_GAUSSIAN )
        ImageProcessor::getInstance().gaussianLowPass(preview, cutoff, getSelection() ,false);
    else if ( mode == HIGH_IDEAL )
        ImageProcessor::getInstance().idealHighPass(preview, cutoff, getSelection() ,false);
    else if ( mode == HIGH_GAUSSIAN )
        ImageProcessor::getInstance().gaussianHighPass(preview, cutoff, getSelection() ,false);

    Mat rgb;
    cvtColor(preview.mat,rgb,CV_GRAY2RGB);
    darqimg->repaint(rgb,false);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewFourierButterworth(int cutoff, int order, int mode) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);

    if ( mode == BUTTERWORTH_LOW_PASS )
        ImageProcessor::getInstance().butterworthLowPass(preview, cutoff, order, getSelection() ,false);
    else if ( mode == BUTTERWORTH_HIGH_PASS )
        ImageProcessor::getInstance().butterworthHighPass(preview, cutoff, order, getSelection() ,false);

    Mat rgb;
    cvtColor(preview.mat,rgb,CV_GRAY2RGB);
    darqimg->repaint(rgb,false);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewBandPass(int inner, int outer) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);

    ImageProcessor::getInstance().bandPass(preview, inner, outer, getSelection() ,false);

    Mat rgb;
    cvtColor(preview.mat,rgb,CV_GRAY2RGB);
    darqimg->repaint(rgb,false);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::hsv() {
    CVImage *cvimage = getActiveImage();
    if (cvimage == NULL)
        return;
    QMdiSubWindow *sub = ui->mdiArea->activeSubWindow();
    HSVDialog dlg;
    connect(&dlg,SIGNAL(preview(int,int)),this,SLOT(previewHsv(int,int)));

    if (dlg.exec() && ( dlg.getHue() != 0 || dlg.getSaturation() != 0 ) ) {
        saveToHistory(*cvimage);
        ImageProcessor::getInstance().hsv(*cvimage,getSelection(),dlg.getHue(),dlg.getSaturation(),true);
        refreshGUI(*cvimage);
    }
    else {
        getActiveImage()->notify();
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::previewHsv(int hue, int saturation) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);

    ImageProcessor::getInstance().hsv(preview,getSelection(),hue,saturation,false);

    darqimg->repaint(preview.mat,false);
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::resizeImg() {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    Mat dst;

    ResizeDialog dlg(cvimage->mat.cols,cvimage->mat.rows);
    connect(&dlg,SIGNAL(help()),this,SLOT(helpResize()));
    int interpolation = dlg.getInterpolation();
    if ( dlg.exec() ) {        
        if ( dlg.getMode() == RESIZE_SCALE ) {
            //skalowanie
            cv::Size size(0,0);
            if ( interpolation == INTERPOLATION_BILINEAR )
                cv::resize(cvimage->mat,dst,size,dlg.getScaleX(),dlg.getScaleY(),INTER_LINEAR);
            else if ( interpolation == INTERPOLATION_NEAREST )
                cv::resize(cvimage->mat,dst,size,dlg.getScaleX(),dlg.getScaleY(),INTER_NEAREST);
            else if ( interpolation == INTERPOLATION_CUBIC )
                cv::resize(cvimage->mat,dst,size,dlg.getScaleX(),dlg.getScaleY(),INTER_CUBIC);
            else if ( interpolation == INTERPOLATION_LANCZOS )
                cv::resize(cvimage->mat,dst,size,dlg.getScaleX(),dlg.getScaleY(),INTER_LANCZOS4);
        }
        else {
            cv::Size size(dlg.getCustomX(),dlg.getCustomY());
            if ( interpolation == INTERPOLATION_BILINEAR )
                cv::resize(cvimage->mat,dst,size,0,0,INTER_LINEAR);
            else if ( interpolation == INTERPOLATION_NEAREST )
                cv::resize(cvimage->mat,dst,size,0,0,INTER_NEAREST);
            else if ( interpolation == INTERPOLATION_CUBIC )
                cv::resize(cvimage->mat,dst,size,0,0,INTER_CUBIC);
            else if ( interpolation == INTERPOLATION_LANCZOS )
                cv::resize(cvimage->mat,dst,size,0,0,INTER_LANCZOS4);

        }
        cvimage->mat = dst;
        sub->resize(dst.cols+10,dst.rows+30);
        cvimage->notify();
    }

    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::noise() {
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    cv::Mat img = cvimage->mat;
    cv::Mat noise(img.size(), img.type());

    NoiseDialog dlg;
    if ( dlg.exec() ) {
        saveToHistory(*cvimage);
        cv::randn(noise,Scalar::all(dlg.getMean()), Scalar::all(dlg.getDev()));

        if ( img.type() == CV_8UC1 ) {
            for( int y = 0; y < img.rows; y++ ) {
                for( int x = 0; x < img.cols; x++ ) {
                    img.at<uchar>(y,x) =
                            saturate_cast<uchar>( img.at<uchar>(y,x) + noise.at<uchar>(y,x) );
                }
            }
        }
        else if ( img.type() == CV_8UC3 ) {
            for( int y = 0; y < img.rows; y++ ) {
                for( int x = 0; x < img.cols; x++ ) {
                    img.at<Vec3b>(y,x)[0] =
                            saturate_cast<uchar>( img.at<Vec3b>(y,x)[0] + noise.at<uchar>(y,x) );
                    img.at<Vec3b>(y,x)[1] =
                            saturate_cast<uchar>( img.at<Vec3b>(y,x)[1] + noise.at<uchar>(y,x) );
                    img.at<Vec3b>(y,x)[2] =
                            saturate_cast<uchar>( img.at<Vec3b>(y,x)[2] + noise.at<uchar>(y,x) );
                }
            }
        }

        refreshGUI(*cvimage);
        cvimage->mat = img;
        cvimage->notify();
    }
}

void MainWindow::DCT() {
    CVImage *cvimage = getActiveImage();
    if ( cvimage == NULL )
        return;
    Mat img = cvimage->mat;
    Mat orig = img.clone();

    if ( img.type() == CV_8UC1 ) {
        cvimage->mat.convertTo(img,CV_32FC1);
        Mat tmp;
        img.convertTo(img,CV_32FC1);
        dct(img,tmp);
        imshow("DCT", tmp);
    }
    else if ( img.type() == CV_8UC3 ) {

        // Split the image into its three planes
        vector<Mat> planes;
        split(orig, planes);

        // Convert each plane to a type suitable for cv.dct(),
        // and do the transform on each one.
        vector<Mat> outplanes(planes.size());

        planes[0].convertTo(planes[0], CV_32FC1);
        dct(planes[0], outplanes[0]);

        planes[1].convertTo(planes[1], CV_32FC1);
        dct(planes[1], outplanes[1]);

        planes[2].convertTo(planes[2], CV_32FC1);
        dct(planes[2], outplanes[2]);


        // Now put the planes together into a single image
        Mat merged;
        merge(outplanes, merged);

        //
        // Show what we have so far
        //

        namedWindow("DCT Image[0]", CV_WINDOW_AUTOSIZE);
        imshow("DCT Image[0]", outplanes[0]);

        namedWindow("DCT Image[1]", CV_WINDOW_AUTOSIZE);
        imshow("DCT Image[1]", outplanes[1]);

        namedWindow("DCT Image[2]", CV_WINDOW_AUTOSIZE);
        imshow("DCT Image[2]", outplanes[2]);

        namedWindow("Merged DCT", CV_WINDOW_AUTOSIZE);
        imshow("Merged DCT", merged);
    }

    cvimage->notify();
}

void MainWindow::helpCanny() {
    QString url = helpModel->find(CONFIG_CANNY);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpBilateral() {
    QString url = helpModel->find(CONFIG_BILATERAL);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpIdeal() {
    QString url = helpModel->find(CONFIG_IDEAL);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpGauss() {
    QString url = helpModel->find(CONFIG_GAUSS);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpButterworth() {
    QString url = helpModel->find(CONFIG_BUTTERWORTH);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpResize() {
    QString url = helpModel->find(CONFIG_RESIZE);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpCustom() {
    QString url = helpModel->find(CONFIG_CUSTOM);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpRank() {
    QString url = helpModel->find(CONFIG_RANK);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpThresh() {
    QString url = helpModel->find(CONFIG_THRESH);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpLogic() {
    QString url = helpModel->find(CONFIG_LOGIC);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::helpMorph() {
    QString url = helpModel->find(CONFIG_MORPH);
    if ( url.size() == 0 )
        return;
    // dla pokazania zakładki z pomocą
    tabWidget->setCurrentIndex(1);
    webView->load(url);
}

void MainWindow::previewLogic(QString ifStr, QStringList thenStr, QStringList elseStr) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);

    QProgressDialog *progress = new QProgressDialog("Operation in progress...",QString(),0,100,this);
    progress->show();
    progress->setModal(true);
    ImageProcessor::getInstance().logicalFilter(preview,ifStr,thenStr,elseStr,getSelection(),false,progress);
    delete progress;

    if ( preview.mat.type() == CV_8UC1) {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    else {
        darqimg->repaint(preview.mat,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}

void MainWindow::listActivated(QListWidgetItem *item) {
    // Uzyskanie dostępu do konkretnej transformacji
    int index = item->listWidget()->currentRow();
    CVImage *cvimage = getActiveImage();
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    std::list<Transformation*>::iterator it = cvimage->transforms.begin();
    while (index) {
        ++it;
        --index;
    }
    index = item->listWidget()->currentRow();
    Transformation *current = *(it);
    // Jeśli to możliwe to edytuj parametry transformacji
    if ( current->isEditable() ) {
        // weź memento z caretakera
        Memento *mem = getActiveCaretaker()->getMementoFromIndex(index);
        // zapisz followers
        std::list<Transformation*> followers(++it,cvimage->transforms.end());
        // stwórz nowy CVImage
        CVImage *newimg = new CVImage(cvimage->path);
        newimg->setObserver(darqimg);
        // przywróć z
        ImageProcessor::getInstance().restore(*newimg,mem,false);
        // RTTI    
        TransBilateral* bil = dynamic_cast<TransBilateral*>(current);
        if (bil != NULL) {
            BilateralDialog dlg(bil->getDiameter(),bil->getSigmaColor(),bil->getSigmaSpace());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().smoothBilateral(*newimg,dlg.getDiameter(),dlg.getSigmaColor(),
                                                              dlg.getSigmaSpace(),bil->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransBrightness* bri = dynamic_cast<TransBrightness*>(current);
        if (bri != NULL) {
            brightnessDialog dlg(bri->getChannel(),bri->getValue());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().changeBrightness(*newimg,dlg.getValue().first,dlg.getValue().second,
                                                               bri->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransCanny* can = dynamic_cast<TransCanny*>(current);
        if (can != NULL) {
            CannyDialog dlg(can->getThreshold());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().canny(*newimg,dlg.getValue(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }


        TransCustomFilter* cus = dynamic_cast<TransCustomFilter*>(current);
        if (cus != NULL) {
            CustomFilterDialog dlg(cus->getMask(), cus->getDiv());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().customFilter(*newimg,cus->getRect(),cus->getMask(),
                                                           cus->getDiv(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }


        TransRankFilter* ran = dynamic_cast<TransRankFilter*>(current);
        if (ran != NULL) {
            rankFilterDialog dlg(ran->getRank(),ran->getSize());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                QProgressDialog *progress = new QProgressDialog("Operation in progress...",QString(),0,100,this);
                progress->show();
                progress->setModal(true);
                ImageProcessor::getInstance().rankFilter(*newimg,ran->getRect(),ran->getRank(),ran->getSize(),true,progress);
                delete progress;
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }


        TransFourierLow* tfl = dynamic_cast<TransFourierLow*>(current);
        if ( tfl != NULL ) {
            //filtr idealny i gauss
            if (tfl->getType() != 'b') {
                CutoffDialog dlg(LOW_GAUSSIAN,tfl->getCutoff());
                if ( dlg.exec() ) {
                    saveToHistory(*cvimage);
                    // wykonaj nową transformację
                    if ( tfl->getType() == 'g' )
                        ImageProcessor::getInstance().gaussianLowPass(*newimg,dlg.getCutoff(),tfl->getRect(),true);
                    else if ( tfl->getType() == 'i' )
                        ImageProcessor::getInstance().idealLowPass(*cvimage,dlg.getCutoff(),tfl->getRect(),true);
                }
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            //filtr butterwortha
            else {
                ButterworthDialog dlg(BUTTERWORTH_LOW_PASS,tfl->getCutoff(),tfl->getOrder());
                if ( dlg.exec() ) {
                    saveToHistory(*cvimage);
                    // wykonaj nową transformację
                    ImageProcessor::getInstance().butterworthLowPass(*newimg,dlg.getCutoff(),dlg.getOrder(),tfl->getRect(),true);
                }
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransFourierHigh* tfh = dynamic_cast<TransFourierHigh*>(current);
        if ( tfh != NULL ) {
            //filtr idealny i gauss
            if (tfh->getType() != 'b') {
                CutoffDialog dlg(HIGH_GAUSSIAN,tfh->getCutoff());
                if ( dlg.exec() ) {
                    saveToHistory(*cvimage);
                    // wykonaj nową transformację
                    if ( tfh->getType() == 'g' )
                        ImageProcessor::getInstance().gaussianHighPass(*newimg,dlg.getCutoff(),tfh->getRect(),true);
                    else if ( tfh->getType() == 'i' )
                        ImageProcessor::getInstance().idealHighPass(*newimg,dlg.getCutoff(),tfh->getRect(),true);
                }
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            //filtr butterwortha
            else {
                ButterworthDialog dlg(BUTTERWORTH_HIGH_PASS,tfh->getCutoff(),tfh->getOrder());
                if ( dlg.exec() ) {
                    saveToHistory(*cvimage);
                    // wykonaj nową transformację
                    ImageProcessor::getInstance().butterworthHighPass(*newimg,dlg.getCutoff(),dlg.getOrder(),tfh->getRect(),true);
                }
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransBandPass* tbp = dynamic_cast<TransBandPass*>(current);
        if (tbp != NULL) {
            BandPassDialog dlg(tbp->getInner(),tbp->getOuter());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().bandPass(*newimg,dlg.getInner(),dlg.getOuter(),tbp->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransHSV* thsv = dynamic_cast<TransHSV*>(current);
        if (thsv != NULL) {
            HSVDialog dlg(thsv->getSaturation(),thsv->getHue());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().hsv(*newimg,thsv->getRect(),dlg.getHue(),dlg.getSaturation(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransLogical* tl = dynamic_cast<TransLogical*>(current);
        if (tl != NULL) {
            logicalFilterDialog dlg(tl->getIf(),tl->getThen(),tl->getElse());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                QProgressDialog *progress = new QProgressDialog("Operation in progress...",QString(),0,100,this);
                progress->show();
                progress->setModal(true);
                int result = ImageProcessor::getInstance().logicalFilter(*newimg, dlg.getIf(),dlg.getThen(),dlg.getElse(),
                                                            tl->getRect(),true,progress);
                if ( result != 0 ) {
                    QMessageBox::information(this, tr("Darqwin"),
                                             tr("Error").append("\nLogical filter parsing failed"));
                }
                delete progress;
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransErode* te = dynamic_cast<TransErode*>(current);
        if ( te != NULL ) {
            MorphDialog dlg(ERODE,te->getSize(),te->getIterations());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().erode(*newimg,dlg.getIterations(),dlg.getSize(),te->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransDilate* td = dynamic_cast<TransDilate*>(current);
        if ( td != NULL ) {
            MorphDialog dlg(DILATE,td->getSize(),td->getIterations());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().dilate(*newimg,dlg.getIterations(),dlg.getSize(),td->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransOpen* to = dynamic_cast<TransOpen*>(current);
        if ( to != NULL ) {
            MorphDialog dlg(OPEN,to->getSize(),to->getIterations());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().open(*newimg,dlg.getIterations(),dlg.getSize(),to->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransGradient* tg = dynamic_cast<TransGradient*>(current);
        if ( tg != NULL ) {
            MorphDialog dlg(GRADIENT,tg->getSize(),tg->getIterations());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().gradient(*newimg,dlg.getIterations(),dlg.getSize(),tg->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }

        TransClose* tc = dynamic_cast<TransClose*>(current);
        if ( tc != NULL ) {
            MorphDialog dlg(CLOSE,tc->getSize(),tc->getIterations());
            if ( dlg.exec() ) {
                saveToHistory(*cvimage);
                // wykonaj nową transformację
                ImageProcessor::getInstance().close(*newimg,dlg.getIterations(),dlg.getSize(),tc->getRect(),true);
                // wykonaj pozostałe
                for ( std::list<Transformation*>::iterator i = followers.begin(); i != followers.end(); ++i ) {
                    ImageProcessor::getInstance().processTransformation(*newimg,*i);
                }
                // skopiuj cvimage (głęboko)
                cvimage->mat = newimg->mat.clone();
                cvimage->transforms.clear();
                cvimage->transforms = newimg->transformationListClone();
                delete newimg;
                // zapisz do historii i odśwież
                if ( cvimage->mat.type() == CV_8UC3 )
                    darqimg->repaint(cvimage->mat,false);
                else {
                    Mat rgb;
                    cvtColor(cvimage->mat,rgb,CV_GRAY2RGB);
                    darqimg->repaint(rgb,false);
                }
                refreshGUI(*cvimage);
            }
            ui->mdiArea->setActiveSubWindow(sub);
            return;
        }        
    }

}

void MainWindow::locateHelp() {
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty()) {
        if ( fileName.endsWith(".htm") || fileName.endsWith(".html") ) {
            // na potrzeby windows
            if ( fileName[0] == '/' )
                fileName.prepend("file://");
            else
                fileName.prepend("file:///");
            QFile file("config.xml");
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            helpModel->createConfig(out,fileName);
            file.close();
            // reload
            helpConfig();
            webView->load(QUrl(helpModel->find(CONFIG_INDEX)));
        }
        else {
            QMessageBox::information(this, tr("Darqwin"),
                                     tr("Cannot load %1.").arg(fileName).append("\nHTML file required"));
            return;
        }
    }
    else
        return;
}

void MainWindow::previewMorph(int size, int iterations, int type) {
    QMdiSubWindow *sub = ui->mdiArea->currentSubWindow();
    DarqImage *darqimg = (DarqImage *)sub->widget();
    CVImage *cvimage = getActiveImage();
    CVImage preview(*cvimage);

    if ( type == ERODE )
        ImageProcessor::getInstance().erode(preview, iterations, size, getSelection(), false);
    else if ( type == DILATE )
        ImageProcessor::getInstance().dilate(preview, iterations, size, getSelection(), false);
    else if ( type == OPEN )
        ImageProcessor::getInstance().open(preview, iterations, size, getSelection(), false);
    else if ( type == CLOSE )
        ImageProcessor::getInstance().close(preview, iterations, size, getSelection(), false);
    else if ( type == GRADIENT )
        ImageProcessor::getInstance().gradient(preview, iterations, size, getSelection(), false);

    if ( preview.mat.type() == CV_8UC1) {
        Mat rgb;
        cvtColor(preview.mat,rgb,CV_GRAY2RGB);
        darqimg->repaint(rgb,false);
    }
    else {
        darqimg->repaint(preview.mat,false);
    }
    ui->mdiArea->setActiveSubWindow(sub);
}
