#include "darqimage.h"
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>

DarqImage::DarqImage(QString fileName, int idd)
{
    path = fileName;
    id = idd;
    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    markPoint = new QPoint();

    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    //imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    current = new QImage(fileName);
    width = current->width();
    height = current->height();
    imageLabel->setPixmap(QPixmap::fromImage(*current));

    scrollArea->setWidget(imageLabel);
    setWindowTitle(fileName);
}

DarqImage::~DarqImage() {}

void DarqImage::resizeEvent(QResizeEvent *) {
    scrollArea->resize(size());
}

void DarqImage::closeEvent(QCloseEvent *) {

}

void DarqImage::repaint(QImage *qimage) {
    delete current;
    current = qimage;
    imageLabel->clear();
    imageLabel->setPixmap(QPixmap::fromImage(*qimage));
}

void DarqImage::mousePressEvent(QMouseEvent *e) {
    qDebug() << "Press: " << e->x() << " " << e->y();
    markPoint->setX((int)e->x());
    markPoint->setY((int)e->y());
}

void DarqImage::mouseReleaseEvent(QMouseEvent *e) {
    qDebug() << "Release: " << e->x() << " " << e->y();
    QPoint *endPoint = new QPoint((int)e->x(),(int)e->y());
    QImage markingImage = current->copy();
    QPainter painter(&markingImage);
    painter.setPen(Qt::DashLine);
    painter.drawRect(QRect(*markPoint,*endPoint));
    imageLabel->setPixmap(QPixmap::fromImage(markingImage));
}

void DarqImage::mouseMoveEvent(QMouseEvent *e) {
    qDebug() << "Moved: " << e->x() << " " << e->y();
    QPoint *endPoint = new QPoint((int)e->x(),(int)e->y());
    QImage markingImage = current->copy();
    QPainter painter(&markingImage);
    painter.setPen(Qt::DashLine);
    painter.drawRect(QRect(*markPoint,*endPoint));
    imageLabel->setPixmap(QPixmap::fromImage(markingImage));
}
