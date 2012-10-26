#ifndef TRANSBILATERAL_H
#define TRANSBILATERAL_H

#include "transformation.h"
#define TRANS_BILATERAL_ID "bilateral"

class TransBilateral : public Transformation
{
public:
    TransBilateral(int,int,int);
    TransBilateral(int d, int sc, int ss, int left, int top, int right, int bottom);
    QString toString() const;
    TransBilateral* clone() const;
    QStringList getXML() const;
    int getDiameter();
    int getSigmaColor();
    int getSigmaSpace();
private:
    int diameter;
    int sigmaColor;
    int sigmaSpace;
};

#endif // TRANSBILATERAL_H
