#ifndef CUSTOMFILTERDIALOG_H
#define CUSTOMFILTERDIALOG_H

#include <QDialog>

namespace Ui {
    class CustomFilterDialog;
}

class CustomFilterDialog : public QDialog {
    Q_OBJECT
public:
    CustomFilterDialog(QWidget *parent = 0);
    ~CustomFilterDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CustomFilterDialog *ui;
};

#endif // CUSTOMFILTERDIALOG_H
