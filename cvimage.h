#ifndef CVIMAGE_H
#define CVIMAGE_H
#include <cv.h>
#include "darqimage.h"

class CVImage
{
public:
    CVImage(DarqImage*);
    ~CVImage();
    cv::Mat mat;
    QString path;
    void notify();
private:
    DarqImage *observer;

};

#endif // CVIMAGE_H
