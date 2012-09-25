#ifndef TRANSAVERAGE_H
#define TRANSAVERAGE_H

#include "transformation.h"

class TransAverage : public Transformation
{
public:
    TransAverage(int s);
    TransAverage(int s, int left, int top, int right, int bottom);
    QString toString() const;
    TransAverage* clone() const;
private:
    int size;
};

#endif // TRANSAVERAGE_H
