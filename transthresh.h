#ifndef TRANSTHRESH_H
#define TRANSTHRESH_H

#include "transformation.h"

class TransThresh : public Transformation
{
public:
    TransThresh(int mode,int value);
    QString toString() const;
    TransThresh* clone() const;
    QStringList getXML() const;
private:
    int mode;
    int value;
};

#endif // TRANSTHRESH_H
