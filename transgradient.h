#ifndef TRANSGRADIENT_H
#define TRANSGRADIENT_H

#include "transformation.h"

class TransGradient : public Transformation
{
public:
    TransGradient();
    QString toString();
    TransGradient* clone() const;
};

#endif // TRANSGRADIENT_H
