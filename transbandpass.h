#ifndef TRANSBANDPASS_H
#define TRANSBANDPASS_H

#include "transformation.h"

#define TRANS_BANDPASS_ID "band-pass"

class TransBandPass : public Transformation
{
public:
    TransBandPass(int in, int out);
    TransBandPass(int left, int top, int right, int bottom, int in, int out);
    QString toString() const;
    TransBandPass* clone() const;
    QStringList getXML() const;
    int getInner();
    int getOuter();

private:
    int innerRadius;
    int outerRadius;
};

#endif // TRANSBANDPASS_H
