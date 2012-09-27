#ifndef TRANSCONVERSION_H
#define TRANSCONVERSION_H

#include "transformation.h"

#define GRAYSCALE 0
#define RGB 1

class TransConversion : public Transformation
{
public:
    TransConversion(int);
    QString toString() const;
    TransConversion* clone() const;
private:
    int type;
};

#endif // TRANSCONVERSION_H
