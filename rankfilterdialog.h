#ifndef RANKFILTERDIALOG_H
#define RANKFILTERDIALOG_H

#include <QDialog>

namespace Ui {
    class rankFilterDialog;
}

class rankFilterDialog : public QDialog {
    Q_OBJECT
public:
    rankFilterDialog(QWidget *parent = 0);
    ~rankFilterDialog();
    int getValue();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::rankFilterDialog *ui;

private slots:
    void button3x3Pressed();
    void button5x5Pressed();
};

#endif // RANKFILTERDIALOG_H
