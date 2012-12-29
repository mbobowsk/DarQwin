#ifndef LOGICALFILTERDIALOG_H
#define LOGICALFILTERDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
    class logicalFilterDialog;
}

class logicalFilterDialog : public QDialog {
    Q_OBJECT
public:
    logicalFilterDialog(bool rgb, QWidget *parent = 0);
    logicalFilterDialog(QString ifStr, const QStringList &thenStr, const QStringList &elseStr, QWidget *parent = 0);
    ~logicalFilterDialog();
    QString getIf();
    QStringList getThen();
    QStringList getElse();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::logicalFilterDialog *ui;

private slots:
    void helpButtonPressed();
    void previewButtonPressed();

signals:
    void help();
    void preview(QString,QStringList,QStringList);

};

#endif // LOGICALFILTERDIALOG_H
