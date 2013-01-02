#include "morphdialog.h"
#include "ui_morphdialog.h"

MorphDialog::MorphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MorphDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    connect(ui->sizeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(sizeOdd(int)));
    connect(ui->iterationsSpinBox,SIGNAL(valueChanged(int)),this,SLOT(iterationsOdd(int)));
}

MorphDialog::~MorphDialog()
{
    delete ui;
}

void MorphDialog::changeEvent(QEvent *e)
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

int MorphDialog::getIterations() {
    return ui->iterationsSpinBox->value();
}

int MorphDialog::getSize() {
    return ui->sizeSpinBox->value();
}

void MorphDialog::iterationsOdd(int value) {
    if ( value%2 != 1 ) {
        ui->iterationsSpinBox->setValue(value-1);
    }
}

void MorphDialog::sizeOdd(int value) {
    if ( value%2 != 1 ) {
        ui->sizeSpinBox->setValue(value-1);
    }
}

void MorphDialog::previewButtonPressed() {
    //emit preview();
}

void MorphDialog::helpButtonPressed() {
    //emit help();
}
