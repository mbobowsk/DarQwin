#include "imageprocessor.h"
#include "transbrightness.h"
#include "transaverage.h"
#include "transmedian.h"
#include "transgaussian.h"
#include "transbilateral.h"
#include "transdilate.h"
#include "transerode.h"
#include "transopen.h"
#include "transclose.h"
#include "transgradient.h"
#include <QDebug>
#include <QMessageBox>
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

    case 'r':
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

    case 'b':
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

void ImageProcessor::smoothAverage5x5(CVImage &img,QRect selection) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        img.transforms.push_back(new TransAverage(5));
        blur(sel,sel,Size(5,5));
    }
    else {
        Mat image = img.mat;
        img.transforms.push_back(new TransAverage(5));
        blur(image,image,Size(5,5));
    }
    img.notify();

}

void ImageProcessor::smoothMedian3x3(CVImage &img,QRect selection) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        img.transforms.push_back(new TransMedian(3));
        medianBlur(sel,sel,3);
    }
    else {
        Mat image = img.mat;
        img.transforms.push_back(new TransMedian(3));
        medianBlur(image,image,3);
    }
    img.notify();
}

void ImageProcessor::smoothMedian5x5(CVImage &img,QRect selection) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        img.transforms.push_back(new TransMedian(5));
        medianBlur(sel,sel,5);
    }
    else {
        Mat image = img.mat;
        img.transforms.push_back(new TransMedian(5));
        medianBlur(image,image,5);
    }
    img.notify();
}

void ImageProcessor::smoothGaussian(CVImage &img,QRect selection) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        img.transforms.push_back(new TransGaussian());
        GaussianBlur(sel,sel,Size(3,3),0,0);
    }
    else {
        Mat image = img.mat;
        img.transforms.push_back(new TransGaussian());
        GaussianBlur(image,image,Size(3,3),0,0);
    }
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

void ImageProcessor::dilate(CVImage &img) {
    Mat image = img.mat;
    qDebug() << "Channels: " << image.channels();
    if ( image.channels() != 1 )
        return;
    img.transforms.push_back(new TransDilate());
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    cv::dilate(image,image,element);
    img.notify();
}

void ImageProcessor::erode(CVImage &img) {
    Mat image = img.mat;
    if ( image.channels() != 1 )
        return;
    img.transforms.push_back(new TransErode());
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    cv::erode(image,image,element);
    img.notify();
}

void ImageProcessor::open(CVImage &img) {
    Mat image = img.mat;
    if ( image.channels() != 1 )
        return;
    img.transforms.push_back(new TransOpen());
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    cv::morphologyEx(image,image,MORPH_OPEN,element);
    img.notify();
}

void ImageProcessor::close(CVImage &img) {
    Mat image = img.mat;
    if ( image.channels() != 1 )
        return;
    img.transforms.push_back(new TransClose());
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    morphologyEx(image,image,MORPH_CLOSE,element);
    img.notify();
}

void ImageProcessor::gradient(CVImage &img) {
    Mat image = img.mat;
    if ( image.channels() != 1 )
        return;
    img.transforms.push_back(new TransGradient());
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    morphologyEx(image,image,MORPH_GRADIENT,element);
    img.notify();
}

void ImageProcessor::convertToGrayscale(CVImage &img) {
    Mat image = img.mat;
    //Mat tmp = image.clone();
    //image.release();
    //tmp.convertTo(image,CV_8UC1);
    //cvtColor(tmp,image,CV_RGB2GRAY);
    //blur(image,image,Size(5,5));
    img.notify();
}

void ImageProcessor::convertToRGB(CVImage &img) {
    //cv::cvtColor(cvimage->mat,cvimage->mat);
}
