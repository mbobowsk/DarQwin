#include "bilateraldialog.h"
#include "ui_bilateraldialog.h"

BilateralDialog::BilateralDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BilateralDialog)
{
    ui->setupUi(this);
}

BilateralDialog::~BilateralDialog()
{
    delete ui;
}

void BilateralDialog::changeEvent(QEvent *e)
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

int BilateralDialog::getDiameter() {
    return ui->diameterSlider->value();
}

int BilateralDialog::getSigmaColor() {
    return ui->sigmaCSlider->value();
}

int BilateralDialog::getSigmaSpace() {
    return ui->sigmaSSlider->value();
}
