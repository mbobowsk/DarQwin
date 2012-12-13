#include "logicalfilterdialog.h"
#include "ui_logicalfilterdialog.h"

logicalFilterDialog::logicalFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logicalFilterDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
}

logicalFilterDialog::logicalFilterDialog(QString ifStr, QString thenStr, QString elseStr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logicalFilterDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    ui->ifTextLine->setText(ifStr);
    ui->thenTextLine->setText(thenStr);
    ui->elseTextLine->setText(elseStr);
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

QString logicalFilterDialog::getIf() {
    return ui->ifTextLine->text();
}

QString logicalFilterDialog::getThen() {
    return ui->thenTextLine->text();
}

QString logicalFilterDialog::getElse() {
    return ui->elseTextLine->text();
}

void logicalFilterDialog::helpButtonPressed() {
    emit help();
}

void logicalFilterDialog::previewButtonPressed() {
    emit preview(getIf(),getThen(),getElse());
}
