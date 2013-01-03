#include "morphdialog.h"
#include "ui_morphdialog.h"

MorphDialog::MorphDialog(int _type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MorphDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    connect(ui->sizeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(sizeOdd(int)));
    type = _type;
}


MorphDialog::MorphDialog(int _type, int _size, int _iter, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MorphDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    connect(ui->sizeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(sizeOdd(int)));
    type = _type;
    ui->sizeSpinBox->setValue(_size);
    ui->iterationsSpinBox->setValue(_iter);
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

void MorphDialog::sizeOdd(int value) {
    if ( value%2 != 1 ) {
        ui->sizeSpinBox->setValue(value-1);
    }
}

void MorphDialog::previewButtonPressed() {
    emit preview(getSize(),getIterations(),type);
}

void MorphDialog::helpButtonPressed() {
    emit help();
}
