#include "darqimage.h"
#include <QPixmap>

DarqImage::DarqImage(QString fileName, int idd)
{
    path = fileName;
    id = idd;
    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);

    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    //imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    QImage *image = new QImage(fileName);
    width = image->width();
    height = image->height();
    repaint(image);

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
    imageLabel->clear();
    imageLabel->setPixmap(QPixmap::fromImage(*qimage));
}
