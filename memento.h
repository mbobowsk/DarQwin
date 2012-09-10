#ifndef MEMENTO_H
#define MEMENTO_H

#include "transformation.h"
#include "list"
#include <cv.h>

class Memento
{
public:
    Memento(const std::list<Transformation*>& list,const cv::Mat& m);
    std::list<Transformation*> transforms;
    cv::Mat mat;
};

#endif // MEMENTO_H
