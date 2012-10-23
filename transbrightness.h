#ifndef TRANSBRIGHTNESS_H
#define TRANSBRIGHTNESS_H

#include "transformation.h"

class TransBrightness : public Transformation
{
public:
    TransBrightness(int v, char ch);
    QString toString() const;
    virtual TransBrightness* clone() const;
    QStringList getXML() const;
private:
    int value;
    char channel;
};

#endif // TRANSBRIGHTNESS_H
