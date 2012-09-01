#include "cvimage.h"
#include "highgui.h"

CVImage::CVImage(DarqImage *obs) {
    observer = obs;
    mat = cvLoadImageM(obs->path.toStdString().c_str());
    path = obs->path;
}

void CVImage::notify() {
    cv::Mat rgb;
    cvtColor(mat, rgb, CV_BGR2RGB);
    QImage *qimage = new QImage((const unsigned char*)(rgb.data), rgb.cols, rgb.rows, QImage::Format_RGB888);
    observer->repaint(qimage);
}

CVImage::~CVImage() {
    delete observer;
}
