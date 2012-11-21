#ifndef NOISEDIALOG_H
#define NOISEDIALOG_H

#include <QDialog>

namespace Ui {
    class NoiseDialog;
}

class NoiseDialog : public QDialog {
    Q_OBJECT
public:
    NoiseDialog(QWidget *parent = 0);
    ~NoiseDialog();
    int getMean();
    int getDev();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::NoiseDialog *ui;
};

#endif // NOISEDIALOG_H
