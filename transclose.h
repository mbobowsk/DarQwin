#ifndef TRANSCLOSE_H
#define TRANSCLOSE_H

#include "transformation.h"
#define TRANS_CLOSE_ID "close"

class TransClose : public Transformation
{
public:
    TransClose(int _size, int _iterations);
    TransClose(int left, int top, int right, int bottom, int _size, int _iterations);
    QString toString() const;
    TransClose* clone() const;
    QStringList getXML() const;
    int getSize();
    int getIterations();

private:
    int size;
    int iterations;
};

#endif // TRANSCLOSE_H
