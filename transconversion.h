#ifndef TRANSCONVERSION_H
#define TRANSCONVERSION_H

#include "transformation.h"
#define TRANS_CONVERSION_ID "coversion"

#define GRAYSCALE 0
#define RGB 1

class TransConversion : public Transformation
{
public:
    TransConversion(int);
    QString toString() const;
    TransConversion* clone() const;
    QStringList getXML() const;
private:
    int type;
};

#endif // TRANSCONVERSION_H
