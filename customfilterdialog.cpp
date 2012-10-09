#include "customfilterdialog.h"
#include "ui_customfilterdialog.h"

CustomFilterDialog::CustomFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomFilterDialog)
{
    ui->setupUi(this);
}

CustomFilterDialog::~CustomFilterDialog()
{
    delete ui;
}

void CustomFilterDialog::changeEvent(QEvent *e)
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
