#include "cvimage.h"
#include "highgui.h"
#include <QDebug>

//CVImage::CVImage(DarqImage *obs, int format) {
CVImage::CVImage(QString fileName) {
    //observer = obs;
    mat = cvLoadImageM(fileName.toStdString().c_str(),CV_LOAD_IMAGE_UNCHANGED);
    int format = mat.type();
    if ( format == CV_8UC3 )
        cvtColor(mat, mat, CV_BGR2RGB);
    else if ( format == CV_8UC1 ) {
        cvtColor(mat,rgb,CV_GRAY2RGB);
    }
    path = fileName;
}

void CVImage::setObserver(DarqImage *img) {
    observer = img;
}

void CVImage::notify() {
    if ( mat.type() == CV_8UC3 )
        observer->repaint(mat);
    else {
        cvtColor(mat,rgb,CV_GRAY2RGB);
        observer->repaint(rgb);
    }
}

CVImage::~CVImage() {
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
    //TODO - poprawić, bo na bank nie działa
    QImage *qimage;
    if ( mat.channels() == 3 )
        qimage = new QImage((const unsigned char*)(mat.data), mat.cols, mat.rows, QImage::Format_RGB888);
    else
        qimage = new QImage((const unsigned char*)(mat.data), mat.cols, mat.rows, QImage::Format_Indexed8);
    qimage->save(path);
    delete qimage;
}
