#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <cv.h>
#include <vector>
#include "cvimage.h"
#include "memento.h"
#include <QRect>

#define HIGH_PASS 0
#define LOW_PASS 1

using namespace cv;

/** Klasa odpowiedzialna za wykonywanie wszelkich operacji na obrazkach
  */

class ImageProcessor
{
public:
    /// Singleton
    static ImageProcessor& getInstance() {
        static ImageProcessor instance;
        return instance;
    }
    /// Funkcje wykonujące przekształcenia
    // Zwraca 0 przy poprawnym wykonaniu
    int changeBrightness(CVImage&,char,int,QRect selection,bool repaint);
    void smoothAverage3x3(CVImage&,QRect);
    void smoothAverage5x5(CVImage&,QRect);
    void smoothMedian3x3(CVImage&,QRect);
    void smoothMedian5x5(CVImage&,QRect);
    void smoothGaussian(CVImage&,QRect);
    void smoothBilateral(CVImage&,int,int,int,QRect,bool repaint);
    void restore(CVImage&,Memento*);
    void dilate(CVImage&,QRect);
    void erode(CVImage&,QRect);
    void open(CVImage&,QRect);
    void close(CVImage&,QRect);
    void gradient(CVImage&,QRect);
    void convertToGrayscale(CVImage&);
    void convertToRGB(CVImage&);
    void thresh(CVImage&,int,int,bool repaint);
    void sobel(CVImage&);
    void laplace(CVImage&);
    void scharr(CVImage&);
    void canny(CVImage&,int,bool repaint);
    void equalize(CVImage&);
    void showHistogram(CVImage&);
    void rankFilter(CVImage&,QRect,int,int,bool repaint);
    void customFilter(CVImage&,QRect,std::vector<float>,int divisor,bool repaint);
    int logicalFilter(CVImage& cvimg, QString ifStr, QString thenStr, QString elseStr, QRect selection, bool repaint);
    void calculateFFT(CVImage&, QRect rect);
    void hsv(CVImage& cvimg, QRect rect, int hue, int saturation, bool repaint);
    /// Funkcja dla transformacji nieznanego typu
    int processTransformation(CVImage& cvimg, Transformation* trans);

    void idealLowPass(CVImage&, double cutoff, QRect selection, bool repaint);
    void gaussianLowPass(CVImage&, double cutoff, QRect selection, bool repaint);
    void idealHighPass(CVImage&, double cutoff, QRect selection, bool repaint);
    void gaussianHighPass(CVImage&, double cutoff, QRect selection, bool repaint);
    void butterworthLowPass(CVImage&, double cutoff, int order, QRect selection, bool repaint);
    void butterworthHighPass(CVImage&, double cutoff, int order, QRect selection, bool repaint);
    void bandPass(CVImage&, int innerRadius, int outerRadius, QRect selection, bool repaint);

private:
    ImageProcessor();
    /// Pomocnicza funkcja sortująca piksele rgb
    static bool sortRGB(Vec3b a, Vec3b b);
    /// Zamienia ćwiartki 1-3 i 2-4 miejscami (Fourier)
    void swapQuadrants(Mat mat);
    /// Fabryka filtrów gaussa
    Mat createGaussianFilter(cv::Size size, double cutoffInPixels, int type);
    /// Fabryka filtrów idealnych
    Mat createIdealFilter(cv::Size size, double cutoffInPixels, int type);
    /// Oblicza współczynnik gaussa
    double gaussianCoeff(double u, double v, double d0);
};

#endif // IMAGEPROCESSOR_H
