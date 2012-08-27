#include "darqimage.h"
#include <QPixmap>

DarqImage::DarqImage(QString fileName, int width, int height)
{
    isFinished = false;
    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);

    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);


    image = new QImage(fileName);
    imageLabel->setPixmap(QPixmap::fromImage(*image));
    if ( imageLabel->pixmap()->width() < width && imageLabel->pixmap()->height() < height )
        imageLabel->resize(imageLabel->pixmap()->size());
    else
        resize(width-100,height-100);

    scrollArea->setWidget(imageLabel);
    scrollArea->resize(imageLabel->size());
    setWindowTitle(fileName);
}

DarqImage::~DarqImage() {}

void DarqImage::resizeEvent(QResizeEvent *) {
    scrollArea->resize(size());
}

void DarqImage::closeEvent(QCloseEvent *) {
    isFinished = true;
}
