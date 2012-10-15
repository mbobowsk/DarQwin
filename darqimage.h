#ifndef DARQIMAGE_H
#define DARQIMAGE_H

#include <QDialog>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QPoint>
#include <cv.h>


class DarqImage : public QWidget
{
public:
    DarqImage(QString fileName,int id, bool select, const cv::Mat&);
    ~DarqImage();
    int width;
    int height;
    int id;
    int format;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QString path;
    void repaint(const cv::Mat &mat);
    bool selectionMode;
    QRect getRect();

private:
    QPoint *beginPoint;
    QPoint *endPoint;
    QImage *current;

protected:
    void resizeEvent(QResizeEvent *);
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // DARQIMAGE_H
