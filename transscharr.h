#ifndef TRANSSCHARR_H
#define TRANSSCHARR_H

#include "transformation.h"
#define TRANS_SCHARR_ID "scharr"

class TransScharr : public Transformation
{
public:
    TransScharr();
    QString toString() const;
    TransScharr* clone() const;
    QStringList getXML() const;
};

#endif // TRANSSCHARR_H
