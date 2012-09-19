#ifndef TRANSCLOSE_H
#define TRANSCLOSE_H

#include "transformation.h"

class TransClose : public Transformation
{
public:
    TransClose();
    QString toString();
    TransClose* clone() const;
};

#endif // TRANSCLOSE_H
