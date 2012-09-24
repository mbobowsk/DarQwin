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
    void smoothAverage5x5(CVImage&,QRect);
    void smoothMedian3x3(CVImage&,QRect);
    void smoothMedian5x5(CVImage&,QRect);
    void smoothGaussian(CVImage&,QRect);
    void smoothBilateral(CVImage&,int,int,int,QRect);
    void restore(CVImage&,Memento*);
    void dilate(CVImage&,QRect);
    void erode(CVImage&,QRect);
    void open(CVImage&,QRect);
    void close(CVImage&,QRect);
    void gradient(CVImage&,QRect);
    void convertToGrayscale(CVImage&);
    void convertToRGB(CVImage&);
};

#endif // IMAGEPROCESSOR_H
