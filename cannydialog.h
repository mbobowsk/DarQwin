#ifndef CANNYDIALOG_H
#define CANNYDIALOG_H

#include <QDialog>

namespace Ui {
    class CannyDialog;
}

class CannyDialog : public QDialog {
    Q_OBJECT
public:
    CannyDialog(QWidget *parent = 0);
    CannyDialog(int thresh, QWidget *parent = 0);
    ~CannyDialog();
    int getValue();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CannyDialog *ui;

signals:
    void preview(int value);
    void help();

private slots:
    void previewButtonPressed();
    void helpButtonPressed();
};

#endif // CANNYDIALOG_H
