#include "transclose.h"
#include <QStringList>

TransClose::TransClose()
{
}

TransClose::TransClose(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransClose::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Closing";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransClose* TransClose::clone() const {
    return new TransClose(*this);
}

QStringList TransClose::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_CLOSE_ID "\">";
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
