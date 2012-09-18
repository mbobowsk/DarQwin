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
    if ( !c->undoList.empty() ) {
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
    Model::getInstance().images.erase(img->id);
    CaretakerModel::getInstance().caretakers.erase(img->id);
}
