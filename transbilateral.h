#ifndef TRANSBILATERAL_H
#define TRANSBILATERAL_H

#include "transformation.h"

class TransBilateral : public Transformation
{
public:
    TransBilateral(int,int,int);
    TransBilateral(int d, int sc, int ss, int left, int top, int right, int bottom);
    QString toString() const;
    TransBilateral* clone() const;
private:
    int diameter;
    int sigmaColor;
    int sigmaSpace;
};

#endif // TRANSBILATERAL_H
