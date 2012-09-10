#include "transmedian.h"

TransMedian::TransMedian(int s)
{
    size = s;
}

QString TransMedian::toString() {
    QString str;
    str.append("Smooth Median ");
    if (size == 3)
        str.append("3x3");
    else
        str.append("5x5");
    return str;
}

TransMedian* TransMedian::clone() const {
    return new TransMedian(*this);
}
