#ifndef TRANSAVERAGE_H
#define TRANSAVERAGE_H

#include "transformation.h"

class TransAverage : public Transformation
{
public:
    TransAverage(int s);
    TransAverage(int s, int left, int top, int right, int bottom);
    QString toString();
    TransAverage* clone() const;
};

#endif // TRANSAVERAGE_H
