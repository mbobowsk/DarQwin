#ifndef CVIMAGE_H
#define CVIMAGE_H
#include <cv.h>
#include "darqimage.h"
#include "transformation.h"
#include <list>
#include "memento.h"

class CVImage
{
public:
    CVImage();
    CVImage(QString fileName);
    ~CVImage();
    //Kopiuje tyle ile jest potrzebne do wykonania preview
    //Nie jest to pełny konstruktor kopiujący
    CVImage(const CVImage& cvimage);
    cv::Mat mat;
    cv::Mat rgb;
    QString path;
    void notify();
    std::list<Transformation*> transforms;
    QStringList transformStringList();
    Memento* createMemento();
    int save(QString); //zwraca 0 przy poprawnym zapisie, 1 przy błędzie
    void setObserver(DarqImage*);
private:
    DarqImage *observer;

};

#endif // CVIMAGE_H
