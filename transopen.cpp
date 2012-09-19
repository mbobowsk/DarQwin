#include "transopen.h"

TransOpen::TransOpen()
{
}

QString TransOpen::toString() {
    QString str;
    str.append("Opening");
    return str;
}

TransOpen* TransOpen::clone() const {
    return new TransOpen(*this);
}
