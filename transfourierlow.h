#ifndef TRANSFOURIERLOW_H
#define TRANSFOURIERLOW_H

#include "transformation.h"

#define TRANS_FOURIERLOW_ID "fourier-low"

class TransFourierLow : public Transformation
{
public:
    TransFourierLow(char t, int c, int o=0);
    TransFourierLow(int left, int top, int right, int bottom, char t, int c, int o=0);
    QString toString() const;
    TransFourierLow* clone() const;
    QStringList getXML() const;

    char getType();
    int getCutoff();
    int getOrder();

private:
    char type;
    int cutoff;
    int order;
};

#endif // TRANSFOURIERLOW_H
