#ifndef TRANSGAUSSIAN_H
#define TRANSGAUSSIAN_H

#include "transformation.h"

class TransGaussian : public Transformation
{
public:
    TransGaussian();
    QString toString();
    TransGaussian* clone() const;
};

#endif // TRANSGAUSSIAN_H
