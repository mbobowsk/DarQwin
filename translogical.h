#ifndef TRANSLOGICAL_H
#define TRANSLOGICAL_H

#include "transformation.h"
#include <QStringList>

#define LOGIC_GRAYSCALE 0
#define LOGIC_RGB 1
#define TRANS_LOGICAL_ID "logical"

class TransLogical : public Transformation
{
public:
    TransLogical( int m, QString i, QStringList t, QStringList e );
    TransLogical( int m, QString i, QStringList t, QStringList e, int left, int top, int right, int bottom);
    QString toString() const;
    TransLogical* clone() const;
    QStringList getXML() const;

    int getMode();
    QString getIf();
    QStringList getThen();
    QStringList getElse();

private:
    int mode;
    QString ifStr;
    QStringList thenStr;
    QStringList elseStr;
};

#endif // TRANSLOGICAL_H
