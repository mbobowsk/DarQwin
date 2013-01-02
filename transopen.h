#ifndef TRANSOPEN_H
#define TRANSOPEN_H

#include "transformation.h"
#define TRANS_OPEN_ID "open"

class TransOpen : public Transformation
{
public:
    TransOpen(int _size, int _iterations);
    TransOpen(int left, int top, int right, int bottom, int _size, int _iterations);
    QString toString() const;
    TransOpen* clone() const;
    QStringList getXML() const;
    int getSize();
    int getIterations();

private:
    int size;
    int iterations;
};

#endif // TRANSOPEN_H
