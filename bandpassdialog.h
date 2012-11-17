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

signals:
    void preview(int inner, int outer);

private slots:
    void previewButtonPressed();
};

#endif // BANDPASSDIALOG_H
