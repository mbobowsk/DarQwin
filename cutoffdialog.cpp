#include "cutoffdialog.h"
#include "ui_cutoffdialog.h"

CutoffDialog::CutoffDialog(int typ, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CutoffDialog)
{
    ui->setupUi(this);
    connect(ui->previewButton,SIGNAL(clicked()),this,SLOT(previewButtonPressed()));
    type = typ;

    if ( type == LOW_GAUSSIAN )
        setWindowTitle("Low-pass Gaussian Filter");
    else if ( type == HIGH_GAUSSIAN )
        setWindowTitle("High-pass Gaussian Filter");
    else if ( type == LOW_IDEAL )
        setWindowTitle("Low-pass Ideal Filter");
    else if ( type == HIGH_IDEAL )
        setWindowTitle("High-pass Ideal Filter");
}

CutoffDialog::~CutoffDialog()
{
    delete ui;
}

void CutoffDialog::changeEvent(QEvent *e)
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

int CutoffDialog::getCutoff() {
    return ui->spinBox->value();
}

void CutoffDialog::previewButtonPressed() {
    emit preview(getCutoff(),type);
}
