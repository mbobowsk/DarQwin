#ifndef TRANSERODE_H
#define TRANSERODE_H

#include "transformation.h"

class TransErode : public Transformation
{
public:
    TransErode();
    QString toString();
    virtual TransErode* clone() const;
};

#endif // TRANSERODE_H
