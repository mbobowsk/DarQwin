#include "transgradient.h"

TransGradient::TransGradient()
{
}

QString TransGradient::toString() {
    QString str;
    str.append("Morphological Gradient");
    return str;
}

TransGradient* TransGradient::clone() const {
    return new TransGradient(*this);
}
