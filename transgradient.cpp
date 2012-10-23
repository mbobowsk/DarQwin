#include "transgradient.h"
#include <QStringList>

TransGradient::TransGradient()
{
    init();
}

TransGradient::TransGradient(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransGradient::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Morphological Gradient";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransGradient* TransGradient::clone() const {
    return new TransGradient(*this);
}

QStringList TransGradient::getXML() const {
    QStringList list;
    return list;
}
