#ifndef CVIMAGE_H
#define CVIMAGE_H
#include <cv.h>
#include "darqimage.h"
#include "transformation.h"
#include <vector>

class CVImage
{
public:
    CVImage(DarqImage*);
    ~CVImage();
    cv::Mat mat;
    QString path;
    int id;
    void notify();
    std::vector<Transformation*> transforms;
    QStringList transformStringList();
private:
    DarqImage *observer;

};

#endif // CVIMAGE_H
