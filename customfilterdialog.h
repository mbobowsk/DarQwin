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
    CustomFilterDialog(const std::vector<float> &params, int divisor, QWidget *parent = 0);
    ~CustomFilterDialog();
    void getParams(std::vector<float> &);
    int getDivisor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CustomFilterDialog *ui;

signals:
    void preview(int divisor, std::vector<float>);
    void help();

private slots:
    void previewButtonPressed();
    void helpButtonPressed();
};

#endif // CUSTOMFILTERDIALOG_H
