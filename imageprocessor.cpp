#include "imageprocessor.h"
#include "transbrightness.h"
#include "transaverage.h"
#include "transmedian.h"
#include "transgaussian.h"
#include "transbilateral.h"
#include <QDebug>
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

void ImageProcessor::smoothAverage3x3(CVImage &img,QRect selection) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        img.transforms.push_back(new TransAverage(3));
        blur(sel,sel,Size(3,3));
    }
    else {
        Mat image = img.mat;
        img.transforms.push_back(new TransAverage(3));
        blur(image,image,Size(3,3));
    }
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

void ImageProcessor::smoothGaussian(CVImage &img) {
    img.transforms.push_back(new TransGaussian());
    Mat image = img.mat;
    GaussianBlur(image,image,Size(3,3),0,0);
    img.notify();
}

void ImageProcessor::smoothBilateral(CVImage &img, int d, int sigma1, int sigma2) {
    img.transforms.push_back(new TransBilateral(d,sigma1,sigma2));
    Mat image = img.mat.clone();
    bilateralFilter(image,img.mat,d,sigma1,sigma2,BORDER_REPLICATE);
    img.notify();
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
