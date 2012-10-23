#include "transmedian.h"
#include <QStringList>

TransMedian::TransMedian(int s)
{
    size = s;
    init();
}

TransMedian::TransMedian(int s, int l, int t, int r, int b) {
    size = s;
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransMedian::toString() const {
    QString str;
    str.append("Smooth Median ");
    if (size == 3)
        str.append("3x3");
    else
        str.append("5x5");
    if ( left != 0 && right != 0 ) {
        std::ostringstream ss;
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
        std::string s = ss.str();
        str.append(s.c_str());
    }
    return str;
}

TransMedian* TransMedian::clone() const {
    return new TransMedian(*this);
}

QStringList TransMedian::getXML() const {
    QStringList list;
    return list;
}
