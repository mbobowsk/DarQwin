#ifndef TRANSSCHARR_H
#define TRANSSCHARR_H

#include "transformation.h"

class TransScharr : public Transformation
{
public:
    TransScharr();
    QString toString() const;
    TransScharr* clone() const;
    QStringList getXML() const;
};

#endif // TRANSSCHARR_H
