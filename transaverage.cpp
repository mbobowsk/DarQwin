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
    list << "<transform name=\"" TRANS_AVERAGE_ID "\">";
    QString s1,s2,s3,s4,s5;
    s1.append("<left>");
    s1.append(QString::number(left));
    s1.append("</left>");
    s2.append("<top>");
    s2.append(QString::number(top));
    s2.append("</top>");
    s3.append("<right>");
    s3.append(QString::number(right));
    s3.append("</right>");
    s4.append("<bottom>");
    s4.append(QString::number(bottom));
    s4.append("</bottom>");
    s5.append("<size>");
    s5.append(QString::number(size));
    s5.append("</size>");
    list << s1 << s2 << s3 << s4 << s5 << "</transform>";
    return list;
}
