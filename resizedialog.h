#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QDialog>

#define RESIZE_SCALE 0
#define RESIZE_CUSTOM 1

namespace Ui {
    class ResizeDialog;
}

class ResizeDialog : public QDialog {
    Q_OBJECT
public:
    ResizeDialog(int currentX, int currentY, QWidget *parent = 0);
    ~ResizeDialog();
    int getMode();
    double getScaleX();
    double getScaleY();
    int getCustomX();
    int getCustomY();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ResizeDialog *ui;

};

#endif // RESIZEDIALOG_H
