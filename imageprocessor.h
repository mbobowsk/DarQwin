#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <cv.h>
#include <vector>

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
};

#endif // IMAGEPROCESSOR_H
