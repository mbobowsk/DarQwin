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
#include "transcanny.h"
#include "transscharr.h"
#include "transconversion.h"
#include "transequalize.h"
#include "transcustomfilter.h"
#include "transrankfilter.h"
#include <QDebug>
#include <QMessageBox>
#include <highgui.h>
#include <algorithm>
using namespace cv;

ImageProcessor::ImageProcessor()
{
}

void ImageProcessor::changeBrightness(CVImage &img, char type, int value, bool repaint) {
    Mat image = img.mat;
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
                    image.at<uchar>(y,x) =
                            saturate_cast<uchar>( image.at<uchar>(y,x) + value );
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
    if ( repaint ) {
        img.notify();
        img.transforms.push_back(new TransBrightness(value,type));
    }
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

void ImageProcessor::smoothBilateral(CVImage &img, int d, int sigma1, int sigma2, QRect selection, bool repaint) {
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        if ( repaint )
            img.transforms.push_back(new TransBilateral(d,sigma1,sigma2,selection.left(),selection.top(),selection.right(),selection.bottom()));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat image = img.mat.clone();
        Mat sel(img.mat,rect);
        Mat selsrc(image,rect);
        bilateralFilter(selsrc,sel,d,sigma1,sigma2,BORDER_REPLICATE);
    }
    else {
        if ( repaint )
            img.transforms.push_back(new TransBilateral(d,sigma1,sigma2));
        Mat image = img.mat.clone();
        bilateralFilter(image,img.mat,d,sigma1,sigma2,BORDER_REPLICATE);
    }
    if ( repaint )
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
    Mat tmp = image.clone();
    cvtColor(tmp,img.mat,CV_RGB2GRAY);
    img.transforms.push_back(new TransConversion(GRAYSCALE));
    img.notify();
}

void ImageProcessor::convertToRGB(CVImage &img) {
    Mat tmp = img.mat.clone();
    cv::cvtColor(tmp,img.mat,CV_GRAY2BGR);
    img.transforms.push_back(new TransConversion(RGB));
    img.notify();
}

void ImageProcessor::thresh(CVImage &img, int mode, int value, bool repaint) {
    Mat image = img.mat;
    //binary
    if (mode == 0) {
        threshold(image,image,value,255,THRESH_BINARY);
    }
    //binary inverted
    else {
        threshold(image,image,value,255,THRESH_BINARY_INV);
    }
    if ( repaint ) {
        img.notify();
        img.transforms.push_back(new TransThresh(mode,value));
    }
}

void ImageProcessor::sobel(CVImage &img) {
    Mat image = img.mat;
    img.transforms.push_back(new TransSobel());
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Mat tmp;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    if ( image.channels() == 3 )
        cvtColor( image, tmp, CV_BGR2GRAY );
    else
        tmp = image.clone();

    //Gradient X
    Sobel( tmp, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );

    //Gradient Y
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

void ImageProcessor::scharr(CVImage &img) {
    Mat image = img.mat;
    img.transforms.push_back(new TransScharr());
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Mat tmp;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    cvtColor( image, tmp, CV_RGB2GRAY );

    //Gradient X
    Scharr( tmp, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );

    //Gradient Y
    Scharr( tmp, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );

    //Total Gradient (approximate)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, img.mat );

    img.notify();
}

void ImageProcessor::canny(CVImage &img, int lowThreshold, bool repaint) {
    int ratio = 3;
    int kernel_size = 3;
    Mat image = img.mat;
    Mat tmp;
    if ( image.channels() == 3 )
        cvtColor( image, tmp, CV_BGR2GRAY );
    else
        tmp = image.clone();
    Canny( tmp, img.mat, lowThreshold, lowThreshold*ratio, kernel_size );
    if ( repaint ) {
        img.notify();
        img.transforms.push_back(new TransCanny(lowThreshold));
    }
}

void ImageProcessor::equalize(CVImage &img) {
    img.transforms.push_back(new TransEqualize());
    if ( img.mat.type() == CV_8UC1 ) {
        equalizeHist(img.mat,img.mat);
    }
    else if ( img.mat.type() == CV_8UC3 ) {
        //Wyrównanie dla każdego kanału oddzielnie
        vector<Mat> rgb_planes;
        split(img.mat,rgb_planes);
        equalizeHist(rgb_planes[0],rgb_planes[0]);
        equalizeHist(rgb_planes[1],rgb_planes[1]);
        equalizeHist(rgb_planes[2],rgb_planes[2]);
        merge(rgb_planes,img.mat);
    }
    img.notify();
}

void ImageProcessor::showHistogram(CVImage &img) {
    /** Nie działa pod Linuksem, ale generalnie działa :) */
    /**
    /// Separate the image in 3 places ( B, G and R )
    vector<Mat> bgr_planes;
    split( img.mat, bgr_planes );

    /// Establish the number of bins
    int histSize = 256;

    /// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };

    bool uniform = true; bool accumulate = false;

    if (img.mat.type() == CV_8UC3) {

        Mat b_hist, g_hist, r_hist;

        /// Compute the histograms:
        calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
        calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
        calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

        // Draw the histograms for B, G and R
        int hist_w = 512; int hist_h = 400;
        int bin_w = cvRound( (double) hist_w/histSize );

        Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

        /// Normalize the result to [ 0, histImage.rows ]
        normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
        normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
        normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

        /// Draw for each channel
        for( int i = 1; i < histSize; i++ )
        {
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                  Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                  Scalar( 255, 0, 0), 2, 8, 0  );
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                  Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                  Scalar( 0, 255, 0), 2, 8, 0  );
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                  Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                  Scalar( 0, 0, 255), 2, 8, 0  );
        }

        /// Display
        namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
        imshow("calcHist Demo", histImage );
    }
    else {

        Mat hist;

        /// Compute the histograms:
        calcHist( &bgr_planes[0], 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate );

        // Draw the histograms for B, G and R
        int hist_w = 512; int hist_h = 400;
        int bin_w = cvRound( (double) hist_w/histSize );

        Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

        /// Normalize the result to [ 0, histImage.rows ]
        normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

        /// Draw for each channel
        for( int i = 1; i < histSize; i++ )
        {
            line( histImage, Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ) ,
                  Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
                  Scalar( 100, 100, 100), 2, 8, 0  );
        }
        /// Display
        namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
        imshow("calcHist Demo", histImage );
    }*/
}

void ImageProcessor::rankFilter(CVImage &img, QRect selection, int rank, int size, bool repaint) {
    Mat image = img.mat;
    Mat dst = image.clone();
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        if ( repaint )
            img.transforms.push_back(new TransRankFilter(selection.left(),selection.top(),selection.right(),selection.bottom(),size,rank));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        //Zakres rank zmniejszony do (0,size-1) zamiast (1,size)
        rank--;
        //Grayscale
        if ( image.type() == CV_8UC1 ) {
            for( int y = 0; y < sel.rows - size; ++y ) {
                for( int x = 0; x < sel.cols - size; ++x ) {
                    //Okno analizy dla każdego punktu
                    Rect rect(x,y,size,size);
                    Mat window(sel,rect);
                    //Wektor wartości
                    std::vector<uchar> values;
                    values.reserve(size*size);
                    for( int yy = 0; yy < size; ++yy ) {
                        for( int xx = 0; xx < size; ++xx ) {
                            values.push_back(window.at<uchar>(yy,xx));
                        }
                    }
                    //Sortowanie
                    std::sort(values.begin(),values.end());
                    //Zapis do obrazka
                    dst.at<uchar>(y+selection.y(),x+selection.x()) = values[rank];
                }
            }
        }
        //RGB
        else {
            for( int y = 0; y < sel.rows - size; ++y ) {
                for( int x = 0; x < sel.cols - size; ++x ) {
                    //Okno analizy dla każdego punktu
                    Rect rect(x,y,size,size);
                    Mat window(sel,rect);
                    //Wektor wartości
                    std::vector<Vec3b> values;
                    values.reserve(size*size);
                    for( int yy = 0; yy < size; ++yy ) {
                        for( int xx = 0; xx < size; ++xx ) {
                            values.push_back(window.at<Vec3b>(yy,xx));
                        }
                    }
                    //Sortowanie
                    std::sort(values.begin(),values.end(),ImageProcessor::sortRGB);
                    //Zapis do obrazka
                    dst.at<Vec3b>(y+selection.y(),x+selection.x()) = values[rank];
                }
            }
        }
    }
    else {
        if ( repaint )
            img.transforms.push_back(new TransRankFilter(size,rank));
        //Zakres rank zmniejszony do (0,size-1) zamiast (1,size)
        rank--;
        //Grayscale
        if ( image.type() == CV_8UC1 ) {
            for( int y = 0; y < image.rows - size; ++y ) {
                for( int x = 0; x < image.cols - size; ++x ) {
                    //Okno analizy dla każdego punktu
                    Rect rect(x,y,size,size);
                    Mat window(image,rect);
                    //Wektor wartości
                    std::vector<uchar> values;
                    for( int yy = 0; yy < size; ++yy ) {
                        for( int xx = 0; xx < size; ++xx ) {
                            values.push_back(window.at<uchar>(yy,xx));
                        }
                    }
                    //Sortowanie
                    std::sort(values.begin(),values.end());
                    //Zapis do obrazka
                    dst.at<uchar>(y,x) = values[rank];
                }
            }
        }
        //RGB
        else {
            for( int y = 0; y < image.rows - size; ++y ) {
                for( int x = 0; x < image.cols - size; ++x ) {
                    //Okno analizy dla każdego punktu
                    Rect rect(x,y,size,size);
                    Mat window(image,rect);
                    //Wektor wartości
                    std::vector<Vec3b> values;
                    for( int yy = 0; yy < size; ++yy ) {
                        for( int xx = 0; xx < size; ++xx ) {
                            values.push_back(window.at<Vec3b>(yy,xx));
                        }
                    }
                    //Sortowanie
                    std::sort(values.begin(),values.end(),ImageProcessor::sortRGB);
                    //Zapis do obrazka
                    dst.at<Vec3b>(y,x) = values[rank];
                }
            }

        }
    }
    img.mat = dst;
    if ( repaint )
        img.notify();
}

void ImageProcessor::customFilter(CVImage &img, QRect selection, std::vector<float> params, int divisor, bool repaint) {
    Mat kernel;
    //Tworzę maskę filtru (3x3 lub 5x5)
    if ( params.size() == 9 ) {
        Mat tmp(3,3,CV_32F);
        tmp.at<float>(0,0) = params[0] / divisor;
        tmp.at<float>(0,1) = params[1] / divisor;
        tmp.at<float>(0,2) = params[2] / divisor;
        tmp.at<float>(1,0) = params[3] / divisor;
        tmp.at<float>(1,1) = params[4] / divisor;
        tmp.at<float>(1,2) = params[5] / divisor;
        tmp.at<float>(2,0) = params[6] / divisor;
        tmp.at<float>(2,1) = params[7] / divisor;
        tmp.at<float>(2,2) = params[8] / divisor;
        kernel = tmp.clone();
    }
    else {
        Mat tmp(5,5,CV_32F);
        tmp.at<float>(0,0) = params[0] / divisor;
        tmp.at<float>(0,1) = params[1] / divisor;
        tmp.at<float>(0,2) = params[2] / divisor;
        tmp.at<float>(0,3) = params[3] / divisor;
        tmp.at<float>(0,4) = params[4] / divisor;
        tmp.at<float>(1,0) = params[5] / divisor;
        tmp.at<float>(1,1) = params[6] / divisor;
        tmp.at<float>(1,2) = params[7] / divisor;
        tmp.at<float>(1,3) = params[8] / divisor;
        tmp.at<float>(1,4) = params[9] / divisor;
        tmp.at<float>(2,0) = params[10] / divisor;
        tmp.at<float>(2,1) = params[11] / divisor;
        tmp.at<float>(2,2) = params[12] / divisor;
        tmp.at<float>(2,3) = params[13] / divisor;
        tmp.at<float>(2,4) = params[14] / divisor;
        tmp.at<float>(3,0) = params[15] / divisor;
        tmp.at<float>(3,1) = params[16] / divisor;
        tmp.at<float>(3,2) = params[17] / divisor;
        tmp.at<float>(3,3) = params[18] / divisor;
        tmp.at<float>(3,4) = params[19] / divisor;
        tmp.at<float>(4,0) = params[20] / divisor;
        tmp.at<float>(4,1) = params[21] / divisor;
        tmp.at<float>(4,2) = params[22] / divisor;
        tmp.at<float>(4,3) = params[23] / divisor;
        tmp.at<float>(4,4) = params[24] / divisor;
        kernel = tmp.clone();
    }
    //Tylko zaznaczenie
    if ( selection.topRight().x() != 0 && selection.topRight().y() != 0 ) {
        if ( repaint )
            img.transforms.push_back(new TransCustomFilter(selection.left(),selection.top(),selection.right(),selection.bottom(),params,divisor));
        Rect rect(selection.topLeft().x(),selection.topLeft().y(),selection.width(),selection.height());
        Mat sel(img.mat,rect);
        filter2D(sel,sel,-1,kernel);
    }
    //Cały obrazek
    else {
        if ( repaint )
            img.transforms.push_back(new TransCustomFilter(params,divisor));
        filter2D(img.mat,img.mat,-1,kernel);
    }
    if ( repaint )
        img.notify();
}

bool ImageProcessor::sortRGB(Vec3b a, Vec3b b) {
    int sumA = a[0] + a[1] + a[2];
    int sumB = b[0] + b[1] + b[2];
    return (sumA < sumB);
}

void ImageProcessor::processTransformation(CVImage& cvimg, Transformation* trans) {
    QRect rect(QPoint(trans->getLeft(),trans->getTop()),QPoint(trans->getRight(),trans->getBottom()));
    TransAverage* avg = dynamic_cast<TransAverage*>(trans);
    if (avg != NULL) {
        if ( avg->getSize() == 3)
            smoothAverage3x3(cvimg,rect);
        else
            smoothAverage5x5(cvimg,rect);
        return;
    }

    TransBilateral* bil = dynamic_cast<TransBilateral*>(trans);
    if (bil != NULL) {
        smoothBilateral(cvimg,bil->getDiameter(),bil->getSigmaColor(),bil->getSigmaSpace(),rect,true);
        return;
    }

    TransBrightness* bri = dynamic_cast<TransBrightness*>(trans);
    if (bri != NULL) {
        changeBrightness(cvimg,bri->getChannel(),bri->getValue(),true);
        return;
    }

    TransCanny* can = dynamic_cast<TransCanny*>(trans);
    if (can != NULL) {
        canny(cvimg,can->getThreshold(),true);
        return;
    }

    TransClose* clo = dynamic_cast<TransClose*>(trans);
    if (clo != NULL) {
        close(cvimg,rect);
        return;
    }

    TransConversion* con = dynamic_cast<TransConversion*>(trans);
    if (con != NULL) {
        if ( con->getType() == GRAYSCALE )
            convertToGrayscale(cvimg);
        else
            convertToRGB(cvimg);
        return;
    }

    TransCustomFilter* cus = dynamic_cast<TransCustomFilter*>(trans);
    if (cus != NULL) {
        customFilter(cvimg,rect,cus->getMask(),cus->getDiv(),true);
        return;
    }

    TransDilate* dil = dynamic_cast<TransDilate*>(trans);
    if (dil != NULL) {
        dilate(cvimg,rect);
        return;
    }

    TransEqualize* equ = dynamic_cast<TransEqualize*>(trans);
    if (equ != NULL) {
        equalize(cvimg);
        return;
    }

    TransErode* ero = dynamic_cast<TransErode*>(trans);
    if (ero != NULL) {
        erode(cvimg,rect);
        return;
    }

    TransGaussian* gau = dynamic_cast<TransGaussian*>(trans);
    if (gau != NULL) {
        smoothGaussian(cvimg,rect);
        return;
    }

    TransGradient* gra = dynamic_cast<TransGradient*>(trans);
    if (gra != NULL) {
        gradient(cvimg,rect);
        return;
    }

    TransLaplacian* lap = dynamic_cast<TransLaplacian*>(trans);
    if (lap != NULL) {
        laplace(cvimg);
        return;
    }

    TransMedian* med = dynamic_cast<TransMedian*>(trans);
    if (med != NULL) {
        if ( med->getSize() == 3)
            smoothMedian3x3(cvimg,rect);
        else
            smoothMedian5x5(cvimg,rect);
        return;
    }

    TransOpen* ope = dynamic_cast<TransOpen*>(trans);
    if (ope != NULL) {
        open(cvimg,rect);
        return;
    }

    TransRankFilter* ran = dynamic_cast<TransRankFilter*>(trans);
    if (ran != NULL) {
        rankFilter(cvimg,rect,ran->getRank(),ran->getSize(),true);
        return;
    }

    TransScharr* sch  = dynamic_cast<TransScharr*>(trans);
    if (sch != NULL) {
        scharr(cvimg);
        return;
    }

    TransSobel* sob = dynamic_cast<TransSobel*>(trans);
    if (sob != NULL) {
        sobel(cvimg);
        return;
    }

    TransThresh* thr = dynamic_cast<TransThresh*>(trans);
    if (thr != NULL) {
        thresh(cvimg,thr->getMode(),thr->getValue(),true);
        return;
    }

    qDebug() << "Dziwny typ";
}
