#ifndef TRANSMEDIAN_H
#define TRANSMEDIAN_H

#include "transformation.h"
#define TRANS_MEDIAN_ID "median"

class TransMedian : public Transformation
{
public:
    TransMedian(int s);
    TransMedian(int s, int left, int top, int right, int bottom);
    QString toString() const;
    TransMedian* clone() const;
    QStringList getXML() const;
private:
    int size;
};

#endif // TRANSMEDIAN_H
