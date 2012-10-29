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

protected:
    void changeEvent(QEvent *e);

private:
    Ui::logicalFilterDialog *ui;
};

#endif // LOGICALFILTERDIALOG_H
