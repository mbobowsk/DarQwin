#include "noisedialog.h"
#include "ui_noisedialog.h"

NoiseDialog::NoiseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoiseDialog)
{
    ui->setupUi(this);
}

NoiseDialog::~NoiseDialog()
{
    delete ui;
}

void NoiseDialog::changeEvent(QEvent *e)
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

int NoiseDialog::getMean() {
    return ui->meanSpinBox->value();
}

int NoiseDialog::getDev() {
    return ui->devSpinBox->value();
}
