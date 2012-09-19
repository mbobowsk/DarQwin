#include "transerode.h"
TransErode::TransErode()
{
}

QString TransErode::toString() {
    QString str;
    str.append("Erosion");
    return str;
}

TransErode* TransErode::clone() const {
    return new TransErode(*this);
}
