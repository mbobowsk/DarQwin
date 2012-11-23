#include "thresholddialog.h"
#include "ui_thresholddialog.h"

ThresholdDialog::ThresholdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThresholdDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
}

ThresholdDialog::~ThresholdDialog()
{
    delete ui;
}

void ThresholdDialog::changeEvent(QEvent *e)
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

int ThresholdDialog::getMode() {
    if ( ui->binaryButton->isChecked() )
        return BINARY;
    else
        return BINARY_INVERTED;
}

int ThresholdDialog::getValue() {
    return ui->threshSlider->value();
}

void ThresholdDialog::previewButtonPressed() {
    emit preview(getMode(),getValue());
}

void ThresholdDialog::helpButtonPressed() {
    emit help();
}
