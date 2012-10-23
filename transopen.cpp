#include "transopen.h"
#include <QStringList>

TransOpen::TransOpen()
{
    init();
}

TransOpen::TransOpen(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransOpen::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Opening";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransOpen* TransOpen::clone() const {
    return new TransOpen(*this);
}

QStringList TransOpen::getXML() const {
    QStringList list;
    list << "<transform name=\"open\">";
    QString s1,s2,s3,s4;
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
    list << s1 << s2 << s3 << s4 << "</transform>";
    return list;
}
