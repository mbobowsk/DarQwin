#include "transgaussian.h"

TransGaussian::TransGaussian()
{
}

QString TransGaussian::toString() {
    QString str;
    str.append("Gaussian Blur");
    return str;
}

TransGaussian* TransGaussian::clone() const {
    return new TransGaussian(*this);
}
