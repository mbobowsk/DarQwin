#include "transdilate.h"

TransDilate::TransDilate()
{
}

QString TransDilate::toString() {
    QString str;
    str.append("Dilation");
    return str;
}

TransDilate* TransDilate::clone() const {
    return new TransDilate(*this);
}
