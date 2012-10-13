#ifndef BRIGHTNESSDIALOG_H
#define BRIGHTNESSDIALOG_H

#include <QDialog>
#include <utility> //dla pair
#include <QtGui>

namespace Ui {
    class brightnessDialog;
}

class brightnessDialog : public QDialog {
    Q_OBJECT
public:
    brightnessDialog(QWidget *parent = 0);
    ~brightnessDialog();
    std::pair<char,int> getValue();
    void setGrayscaleButtons();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::brightnessDialog *ui;

signals:
    void preview(char type, int value);

private slots:
    void previewButtonPressed();
};

#endif // BRIGHTNESSDIALOG_H
