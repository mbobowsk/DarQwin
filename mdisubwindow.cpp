#include "mdisubwindow.h"
#include "model.h"
#include "darqimage.h"
#include "cvimage.h"
#include "caretakermodel.h"
#include <QMessageBox>
#include <QCloseEvent>

MdiSubWindow::MdiSubWindow(QWidget *widget) : QMdiSubWindow(widget)
{
    setAttribute(Qt::WA_DeleteOnClose);
}

MdiSubWindow::~MdiSubWindow() {}

void MdiSubWindow::closeEvent(QCloseEvent *e) {
    DarqImage *img = (DarqImage *) this->widget();
    Caretaker *c = CaretakerModel::getInstance().caretakers.find(img->id)->second;
    if ( c->dirtyCounter != 0 ) {
        QMessageBox msgBox;
        msgBox.setText("The image has been modified.");
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

    CVImage *cvimage = Model::getInstance().images.find(img->id)->second;
    Model::getInstance().images.erase(img->id);
    delete cvimage;

    Caretaker *caretaker = CaretakerModel::getInstance().caretakers.find(img->id)->second;
    CaretakerModel::getInstance().caretakers.erase(img->id);
    delete caretaker;
    if ( Model::getInstance().images.empty() )
        emit allClosed();
}
