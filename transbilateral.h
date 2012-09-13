#ifndef TRANSBILATERAL_H
#define TRANSBILATERAL_H

#include "transformation.h"

class TransBilateral : public Transformation
{
public:
    TransBilateral(int,int,int);
    QString toString();
    TransBilateral* clone() const;
private:
    int diameter;
    int sigmaColor;
    int sigmaSpace;
};

#endif // TRANSBILATERAL_H
