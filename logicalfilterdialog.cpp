#include "logicalfilterdialog.h"
#include "ui_logicalfilterdialog.h"

logicalFilterDialog::logicalFilterDialog(bool rgb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logicalFilterDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    // inicjalizacja w zależności od ilości kanałów obrazka
    if ( rgb ) {
        ui->ifTextLine->setText("Er>100");
        ui->e1->setDisabled(true);
        ui->e2->setDisabled(true);
        ui->label_14->setDisabled(true);
        ui->label_21->setDisabled(true);
        ui->er1->setText("Er");
        ui->eg1->setText("Eg");
        ui->eb1->setText("Eb");
        ui->er2->setText("Er");
        ui->eg2->setText("Eg");
        ui->eb2->setText("Eb");
    }
    else {
        ui->ifTextLine->setText("E>100");
        ui->er1->setDisabled(true);
        ui->eg1->setDisabled(true);
        ui->eb1->setDisabled(true);
        ui->er2->setDisabled(true);
        ui->eg2->setDisabled(true);
        ui->eb2->setDisabled(true);
        ui->label_15->setDisabled(true);
        ui->label_19->setDisabled(true);
        ui->label_20->setDisabled(true);
        ui->label_22->setDisabled(true);
        ui->label_23->setDisabled(true);
        ui->label_24->setDisabled(true);
        ui->e1->setText("E");
        ui->e2->setText("E");
    }
}

logicalFilterDialog::logicalFilterDialog(QString ifStr, const QStringList &thenStr, const QStringList &elseStr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logicalFilterDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    ui->ifTextLine->setText(ifStr);

    // inicjalizacja w zależności od ilości kanałów obrazka
    // rgb
    if ( thenStr[0].isEmpty() && elseStr[0].isEmpty() ) {
        ui->e1->setDisabled(true);
        ui->e2->setDisabled(true);
        ui->label_14->setDisabled(true);
        ui->label_21->setDisabled(true);
        ui->er1->setText(thenStr.at(1));
        ui->eg1->setText(thenStr.at(2));
        ui->eb1->setText(thenStr.at(3));
        ui->er2->setText(elseStr.at(1));
        ui->eg2->setText(elseStr.at(2));
        ui->eb2->setText(elseStr.at(3));
    }
    // grayscale
    else {
        ui->er1->setDisabled(true);
        ui->eg1->setDisabled(true);
        ui->eb1->setDisabled(true);
        ui->er2->setDisabled(true);
        ui->eg2->setDisabled(true);
        ui->eb2->setDisabled(true);
        ui->label_15->setDisabled(true);
        ui->label_19->setDisabled(true);
        ui->label_20->setDisabled(true);
        ui->label_22->setDisabled(true);
        ui->label_23->setDisabled(true);
        ui->label_24->setDisabled(true);
        ui->e1->setText(thenStr.at(0));
        ui->e2->setText(elseStr.at(0));

    }
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

QStringList logicalFilterDialog::getThen() {
    QStringList ret;
    ret << ui->e1->text() << ui->er1->text() << ui->eg1->text() << ui->eb1->text();
    return ret;
}

QStringList logicalFilterDialog::getElse() {
    QStringList ret;
    ret << ui->e2->text() << ui->er2->text() << ui->eg2->text() << ui->eb2->text();
    return ret;
}

void logicalFilterDialog::helpButtonPressed() {
    emit help();
}

void logicalFilterDialog::previewButtonPressed() {
    emit preview(getIf(),getThen(),getElse());
}
