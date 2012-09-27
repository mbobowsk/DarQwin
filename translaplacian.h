#ifndef TRANSLAPLACIAN_H
#define TRANSLAPLACIAN_H

#include "transformation.h"

class TransLaplacian : public Transformation
{
public:
    TransLaplacian();
    QString toString() const;
    TransLaplacian* clone() const;
};

#endif // TRANSLAPLACIAN_H