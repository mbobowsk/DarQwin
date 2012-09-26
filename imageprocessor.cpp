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
#include "transthresh.h"
#include "transsobel.h"
#include "translaplacian.h"
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
        if ( img.mat.type() == CV_8UC3 ) {
            for( int y = 0; y < image.rows; y++ ) {
                for( int x = 0; x < image.cols; x++ ) {
                    for( int c = 0; c < 3; c++ ) {
                        image.at<Vec3b>(y,x)[c] =
                                saturate_cast<uchar>( image.at<Vec3b>(y,x)[c] + value );
                    }
                }
            }
        }
        else {
            for( int y = 0; y < image.rows; y++ ) {
                for( int x = 0; x < image.cols; x++ ) {
                    image.at<Vec3b>(y,x)[0] =
                            saturate_cast<uchar>( image.at<Vec3b>(y,x)[0] + value );
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
        img.transforms.push_back(new TransAverage(3,selection.left(),selection.top(),selection.right(),selection.bottom()));
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
        img.transforms.push_back(new TransAverage(5,selection.left(),selection.top(),selection.right(),selection.bottom()));
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
        img.transforms.push_back(new TransMedian((3),selection.left(),selection.top(),selection.right(),selection.bottom()));
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
        img.transforms.push_back(new TransMedian((5),selection.left(),selection.top(),selection.right(),selection.bottom()));
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
        img.transforms.push_back(new TransGaussian(selection.left(),selection.top(),selection.right(),selection.bottom()));
        GaussianBlur(sel,sel,Size(3,3),0,0);
    }
    else {
        Mat image = img.mat;
        img.transforms.push_back(new TransGaussian());
        GaussianBlur(image,image,Size(3,3),0,0);
    }
    img.notify();
}

void ImageProcessor::smoothBilateral(CVImage &img, int d, int sigma1, int sigma2, QRect selection) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        img.transforms.push_back(new TransBilateral(d,sigma1,sigma2,selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat image = img.mat.clone();
        Mat sel(img.mat,rect);
        Mat selsrc(image,rect);
        bilateralFilter(selsrc,sel,d,sigma1,sigma2,BORDER_REPLICATE);
    }
    else {
        img.transforms.push_back(new TransBilateral(d,sigma1,sigma2));
        Mat image = img.mat.clone();
        bilateralFilter(image,img.mat,d,sigma1,sigma2,BORDER_REPLICATE);
    }
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

void ImageProcessor::dilate(CVImage &img,QRect selection) {
    Mat image = img.mat;
    //OGRANICZENIE DLA OPENCV < 2.4
    if ( image.channels() != 1 )
        return;
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        img.transforms.push_back(new TransDilate(selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        cv::dilate(sel,sel,element);
    }
    else {
        img.transforms.push_back(new TransDilate());
        cv::dilate(image,image,element);
    }
    img.notify();
}

void ImageProcessor::erode(CVImage &img,QRect selection) {
    Mat image = img.mat;
    //OGRANICZENIE DLA OPENCV < 2.4
    if ( image.channels() != 1 )
        return;
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        img.transforms.push_back(new TransErode(selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        cv::erode(sel,sel,element);
    }
    else {
        img.transforms.push_back(new TransErode());
        cv::erode(image,image,element);
    }
    img.notify();
}

void ImageProcessor::open(CVImage &img,QRect selection) {
    Mat image = img.mat;
    //OGRANICZENIE DLA OPENCV < 2.4
    if ( image.channels() != 1 )
        return;
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        img.transforms.push_back(new TransOpen(selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        cv::morphologyEx(sel,sel,MORPH_OPEN,element);
    }
    else {
        img.transforms.push_back(new TransOpen());
        cv::morphologyEx(image,image,MORPH_OPEN,element);
    }
    img.notify();
}

void ImageProcessor::close(CVImage &img,QRect selection) {
    Mat image = img.mat;
    //OGRANICZENIE DLA OPENCV < 2.4
    if ( image.channels() != 1 )
        return;
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        img.transforms.push_back(new TransClose(selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        morphologyEx(sel,sel,MORPH_CLOSE,element);
    }
    else {
        img.transforms.push_back(new TransClose());
        morphologyEx(image,image,MORPH_CLOSE,element);
    }
    img.notify();
}

void ImageProcessor::gradient(CVImage &img,QRect selection) {
    Mat image = img.mat;
    //OGRANICZENIE DLA OPENCV < 2.4
    if ( image.channels() != 1 )
        return;
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3),Point(0,0));
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        img.transforms.push_back(new TransGradient(selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        morphologyEx(sel,sel,MORPH_GRADIENT,element);
    }
    else {
        img.transforms.push_back(new TransGradient());
        morphologyEx(image,image,MORPH_GRADIENT,element);
    }
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

void ImageProcessor::thresh(CVImage &img, int mode, int value) {
    Mat image = img.mat;
    img.transforms.push_back(new TransThresh(mode,value));
    //binary
    if (mode == 0) {
        threshold(image,image,value,255,THRESH_BINARY);
    }
    //binary inverted
    else {
        threshold(image,image,value,255,THRESH_BINARY_INV);
    }
    img.notify();
}

void ImageProcessor::sobel(CVImage &img) {
    /**
      * Obliczam oddzielnie gradienty w osiach X i Y.
      * Wynik jest aproksymowany sumą obydwu gradientów.
      */
    Mat image = img.mat;
    img.transforms.push_back(new TransSobel());
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Mat tmp;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    cvtColor( image, tmp, CV_RGB2GRAY );

    //Gradient X
    //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    Sobel( tmp, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );

    //Gradient Y
    //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    Sobel( tmp, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );

    //Total Gradient (approximate)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, img.mat );

    img.notify();
}

void ImageProcessor::laplace(CVImage &img) {
    Mat image = img.mat;
    img.transforms.push_back(new TransLaplacian());
    Mat tmp, tmp2;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    cvtColor( image, tmp, CV_RGB2GRAY );

    Laplacian( tmp, tmp2, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( tmp2, img.mat );

    img.notify();
}
