#ifndef DARQIMAGE_H
#define DARQIMAGE_H

#include <QDialog>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <cv.h>


class DarqImage : public QWidget
{
public:
    DarqImage(QString fileName);
    ~DarqImage();
    int width;
    int height;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QString path;
    bool isFinished;
    void repaint(QImage *);

protected:
    void resizeEvent(QResizeEvent *);
    void closeEvent(QCloseEvent *);
};

#endif // DARQIMAGE_H
