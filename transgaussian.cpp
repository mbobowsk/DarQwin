#include "transgaussian.h"
#include <QStringList>

TransGaussian::TransGaussian()
{
    init();
}

TransGaussian::TransGaussian(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransGaussian::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Gaussian Blur";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransGaussian* TransGaussian::clone() const {
    return new TransGaussian(*this);
}

QStringList TransGaussian::getXML() const {
    QStringList list;
    return list;
}
