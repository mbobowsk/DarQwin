#ifndef TRANSLAPLACIAN_H
#define TRANSLAPLACIAN_H

#include "transformation.h"
#define TRANS_LAPLACIAN_ID "laplacian"

class TransLaplacian : public Transformation
{
public:
    TransLaplacian();
    QString toString() const;
    TransLaplacian* clone() const;
    QStringList getXML() const;
};

#endif // TRANSLAPLACIAN_H
