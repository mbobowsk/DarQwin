#include "cvimage.h"
#include "highgui.h"
#include <QDebug>

CVImage::CVImage(DarqImage *obs) {
    observer = obs;
    id = obs->id;
    mat = cvLoadImageM(obs->path.toStdString().c_str());
    path = obs->path;
}

void CVImage::notify() {
    //qDebug() << mat.at<cv::Vec3b>(0,0)[0];

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
    for ( std::list<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
        list.append((*it)->toString());
    }
    return list;
}

Memento* CVImage::createMemento() {
    return new Memento(transforms,mat);
}
