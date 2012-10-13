#include "cannydialog.h"
#include "ui_cannydialog.h"

CannyDialog::CannyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CannyDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
}

CannyDialog::~CannyDialog()
{
    delete ui;
}

void CannyDialog::changeEvent(QEvent *e)
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

int CannyDialog::getValue() {
    return ui->horizontalSlider->value();
}

void CannyDialog::previewButtonPressed() {
    emit preview(ui->horizontalSlider->value());
}
