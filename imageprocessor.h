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
    void changeBrightness(CVImage *,char,int);
};

#endif // IMAGEPROCESSOR_H
