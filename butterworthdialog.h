#ifndef BUTTERWORTHDIALOG_H
#define BUTTERWORTHDIALOG_H

#include <QDialog>

#define BUTTERWORTH_LOW_PASS 0
#define BUTTERWORTH_HIGH_PASS 1

namespace Ui {
    class ButterworthDialog;
}

class ButterworthDialog : public QDialog {
    Q_OBJECT
public:
    ButterworthDialog(int type, QWidget *parent = 0);
    ~ButterworthDialog();
    int getCutoff();
    int getOrder();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ButterworthDialog *ui;
};

#endif // BUTTERWORTHDIALOG_H
