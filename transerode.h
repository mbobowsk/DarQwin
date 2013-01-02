#ifndef TRANSERODE_H
#define TRANSERODE_H

#include "transformation.h"
#define TRANS_ERODE_ID "erode"

class TransErode : public Transformation
{
public:
    TransErode(int _size, int _iterations);
    TransErode(int left, int top, int right, int bottom, int _size, int _iterations);
    QString toString() const;
    virtual TransErode* clone() const;
    QStringList getXML() const;
    int getSize();
    int getIterations();

private:
    int size;
    int iterations;
};

#endif // TRANSERODE_H
