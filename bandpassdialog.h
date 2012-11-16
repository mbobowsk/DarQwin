#ifndef BANDPASSDIALOG_H
#define BANDPASSDIALOG_H

#include <QDialog>

namespace Ui {
    class BandPassDialog;
}

class BandPassDialog : public QDialog {
    Q_OBJECT
public:
    BandPassDialog(QWidget *parent = 0);
    ~BandPassDialog();
    int getInner();
    int getOuter();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BandPassDialog *ui;
};

#endif // BANDPASSDIALOG_H
