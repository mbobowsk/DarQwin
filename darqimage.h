#ifndef DARQIMAGE_H
#define DARQIMAGE_H

#include <QDialog>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>


class DarqImage : public QWidget
{
public:
    DarqImage(QString fileName, int width, int height);
    ~DarqImage();
    QImage *image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    bool isFinished;

protected:
    void resizeEvent(QResizeEvent *);
    void closeEvent(QCloseEvent *);
};

#endif // DARQIMAGE_H
