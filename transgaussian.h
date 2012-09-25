#ifndef TRANSGAUSSIAN_H
#define TRANSGAUSSIAN_H

#include "transformation.h"

class TransGaussian : public Transformation
{
public:
    TransGaussian();
    TransGaussian(int left, int top, int right, int bottom);
    QString toString() const;
    TransGaussian* clone() const;
};

#endif // TRANSGAUSSIAN_H
