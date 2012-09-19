#include "transclose.h"

TransClose::TransClose()
{
}

QString TransClose::toString() {
    QString str;
    str.append("Closing");
    return str;
}

TransClose* TransClose::clone() const {
    return new TransClose(*this);
}
