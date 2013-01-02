#ifndef MORPHDIALOG_H
#define MORPHDIALOG_H

#include <QDialog>

namespace Ui {
    class MorphDialog;
}

class MorphDialog : public QDialog {
    Q_OBJECT
public:
    MorphDialog(QWidget *parent = 0);
    ~MorphDialog();
    int getSize();
    int getIterations();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MorphDialog *ui;

signals:
    void preview(int size, int iterations);
    void help();

private slots:
    void previewButtonPressed();
    void helpButtonPressed();

    void iterationsOdd(int value);
    void sizeOdd(int value);
};

#endif // MORPHDIALOG_H
