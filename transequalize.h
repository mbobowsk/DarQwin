#ifndef TRANSEQUALIZE_H
#define TRANSEQUALIZE_H

#include "transformation.h"
#define TRANS_EQUALIZE_ID "equalize"

class TransEqualize : public Transformation
{
public:
    TransEqualize();
    QString toString() const;
    virtual TransEqualize* clone() const;
    QStringList getXML() const;
};

#endif // TRANSEQUALIZE_H
