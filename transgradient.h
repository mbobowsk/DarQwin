#ifndef TRANSGRADIENT_H
#define TRANSGRADIENT_H

#include "transformation.h"
#define TRANS_GRADIENT_ID "gradient"

class TransGradient : public Transformation
{
public:
    TransGradient(int _size, int _iterations);
    TransGradient(int left, int top, int right, int bottom, int _size, int _iterations);
    QString toString() const;
    TransGradient* clone() const;
    QStringList getXML() const;
    int getSize();
    int getIterations();

private:
    int size;
    int iterations;
};

#endif // TRANSGRADIENT_H
