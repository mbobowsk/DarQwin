#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QString>
#include <sstream>

class Transformation
{
public:
    Transformation(){};
    virtual ~Transformation(){};
    virtual QString toString() = 0;
    virtual Transformation* clone() const = 0;
    int size;
    int left;
    int top;
    int right;
    int bottom;
};

#endif // TRANSFORMATION_H
