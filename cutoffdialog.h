#ifndef CUTOFFDIALOG_H
#define CUTOFFDIALOG_H

#include <QDialog>

#define LOW_GAUSSIAN 0
#define LOW_IDEAL 1
#define HIGH_GAUSSIAN 2
#define HIGH_IDEAL 3

namespace Ui {
    class CutoffDialog;
}

class CutoffDialog : public QDialog {
    Q_OBJECT
public:
    CutoffDialog(int type, QWidget *parent = 0);
    ~CutoffDialog();
    int getCutoff();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CutoffDialog *ui;
    int type;

signals:
    void preview(int cutoff, int type);
    void help();

private slots:
    void previewButtonPressed();
    void helpButtonPressed();
};

#endif // CUTOFFDIALOG_H
