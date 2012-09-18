#include "cvimage.h"
#include "highgui.h"

CVImage::CVImage(DarqImage *obs) {
    observer = obs;
    //dirty = false;
    mat = cvLoadImageM(obs->path.toStdString().c_str());
    path = obs->path;
}

void CVImage::notify() {
    cv::Mat rgb;
    cvtColor(mat, rgb, CV_BGR2RGB);
    //observer->repaint(new QImage((const unsigned char*)(rgb.data), rgb.cols, rgb.rows, QImage::Format_RGB888));
    observer->repaint(rgb);
}

CVImage::~CVImage() {
    //delete observer;
    for ( std::list<Transformation*>::iterator it = transforms.begin(); it != transforms.end(); it++ ) {
        delete *it;
    }
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

void CVImage::save(QString path) {
    cv::Mat rgb;
    cvtColor(mat, rgb, CV_BGR2RGB);
    QImage *qimage = new QImage((const unsigned char*)(rgb.data), rgb.cols, rgb.rows, QImage::Format_RGB888);
    qimage->save(path);
}
