#ifndef TRANSSOBEL_H
#define TRANSSOBEL_H

#include "transformation.h"

class TransSobel : public Transformation
{
public:
    TransSobel();
    QString toString() const;
    TransSobel* clone() const;
    QStringList getXML() const;
};

#endif // TRANSSOBEL_H
