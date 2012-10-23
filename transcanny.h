#ifndef TRANSCANNY_H
#define TRANSCANNY_H

#include "transformation.h"

class TransCanny : public Transformation
{
public:
    TransCanny(int);
    QString toString() const;
    TransCanny* clone() const;
    QStringList getXML() const;
private:
    int lowThreshold;
};

#endif // TRANSCANNY_H
