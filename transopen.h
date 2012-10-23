#ifndef TRANSOPEN_H
#define TRANSOPEN_H

#include "transformation.h"

class TransOpen : public Transformation
{
public:
    TransOpen();
    TransOpen(int left, int top, int right, int bottom);
    QString toString() const;
    TransOpen* clone() const;
    QStringList getXML() const;
};

#endif // TRANSOPEN_H
