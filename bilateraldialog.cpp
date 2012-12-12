#include "bilateraldialog.h"
#include "ui_bilateraldialog.h"

BilateralDialog::BilateralDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BilateralDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
}

BilateralDialog::BilateralDialog(int d, int sc, int ss, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::BilateralDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    ui->diameterSlider->setValue(d);
    ui->diameterSpinBox->setValue(d);
    ui->sigmaCSlider->setValue(sc);
    ui->sigmaCSpinBox->setValue(sc);
    ui->sigmaSSlider->setValue(ss);
    ui->sigmaSSpinBox->setValue(ss);
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

void BilateralDialog::previewButtonPressed() {
    emit preview(ui->diameterSlider->value(),ui->sigmaCSlider->value(),ui->sigmaSSlider->value());
}

void BilateralDialog::helpButtonPressed() {
    emit help();
}
