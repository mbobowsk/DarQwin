#include "transaverage.h"

TransAverage::TransAverage(int s)
{
    size = s;
}

QString TransAverage::toString() {
    QString str;
    str.append("Smooth Average ");
    if (size == 3)
        str.append("3x3");
    else
        str.append("5x5");
    return str;
}

TransAverage* TransAverage::clone() const {
    return new TransAverage(*this);
}
