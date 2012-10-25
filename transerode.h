#ifndef TRANSERODE_H
#define TRANSERODE_H

#include "transformation.h"
#define TRANS_ERODE_ID "erode"

class TransErode : public Transformation
{
public:
    TransErode();
    TransErode(int left, int top, int right, int bottom);
    QString toString() const;
    virtual TransErode* clone() const;
    QStringList getXML() const;
};

#endif // TRANSERODE_H
