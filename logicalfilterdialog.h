#ifndef LOGICALFILTERDIALOG_H
#define LOGICALFILTERDIALOG_H

#include <QDialog>

namespace Ui {
    class logicalFilterDialog;
}

class logicalFilterDialog : public QDialog {
    Q_OBJECT
public:
    logicalFilterDialog(QWidget *parent = 0);
    ~logicalFilterDialog();
    QString getIf();
    QString getThen();
    QString getElse();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::logicalFilterDialog *ui;

private slots:
    void helpButtonPressed();

signals:
    void help();

};

#endif // LOGICALFILTERDIALOG_H
