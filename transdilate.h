#ifndef TRANSDILATE_H
#define TRANSDILATE_H

#include "transformation.h"
#define TRANS_DILATE_ID "dilate"

class TransDilate : public Transformation
{
public:
    TransDilate(int _size, int _iterations);
    TransDilate(int left, int top, int right, int bottom, int _size, int _iterations);
    QString toString() const;
    virtual TransDilate* clone() const;
    QStringList getXML() const;
    int getSize();
    int getIterations();

private:
    int size;
    int iterations;
};

#endif // TRANSDILATE_H
