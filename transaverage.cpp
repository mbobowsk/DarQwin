#include "transaverage.h"
#include <QStringList>

TransAverage::TransAverage(int s) {
    size = s;
    init();
}

TransAverage::TransAverage(int s, int l, int t, int r, int b) {
    size = s;
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransAverage::toString() const {
    QString str;
    str.append("Smooth Average ");
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

TransAverage* TransAverage::clone() const {
    return new TransAverage(*this);
}

QStringList TransAverage::getXML() const {
    QStringList list;
    return list;
}
