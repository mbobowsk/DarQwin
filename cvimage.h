#ifndef CVIMAGE_H
#define CVIMAGE_H
#include <cv.h>
#include "darqimage.h"
#include "transformation.h"
#include <list>
#include "memento.h"

class CVImage
{
public:
    //CVImage(DarqImage*,int format);
    CVImage(QString fileName);
    ~CVImage();
    cv::Mat mat;
    cv::Mat rgb;
    QString path;
    void notify();
    std::list<Transformation*> transforms;
    QStringList transformStringList();
    Memento* createMemento();
    void save(QString);
    void setObserver(DarqImage*);
private:
    DarqImage *observer;

};

#endif // CVIMAGE_H
