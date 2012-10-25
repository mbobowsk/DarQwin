#ifndef TRANSGRADIENT_H
#define TRANSGRADIENT_H

#include "transformation.h"
#define TRANS_GRADIENT_ID "gradient"

class TransGradient : public Transformation
{
public:
    TransGradient();
    TransGradient(int left, int top, int right, int bottom);
    QString toString() const;
    TransGradient* clone() const;
    QStringList getXML() const;
};

#endif // TRANSGRADIENT_H
