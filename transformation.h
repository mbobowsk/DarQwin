#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QString>
#include <sstream>

class Transformation
{
public:
    Transformation();
    virtual ~Transformation(){};
    virtual QString toString() const = 0;
    virtual Transformation* clone() const = 0;
    virtual QStringList getXML() const = 0;
    int getLeft();
    int getRight();
    int getTop();
    int getBottom();
protected:
    int left;
    int top;
    int right;
    int bottom;
};

#endif // TRANSFORMATION_H
