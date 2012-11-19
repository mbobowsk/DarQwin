#include "hsvdialog.h"
#include "ui_hsvdialog.h"

HSVDialog::HSVDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HSVDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
}

HSVDialog::~HSVDialog()
{
    delete ui;
}

void HSVDialog::changeEvent(QEvent *e)
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

int HSVDialog::getHue() {
    return ui->hueSlider->value();
}

int HSVDialog::getSaturation() {
    return ui->saturationSlider->value();
}

void HSVDialog::previewButtonPressed() {
    emit preview(ui->hueSlider->value(),ui->saturationSpinBox->value());
}
