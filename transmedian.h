#ifndef TRANSMEDIAN_H
#define TRANSMEDIAN_H

#include "transformation.h"

class TransMedian : public Transformation
{
public:
    TransMedian(int s);
    int size;
    QString toString();
    TransMedian* clone() const;
};

#endif // TRANSMEDIAN_H
