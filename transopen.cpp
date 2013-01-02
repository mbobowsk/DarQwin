#include "transopen.h"
#include <QStringList>

TransOpen::TransOpen(int _size, int _iterations)
{
    size = _size;
    iterations = _iterations;
}

TransOpen::TransOpen(int l, int t, int r, int b, int _size, int _iterations) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    size = _size;
    iterations = _iterations;
}

QString TransOpen::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Opening ";
    ss << size << 'x' << size;
    ss << '(' << iterations << ')';
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
    list << "<transform name=\"" TRANS_OPEN_ID "\">";
    QString s1,s2,s3,s4,s5,s6;
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
    s6.append("<iterations>");
    s6.append(QString::number(iterations));
    s6.append("</iterations>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << "</transform>";
    return list;
}

int TransOpen::getSize() {
    return size;
}

int TransOpen::getIterations() {
    return iterations;
}
