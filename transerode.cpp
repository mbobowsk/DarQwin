#include "transerode.h"
#include <QStringList>
TransErode::TransErode()
{
    init();
}

TransErode::TransErode(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransErode::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Erosion";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransErode* TransErode::clone() const {
    return new TransErode(*this);
}

QStringList TransErode::getXML() const {
    QStringList list;
    return list;
}
