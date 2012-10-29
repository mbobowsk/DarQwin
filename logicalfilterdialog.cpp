#include "logicalfilterdialog.h"
#include "ui_logicalfilterdialog.h"

logicalFilterDialog::logicalFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logicalFilterDialog)
{
    ui->setupUi(this);
}

logicalFilterDialog::~logicalFilterDialog()
{
    delete ui;
}

void logicalFilterDialog::changeEvent(QEvent *e)
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
