#include "customfilterdialog.h"
#include "ui_customfilterdialog.h"

CustomFilterDialog::CustomFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomFilterDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
}

CustomFilterDialog::CustomFilterDialog(const std::vector<float> &params, int divisor, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomFilterDialog)
{
    ui->setupUi(this);
    connect(ui->helpButton,SIGNAL(clicked()),this,SLOT(helpButtonPressed()));
    ui->spinBox->setValue(divisor);
    if ( params.size() == 9 ) {
        ui->spinBox11->setValue(params[0]*divisor);
        ui->spinBox12->setValue(params[1]*divisor);
        ui->spinBox13->setValue(params[2]*divisor);
        ui->spinBox21->setValue(params[3]*divisor);
        ui->spinBox22->setValue(params[4]*divisor);
        ui->spinBox23->setValue(params[5]*divisor);
        ui->spinBox31->setValue(params[6]*divisor);
        ui->spinBox32->setValue(params[7]*divisor);
        ui->spinBox33->setValue(params[8]*divisor);
    }
    else {
        ui->spinBox00->setValue(params[0]*divisor);
        ui->spinBox01->setValue(params[1]*divisor);
        ui->spinBox02->setValue(params[2]*divisor);
        ui->spinBox03->setValue(params[3]*divisor);
        ui->spinBox04->setValue(params[4]*divisor);
        ui->spinBox10->setValue(params[5]*divisor);
        ui->spinBox11->setValue(params[6]*divisor);
        ui->spinBox12->setValue(params[7]*divisor);
        ui->spinBox13->setValue(params[8]*divisor);
        ui->spinBox14->setValue(params[9]*divisor);
        ui->spinBox20->setValue(params[10]*divisor);
        ui->spinBox21->setValue(params[11]*divisor);
        ui->spinBox22->setValue(params[12]*divisor);
        ui->spinBox23->setValue(params[13]*divisor);
        ui->spinBox24->setValue(params[14]*divisor);
        ui->spinBox30->setValue(params[15]*divisor);
        ui->spinBox31->setValue(params[16]*divisor);
        ui->spinBox32->setValue(params[17]*divisor);
        ui->spinBox33->setValue(params[18]*divisor);
        ui->spinBox34->setValue(params[19]*divisor);
        ui->spinBox40->setValue(params[20]*divisor);
        ui->spinBox41->setValue(params[21]*divisor);
        ui->spinBox42->setValue(params[22]*divisor);
        ui->spinBox43->setValue(params[23]*divisor);
        ui->spinBox44->setValue(params[24]*divisor);
    }
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

void CustomFilterDialog::helpButtonPressed() {
    emit help();
}

