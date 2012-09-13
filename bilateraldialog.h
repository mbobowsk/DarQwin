#ifndef BILATERALDIALOG_H
#define BILATERALDIALOG_H

#include <QDialog>

namespace Ui {
    class BilateralDialog;
}

class BilateralDialog : public QDialog {
    Q_OBJECT
public:
    BilateralDialog(QWidget *parent = 0);
    ~BilateralDialog();
    int getDiameter();
    int getSigmaColor();
    int getSigmaSpace();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BilateralDialog *ui;
};

#endif // BILATERALDIALOG_H
