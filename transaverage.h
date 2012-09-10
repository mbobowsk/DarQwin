#ifndef TRANSAVERAGE_H
#define TRANSAVERAGE_H

#include "transformation.h"

class TransAverage : public Transformation
{
public:
    TransAverage(int s);
    int size;
    QString toString();
    TransAverage* clone() const;
};

#endif // TRANSAVERAGE_H
