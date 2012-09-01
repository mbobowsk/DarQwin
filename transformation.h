#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <QString>

class Transformation
{
public:
    Transformation();
    virtual QString toString() = 0;
};

#endif // TRANSFORMATION_H
