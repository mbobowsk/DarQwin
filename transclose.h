#ifndef TRANSCLOSE_H
#define TRANSCLOSE_H

#include "transformation.h"

class TransClose : public Transformation
{
public:
    TransClose();
    TransClose(int left, int top, int right, int bottom);
    QString toString() const;
    TransClose* clone() const;
};

#endif // TRANSCLOSE_H
