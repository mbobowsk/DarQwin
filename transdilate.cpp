#include "transdilate.h"
#include <QStringList>

TransDilate::TransDilate(int _size, int _iterations)
{
    size = _size;
    iterations = _iterations;
    editable = true;
}

TransDilate::TransDilate(int l, int t, int r, int b,int _size, int _iterations) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    size = _size;
    iterations = _iterations;
    editable = true;
}

QString TransDilate::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Dilation ";
    ss << size << 'x' << size;
    ss << '(' << iterations << ')';
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
    list << "<transform name=\"" TRANS_DILATE_ID "\">";
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

int TransDilate::getSize() {
    return size;
}

int TransDilate::getIterations() {
    return iterations;
}
