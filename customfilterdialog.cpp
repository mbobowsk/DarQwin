#include "customfilterdialog.h"
#include "ui_customfilterdialog.h"

CustomFilterDialog::CustomFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomFilterDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
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

void CustomFilterDialog::getParams(std::vector<float> &vec) {
    if ( ui->spinBox00->value() == 0 && ui->spinBox01->value() == 0 && ui->spinBox02->value() == 0 &&
         ui->spinBox03->value() == 0 && ui->spinBox04->value() == 0 && ui->spinBox10->value() == 0 &&
         ui->spinBox14->value() == 0 && ui->spinBox20->value() == 0 && ui->spinBox24->value() == 0 &&
         ui->spinBox30->value() == 0 && ui->spinBox34->value() == 0 && ui->spinBox40->value() == 0 &&
         ui->spinBox41->value() == 0 && ui->spinBox42->value() == 0 && ui->spinBox43->value() == 0 &&
         ui->spinBox44->value() == 0 ) {
        vec.push_back(ui->spinBox11->value());
        vec.push_back(ui->spinBox12->value());
        vec.push_back(ui->spinBox13->value());
        vec.push_back(ui->spinBox21->value());
        vec.push_back(ui->spinBox22->value());
        vec.push_back(ui->spinBox23->value());
        vec.push_back(ui->spinBox31->value());
        vec.push_back(ui->spinBox32->value());
        vec.push_back(ui->spinBox33->value());
    }
    else {
        vec.push_back(ui->spinBox00->value());
        vec.push_back(ui->spinBox01->value());
        vec.push_back(ui->spinBox02->value());
        vec.push_back(ui->spinBox03->value());
        vec.push_back(ui->spinBox04->value());
        vec.push_back(ui->spinBox10->value());
        vec.push_back(ui->spinBox11->value());
        vec.push_back(ui->spinBox12->value());
        vec.push_back(ui->spinBox13->value());
        vec.push_back(ui->spinBox14->value());
        vec.push_back(ui->spinBox20->value());
        vec.push_back(ui->spinBox21->value());
        vec.push_back(ui->spinBox22->value());
        vec.push_back(ui->spinBox23->value());
        vec.push_back(ui->spinBox24->value());
        vec.push_back(ui->spinBox30->value());
        vec.push_back(ui->spinBox31->value());
        vec.push_back(ui->spinBox32->value());
        vec.push_back(ui->spinBox33->value());
        vec.push_back(ui->spinBox34->value());
        vec.push_back(ui->spinBox40->value());
        vec.push_back(ui->spinBox41->value());
        vec.push_back(ui->spinBox42->value());
        vec.push_back(ui->spinBox43->value());
        vec.push_back(ui->spinBox44->value());
    }
}

int CustomFilterDialog::getDivisor() {
    return ui->spinBox->value();
}

void CustomFilterDialog::previewButtonPressed() {
    std::vector<float> vec;
    if ( ui->spinBox00->value() == 0 && ui->spinBox01->value() == 0 && ui->spinBox02->value() == 0 &&
         ui->spinBox03->value() == 0 && ui->spinBox04->value() == 0 && ui->spinBox10->value() == 0 &&
         ui->spinBox14->value() == 0 && ui->spinBox20->value() == 0 && ui->spinBox24->value() == 0 &&
         ui->spinBox30->value() == 0 && ui->spinBox34->value() == 0 && ui->spinBox40->value() == 0 &&
         ui->spinBox41->value() == 0 && ui->spinBox42->value() == 0 && ui->spinBox43->value() == 0 &&
         ui->spinBox44->value() == 0 ) {
        vec.push_back(ui->spinBox11->value());
        vec.push_back(ui->spinBox12->value());
        vec.push_back(ui->spinBox13->value());
        vec.push_back(ui->spinBox21->value());
        vec.push_back(ui->spinBox22->value());
        vec.push_back(ui->spinBox23->value());
        vec.push_back(ui->spinBox31->value());
        vec.push_back(ui->spinBox32->value());
        vec.push_back(ui->spinBox33->value());
    }
    else {
        vec.push_back(ui->spinBox00->value());
        vec.push_back(ui->spinBox01->value());
        vec.push_back(ui->spinBox02->value());
        vec.push_back(ui->spinBox03->value());
        vec.push_back(ui->spinBox04->value());
        vec.push_back(ui->spinBox10->value());
        vec.push_back(ui->spinBox11->value());
        vec.push_back(ui->spinBox12->value());
        vec.push_back(ui->spinBox13->value());
        vec.push_back(ui->spinBox14->value());
        vec.push_back(ui->spinBox20->value());
        vec.push_back(ui->spinBox21->value());
        vec.push_back(ui->spinBox22->value());
        vec.push_back(ui->spinBox23->value());
        vec.push_back(ui->spinBox24->value());
        vec.push_back(ui->spinBox30->value());
        vec.push_back(ui->spinBox31->value());
        vec.push_back(ui->spinBox32->value());
        vec.push_back(ui->spinBox33->value());
        vec.push_back(ui->spinBox34->value());
        vec.push_back(ui->spinBox40->value());
        vec.push_back(ui->spinBox41->value());
        vec.push_back(ui->spinBox42->value());
        vec.push_back(ui->spinBox43->value());
        vec.push_back(ui->spinBox44->value());
    }
    emit preview(ui->spinBox->value(),vec);
}

