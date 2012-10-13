#ifndef THRESHOLDDIALOG_H
#define THRESHOLDDIALOG_H

#include <QDialog>

#define BINARY 0
#define BINARY_INVERTED 1

namespace Ui {
    class ThresholdDialog;
}

class ThresholdDialog : public QDialog {
    Q_OBJECT
public:
    ThresholdDialog(QWidget *parent = 0);
    ~ThresholdDialog();
    int getMode();
    int getValue();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ThresholdDialog *ui;

signals:
    void preview(int mode,int value);

private slots:
    void previewButtonPressed();
};

#endif // THRESHOLDDIALOG_H
