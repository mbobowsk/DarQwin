#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QString>

class Transformation
{
public:
    Transformation(){};
    virtual ~Transformation(){};
    virtual QString toString() = 0;
    virtual Transformation* clone() const = 0;
};

#endif // TRANSFORMATION_H
