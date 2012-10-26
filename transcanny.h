#ifndef TRANSCANNY_H
#define TRANSCANNY_H

#include "transformation.h"
#define TRANS_CANNY_ID "canny"

class TransCanny : public Transformation
{
public:
    TransCanny(int);
    QString toString() const;
    TransCanny* clone() const;
    QStringList getXML() const;
    int getThreshold();
private:
    int lowThreshold;
};

#endif // TRANSCANNY_H
