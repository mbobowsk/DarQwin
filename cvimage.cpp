#include "cvimage.h"
#include "highgui.h"

CVImage::CVImage(DarqImage *obs) {
    observer = obs;
    id = obs->id;
    mat = cvLoadImageM(obs->path.toStdString().c_str());
    path = obs->path;
}

void CVImage::notify() {
    cv::Mat rgb;
    cvtColor(mat, rgb, CV_BGR2RGB);
    QImage *qimage = new QImage((const unsigned char*)(rgb.data), rgb.cols, rgb.rows, QImage::Format_RGB888);
    observer->repaint(qimage);
    delete qimage;
}

CVImage::~CVImage() {
    delete observer;
}

QStringList CVImage::transformStringList() {
    QStringList list;
    for ( unsigned i = 0; i < transforms.size(); ++i) {
        list.append(transforms[i]->toString());
    }
    return list;
}
