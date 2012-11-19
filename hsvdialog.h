#ifndef HSVDIALOG_H
#define HSVDIALOG_H

#include <QDialog>

namespace Ui {
    class HSVDialog;
}

class HSVDialog : public QDialog {
    Q_OBJECT
public:
    HSVDialog(QWidget *parent = 0);
    ~HSVDialog();
    int getSaturation();
    int getHue();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::HSVDialog *ui;

signals:
    void preview(int hue, int saturation);

private slots:
    void previewButtonPressed();
};

#endif // HSVDIALOG_H
