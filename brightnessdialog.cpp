#include "brightnessdialog.h"
#include "ui_brightnessdialog.h"

brightnessDialog::brightnessDialog(QWidget *parent) :
        QDialog(parent),
    ui(new Ui::brightnessDialog)
{
    ui->setupUi(this);
    setWindowTitle("Set brightness");
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
}

brightnessDialog::~brightnessDialog()
{
    delete ui;
}

void brightnessDialog::changeEvent(QEvent *e)
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

std::pair<char,int> brightnessDialog::getValue() {
    int value = ui->horizontalSlider->sliderPosition();
    char type = 'a'; //domyslnie dla RGB
    if (ui->rButton->isChecked())
        type = 'r';
    else if (ui->gButton->isChecked())
        type = 'g';
    else if (ui->bButton->isChecked())
        type = 'b';
    return std::make_pair(type,value);
}

void brightnessDialog::setGrayscaleButtons() {
    ui->rButton->setEnabled(false);
    ui->gButton->setEnabled(false);
    ui->bButton->setEnabled(false);
}

void brightnessDialog::previewButtonPressed() {
    char type = 'a'; //domyslnie dla RGB
    if (ui->rButton->isChecked())
        type = 'r';
    else if (ui->gButton->isChecked())
        type = 'g';
    else if (ui->bButton->isChecked())
        type = 'b';
    emit preview(type,ui->horizontalSlider->sliderPosition());
}
