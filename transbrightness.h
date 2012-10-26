#ifndef TRANSBRIGHTNESS_H
#define TRANSBRIGHTNESS_H

#include "transformation.h"
#define TRANS_BRIGHTNESS_ID "brightness"

class TransBrightness : public Transformation
{
public:
    TransBrightness(int v, char ch);
    TransBrightness(int top, int left, int bottom, int right, int v, char ch);
    QString toString() const;
    virtual TransBrightness* clone() const;
    QStringList getXML() const;
    int getValue();
    char getChannel();
private:
    int value;
    char channel;
};

#endif // TRANSBRIGHTNESS_H
