#ifndef TRANSHSV_H
#define TRANSHSV_H

#define TRANS_HSV_ID "hsv"
#include "transformation.h"

class TransHSV : public Transformation
{
public:
    TransHSV(int hue, int saturation);
    TransHSV(int left, int top, int right, int bottom, int hue, int saturation);
    QString toString() const;
    TransHSV* clone() const;
    QStringList getXML() const;
    int getHue();
    int getSaturation();

private:
    int hue;
    int saturation;
};

#endif // TRANSHSV_H
