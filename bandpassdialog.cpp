#include "bandpassdialog.h"
#include "ui_bandpassdialog.h"

BandPassDialog::BandPassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BandPassDialog)
{
    ui->setupUi(this);
}

BandPassDialog::~BandPassDialog()
{
    delete ui;
}

void BandPassDialog::changeEvent(QEvent *e)
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

int BandPassDialog::getInner() {
    return ui->innerSpinBox->value();
}

int BandPassDialog::getOuter() {
    return ui->outerSpinBox->value();
}
