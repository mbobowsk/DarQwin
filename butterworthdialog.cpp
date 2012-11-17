#include "butterworthdialog.h"
#include "ui_butterworthdialog.h"

ButterworthDialog::ButterworthDialog(int typ, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButterworthDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    type = typ;

    if ( type == BUTTERWORTH_HIGH_PASS )
        setWindowTitle("Butterworth High-pass Filter");
    else if ( type == BUTTERWORTH_LOW_PASS )
        setWindowTitle("Butterworth Low-pass Filter");
}

ButterworthDialog::~ButterworthDialog()
{
    delete ui;
}

void ButterworthDialog::changeEvent(QEvent *e)
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

int ButterworthDialog::getOrder() {
    return ui->orderSpinBox->value();
}

int ButterworthDialog::getCutoff() {
    return ui->cutoffSpinBox->value();
}

void ButterworthDialog::previewButtonPressed() {
    emit preview(getCutoff(),getOrder(),type);
}
