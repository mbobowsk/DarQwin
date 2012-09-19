#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <cv.h>
#include <vector>
#include "cvimage.h"
#include "memento.h"
#include <QRect>

using namespace cv;

class ImageProcessor
{
private:
    ImageProcessor();
public:
    static ImageProcessor& getInstance() {
        static ImageProcessor instance;
        return instance;
    }
    void changeBrightness(CVImage&,char,int);
    void smoothAverage3x3(CVImage&,QRect);
    void smoothAverage5x5(CVImage&);
    void smoothMedian3x3(CVImage&);
    void smoothMedian5x5(CVImage&);
    void smoothGaussian(CVImage&);
    void smoothBilateral(CVImage&,int,int,int);
    void restore(CVImage&,Memento*);
    void dilate(CVImage&);
    void erode(CVImage&);
    void open(CVImage&);
    void close(CVImage&);
    void gradient(CVImage&);
};

#endif // IMAGEPROCESSOR_H
