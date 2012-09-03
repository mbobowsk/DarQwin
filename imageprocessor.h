#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <cv.h>
#include <vector>
#include "cvimage.h"

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
    void changeBrightness(CVImage &,char,int);
    void smoothAverage3x3(CVImage &);
    void smoothAverage5x5(CVImage &);
    void smoothMedian3x3(CVImage &);
    void smoothMedian5x5(CVImage &);
    void smoothGaussian(CVImage &);
    void smoothBilateral(CVImage &);
};

#endif // IMAGEPROCESSOR_H
