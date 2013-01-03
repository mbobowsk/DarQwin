#ifndef MORPHDIALOG_H
#define MORPHDIALOG_H

#include <QDialog>

#define ERODE 0
#define DILATE 1
#define OPEN 2
#define CLOSE 3
#define GRADIENT 4

namespace Ui {
    class MorphDialog;
}

class MorphDialog : public QDialog {
    Q_OBJECT
public:
    MorphDialog(int _type, QWidget *parent = 0);
    MorphDialog(int _type, int _size, int _iter, QWidget *parent = 0);
    ~MorphDialog();
    int getSize();
    int getIterations();
    int type;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MorphDialog *ui;

signals:
    void preview(int size, int iterations, int type);
    void help();

private slots:
    void previewButtonPressed();
    void helpButtonPressed();

    void sizeOdd(int value);
};

#endif // MORPHDIALOG_H
