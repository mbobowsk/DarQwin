#include "rankfilterdialog.h"
#include "ui_rankfilterdialog.h"

rankFilterDialog::rankFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rankFilterDialog)
{
    ui->setupUi(this);
    connect(ui->button3x3, SIGNAL(clicked()), this, SLOT(button3x3Pressed()));
    connect(ui->button5x5, SIGNAL(clicked()), this, SLOT(button5x5Pressed()));
}

rankFilterDialog::~rankFilterDialog()
{
    delete ui;
}

void rankFilterDialog::changeEvent(QEvent *e)
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

int rankFilterDialog::getValue() {
    return ui->spinBox->value();
}

void rankFilterDialog::button3x3Pressed() {
    ui->spinBox->setMaximum(9);
}

void rankFilterDialog::button5x5Pressed() {
    ui->spinBox->setMaximum(16);
}

