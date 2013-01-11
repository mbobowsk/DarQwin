#include "mdisubwindow.h"
#include "model.h"
#include "darqimage.h"
#include "cvimage.h"
#include "caretakermodel.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>

MdiSubWindow::MdiSubWindow(QWidget *widget) : QMdiSubWindow(widget)
{
    setAttribute(Qt::WA_DeleteOnClose);
}

MdiSubWindow::~MdiSubWindow() {}

void MdiSubWindow::closeEvent(QCloseEvent *e) {
    DarqImage *img = (DarqImage *) this->widget();
    Caretaker *caretaker = CaretakerModel::getInstance().caretakers.find(img->id)->second;
    CVImage *cvimage = Model::getInstance().images.find(img->id)->second;
    if ( caretaker->dirtyCounter != 0 ) {
        QMessageBox msgBox;
        msgBox.setText("The image has been modified.");
        msgBox.setInformativeText("Close without saving?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Cancel | QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Yes: {
                show_file_dialog3:
                QString filePath = QFileDialog::getSaveFileName(this,"Save File",img->path);
                if ( !filePath.isNull() ) {
                    if ( cvimage->save(filePath) != 0 )
                        goto show_file_dialog3;
                }
            }
            break;
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            return;
        }
    }

    Model::getInstance().images.erase(img->id);
    delete cvimage;

    CaretakerModel::getInstance().caretakers.erase(img->id);
    delete caretaker;

    if ( Model::getInstance().images.empty() )
        emit allClosed();
}
