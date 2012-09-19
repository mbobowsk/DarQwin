#ifndef TRANSDILATE_H
#define TRANSDILATE_H

#include "transformation.h"

class TransDilate : public Transformation
{
public:
    TransDilate();
    QString toString();
    virtual TransDilate* clone() const;
};

#endif // TRANSDILATE_H
