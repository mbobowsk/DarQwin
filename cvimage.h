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
    CVImage(DarqImage*);
    ~CVImage();
    cv::Mat mat;
    QString path;
    int id;
    void notify();
    std::list<Transformation*> transforms;
    QStringList transformStringList();
    Memento* createMemento();
private:
    DarqImage *observer;

};

#endif // CVIMAGE_H
