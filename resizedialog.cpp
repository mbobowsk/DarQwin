#include "resizedialog.h"
#include "ui_resizedialog.h"

ResizeDialog::ResizeDialog(int currentX, int currentY, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResizeDialog)
{
    ui->setupUi(this);
    ui->customXSpinBox->setValue(currentX);
    ui->customYSpinBox->setValue(currentY);
}

ResizeDialog::~ResizeDialog()
{
    delete ui;
}

void ResizeDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int ResizeDialog::getMode() {
    if ( ui->scaleButton->isChecked() )
        return RESIZE_SCALE;
    else
        return RESIZE_CUSTOM;
}

double ResizeDialog::getScaleX() {
    return ui->scaleXSpinBox->value();
}

double ResizeDialog::getScaleY() {
    return ui->scaleYSpinBox->value();
}

int ResizeDialog::getCustomX() {
    return ui->customXSpinBox->value();
}

int ResizeDialog::getCustomY() {
    return ui->customYSpinBox->value();
}
