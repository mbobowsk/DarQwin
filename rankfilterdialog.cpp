#include "rankfilterdialog.h"
#include "ui_rankfilterdialog.h"

rankFilterDialog::rankFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rankFilterDialog)
{
    ui->setupUi(this);
    connect(ui->button3x3, SIGNAL(clicked()), this, SLOT(button3x3Pressed()));
    connect(ui->button5x5, SIGNAL(clicked()), this, SLOT(button5x5Pressed()));
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
}

rankFilterDialog::rankFilterDialog(int rank, int size, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rankFilterDialog)
{
    ui->setupUi(this);
    connect(ui->button3x3, SIGNAL(clicked()), this, SLOT(button3x3Pressed()));
    connect(ui->button5x5, SIGNAL(clicked()), this, SLOT(button5x5Pressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    ui->spinBox->setValue(rank);
    if ( size == 3 )
        ui->button3x3->setChecked(true);
    else
        ui->button5x5->setChecked(true);
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

int rankFilterDialog::getSize() {
    if ( ui->button3x3->isChecked() )
        return 3;
    else
        return 5;
}

void rankFilterDialog::button3x3Pressed() {
    ui->spinBox->setMaximum(9);
}

void rankFilterDialog::button5x5Pressed() {
    ui->spinBox->setMaximum(25);
}

void rankFilterDialog::previewButtonPressed() {
    emit preview(getSize(),getValue());
}

void rankFilterDialog::helpButtonPressed() {
    emit help();
}
