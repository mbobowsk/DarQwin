#ifndef JPEGDIALOG_H
#define JPEGDIALOG_H

#include <QDialog>

namespace Ui {
    class JPEGDialog;
}

class JPEGDialog : public QDialog {
    Q_OBJECT
public:
    JPEGDialog(QWidget *parent = 0);
    ~JPEGDialog();
    int getValue();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::JPEGDialog *ui;
};

#endif // JPEGDIALOG_H
