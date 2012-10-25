#ifndef TRANSDILATE_H
#define TRANSDILATE_H

#include "transformation.h"
#define TRANS_DILATE_ID "dilate"

class TransDilate : public Transformation
{
public:
    TransDilate();
    TransDilate(int left, int top, int right, int bottom);
    QString toString() const;
    virtual TransDilate* clone() const;
    QStringList getXML() const;
};

#endif // TRANSDILATE_H
