#include "jpegdialog.h"
#include "ui_jpegdialog.h"

JPEGDialog::JPEGDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JPEGDialog)
{
    ui->setupUi(this);
}

JPEGDialog::~JPEGDialog()
{
    delete ui;
}

void JPEGDialog::changeEvent(QEvent *e)
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

int JPEGDialog::getValue() {
    return ui->horizontalSlider->value();
}
