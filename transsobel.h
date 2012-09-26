#ifndef TRANSSOBEL_H
#define TRANSSOBEL_H

#include "transformation.h"

class TransSobel : public Transformation
{
public:
    TransSobel();
    QString toString() const;
    TransSobel* clone() const;
};

#endif // TRANSSOBEL_H
