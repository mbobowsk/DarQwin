#ifndef TRANSTHRESH_H
#define TRANSTHRESH_H

#include "transformation.h"
#define TRANS_THRESH_ID "thresh"

class TransThresh : public Transformation
{
public:
    TransThresh(int mode,int value);
    QString toString() const;
    TransThresh* clone() const;
    QStringList getXML() const;
    int getValue();
    int getMode();
private:
    int mode;
    int value;
};

#endif // TRANSTHRESH_H
