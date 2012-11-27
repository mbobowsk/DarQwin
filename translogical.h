#ifndef TRANSLOGICAL_H
#define TRANSLOGICAL_H

#include "transformation.h"
#include <QString>

#define LOGIC_GRAYSCALE 0
#define LOGIC_RGB 1
#define TRANS_LOGICAL_ID "logical"

class TransLogical : public Transformation
{
public:
    TransLogical( int m, QString i, QString t, QString e );
    TransLogical( int m, QString i, QString t, QString e, int left, int top, int right, int bottom);
    QString toString() const;
    TransLogical* clone() const;
    QStringList getXML() const;

    int getMode();
    QString getIf();
    QString getThen();
    QString getElse();

private:
    int mode;
    QString ifStr;
    QString thenStr;
    QString elseStr;
};

#endif // TRANSLOGICAL_H
