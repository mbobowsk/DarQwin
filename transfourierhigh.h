#ifndef TRANSFOURIERHIGH_H
#define TRANSFOURIERHIGH_H

#include "transformation.h"

#define TRANS_FOURIERHIGH_ID "fourier-high"

class TransFourierHigh : public Transformation
{
public:
    TransFourierHigh(char t, int c, int o=0);
    TransFourierHigh(int left, int top, int right, int bottom, char t, int c, int o=0);
    QString toString() const;
    TransFourierHigh* clone() const;
    QStringList getXML() const;

    char getType();
    int getCutoff();
    int getOrder();

private:
    char type;
    int cutoff;
    int order;
};

#endif // TRANSFOURIERHIGH_H
