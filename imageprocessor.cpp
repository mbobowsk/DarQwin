#include "imageprocessor.h"
#include "transbrightness.h"
#include "transaverage.h"
#include "transmedian.h"
using namespace cv;

ImageProcessor::ImageProcessor()
{
}

void ImageProcessor::changeBrightness(CVImage &img, char type, int value) {
    Mat image = img.mat;
    img.transforms.push_back(new TransBrightness(value,type));
    switch (type) {
    case 'a':
        for( int y = 0; y < image.rows; y++ ) {
            for( int x = 0; x < image.cols; x++ ) {
                for( int c = 0; c < 3; c++ ) {
                   image.at<Vec3b>(y,x)[c] =
                                 saturate_cast<uchar>( image.at<Vec3b>(y,x)[c] + value );
                }
            }
        }
        break;

    case 'b':
        for( int y = 0; y < image.rows; y++ ) {
            for( int x = 0; x < image.cols; x++ ) {
                   image.at<Vec3b>(y,x)[0] =
                                 saturate_cast<uchar>( image.at<Vec3b>(y,x)[0] + value );
            }
        }
        break;

    case 'g':
        for( int y = 0; y < image.rows; y++ ) {
            for( int x = 0; x < image.cols; x++ ) {
                   image.at<Vec3b>(y,x)[1] =
                                 saturate_cast<uchar>( image.at<Vec3b>(y,x)[1] + value );
            }
        }
        break;

    case 'r':
        for( int y = 0; y < image.rows; y++ ) {
            for( int x = 0; x < image.cols; x++ ) {
                   image.at<Vec3b>(y,x)[2] =
                                 saturate_cast<uchar>( image.at<Vec3b>(y,x)[2] + value );
            }
        }
        break;
    }

    img.notify();
}

void ImageProcessor::smoothAverage3x3(CVImage &img) {
    img.transforms.push_back(new TransAverage(3));
    Mat image = img.mat;
    blur(image,image,Size(3,3));
    img.notify();
}

void ImageProcessor::smoothAverage5x5(CVImage &img) {
    img.transforms.push_back(new TransAverage(5));
    Mat image = img.mat;
    blur(image,image,Size(5,5));
    img.notify();
}

void ImageProcessor::smoothMedian3x3(CVImage &img) {
    img.transforms.push_back(new TransMedian(3));
    Mat image = img.mat;
    medianBlur(image,image,3);
    img.notify();
}

void ImageProcessor::smoothMedian5x5(CVImage &img) {
    img.transforms.push_back(new TransMedian(5));
    Mat image = img.mat;
    medianBlur(image,image,5);
    img.notify();
}

void ImageProcessor::smoothGaussian(CVImage &) {

}

void ImageProcessor::smoothBilateral(CVImage &) {

}

void ImageProcessor::restore(CVImage &img, Memento *mem) {
    std::list<Transformation*> list = mem->transforms;
    img.transforms.clear();
    img.mat = mem->mat.clone();

    for ( std::list<Transformation*>::iterator it = list.begin(); it != list.end(); it++) {
        Transformation* t = *it;
        img.transforms.push_back(t->clone());
    }
    img.notify();
}
