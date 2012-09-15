#include "mdisubwindow.h"
#include "model.h"
#include "darqimage.h"
#include "cvimage.h"
#include "caretakermodel.h"

MdiSubWindow::MdiSubWindow(QWidget *widget) : QMdiSubWindow(widget)
{
    setAttribute(Qt::WA_DeleteOnClose);
}

MdiSubWindow::~MdiSubWindow() {}

void MdiSubWindow::closeEvent(QCloseEvent *) {
    DarqImage *img = (DarqImage *) this->widget();
    Model::getInstance().images.erase(img->id);
    CaretakerModel::getInstance().caretakers.erase(img->id);
}
