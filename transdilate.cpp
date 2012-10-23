#include "transdilate.h"
#include <QStringList>

TransDilate::TransDilate()
{
    init();
}

TransDilate::TransDilate(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransDilate::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Dilation";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransDilate* TransDilate::clone() const {
    return new TransDilate(*this);
}

QStringList TransDilate::getXML() const {
    QStringList list;
    return list;
}
