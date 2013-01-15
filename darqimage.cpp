#include "darqimage.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <highgui.h>
using namespace cv;

DarqImage::DarqImage(QString fileName, int idd, bool select, const cv::Mat &mat) {
    path = fileName;
    id = idd;
    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    beginPoint = new QPoint(0,0);
    endPoint = new QPoint(0,0);
    selectionMode = select;

    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    //imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    current = new QImage( mat.cols, mat.rows, QImage::Format_RGB888);

    for(int i=0; i<mat.cols; i++){
        for(int j=0; j<mat.rows; j++){
            current->setPixel(i,j, qRgb(mat.at<Vec3b>(j,i)[0],mat.at<Vec3b>(j,i)[1],mat.at<Vec3b>(j,i)[2]) );
        }
    }

    width = current->width();
    height = current->height();
    format = current->format();

    imageLabel->setPixmap(QPixmap::fromImage(*current));

    scrollArea->setWidget(imageLabel);
    setWindowTitle(fileName);
}

DarqImage::~DarqImage() {
    delete beginPoint;
    delete endPoint;
    delete current;
    delete imageLabel;
    delete scrollArea;
}

void DarqImage::resizeEvent(QResizeEvent *) {
    scrollArea->resize(size());
}

void DarqImage::closeEvent(QCloseEvent *) {

}

void DarqImage::repaint(const cv::Mat &mat, bool clearSelection) {
    delete current;

    current = new QImage( mat.cols, mat.rows, QImage::Format_RGB888);

    for(int i=0; i<mat.cols; i++){
        for(int j=0; j<mat.rows; j++){
            current->setPixel(i,j, qRgb(mat.at<Vec3b>(j,i)[0],mat.at<Vec3b>(j,i)[1],mat.at<Vec3b>(j,i)[2]) );
        }
    }

    //current = new QImage((const unsigned char*)(mat.data), mat.cols, mat.rows, QImage::Format_RGB888);
    imageLabel->clear();

    if ( clearSelection ) {
        endPoint->setX(0);
        endPoint->setY(0);
        beginPoint->setX(0);
        beginPoint->setY(0);
    }
    else {
        QPainter painter(current);
        painter.setPen(Qt::DashLine);
        painter.drawRect(QRect(*beginPoint,*endPoint));
    }
    imageLabel->resize(current->width(),current->height());
    imageLabel->setPixmap(QPixmap::fromImage(*current));

    width = current->width();
    height = current->height();
}

void DarqImage::mousePressEvent(QMouseEvent *e) {
    if ( selectionMode ) {
        beginPoint->setX(e->x());
        beginPoint->setY(e->y());
    }
}

void DarqImage::mouseReleaseEvent(QMouseEvent *e) {
    if ( selectionMode ) {
        endPoint->setX(e->x());
        endPoint->setY(e->y());
        if ( endPoint->x() != beginPoint->x() && endPoint->y() != beginPoint->y() ) {
            endPoint->setX(e->x());
            endPoint->setY(e->y());
            QImage markingImage = current->copy();
            QPainter painter(&markingImage);
            //ustalenie koloru
            QPen pen;
            pen.setStyle(Qt::DashLine);
            QColor c = QColor::fromRgb(markingImage.pixel(beginPoint->x(),beginPoint->y()));
            if ( c.red() + c.green() + c.blue() < 300 ) {
                pen.setColor(QColor(255,255,255,255));
            }
            painter.setPen(pen);
            painter.drawRect(QRect(*beginPoint,*endPoint));
            imageLabel->setPixmap(QPixmap::fromImage(markingImage));
        }
        else {
            imageLabel->setPixmap(QPixmap::fromImage(*current));
            endPoint->setX(0);
            endPoint->setY(0);
            beginPoint->setX(0);
            beginPoint->setY(0);
        }
    }
}

void DarqImage::mouseMoveEvent(QMouseEvent *e) {
    if ( selectionMode && beginPoint->x() != 0 && beginPoint->y() != 0 ) {
        QPoint endPoint(e->x(),e->y());
        QImage markingImage = current->copy();
        QPainter painter(&markingImage);
        //ustalenie koloru
        QPen pen;
        pen.setStyle(Qt::DashLine);
        QColor c = QColor::fromRgb(markingImage.pixel(beginPoint->x(),beginPoint->y()));
        if ( c.red() + c.green() + c.blue() < 300 ) {
            pen.setColor(QColor(255,255,255,255));
        }
        painter.setPen(pen);
        painter.drawRect(QRect(*beginPoint,endPoint));

        imageLabel->setPixmap(QPixmap::fromImage(markingImage));
    }
}

QRect DarqImage::getRect() {
    int x1 = beginPoint->x();
    int y1 = beginPoint->y();
    int x2 = endPoint->x();
    int y2 = endPoint->y();

    if ( x2 > x1 && y2 > y1 )
        return QRect(*beginPoint,*endPoint);
    if ( x1 > x2 && y1 > y2 )
        return QRect(*endPoint,*beginPoint);
    if ( x1 > x2 && y1 < y2 )
        return QRect(x2,y1,x1-x2,y2-y1);
    return QRect(x1,y2,x2-x1,y1-y2);
}
