#ifndef TRANSEQUALIZE_H
#define TRANSEQUALIZE_H

#include "transformation.h"

class TransEqualize : public Transformation
{
public:
    TransEqualize();
    QString toString() const;
    virtual TransEqualize* clone() const;
};

#endif // TRANSEQUALIZE_H