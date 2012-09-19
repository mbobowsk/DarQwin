#ifndef TRANSOPEN_H
#define TRANSOPEN_H

#include "transformation.h"

class TransOpen : public Transformation
{
public:
    TransOpen();
    QString toString();
    TransOpen* clone() const;
};

#endif // TRANSOPEN_H
