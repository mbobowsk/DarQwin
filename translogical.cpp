#include "translogical.h"
#include <QStringList>

TransLogical::TransLogical(int m, QString i, QString t, QString e) {
    mode = m;
    ifStr = i;
    thenStr = t;
    elseStr = e;
    editable = true;
}

TransLogical::TransLogical(int m, QString i, QString t, QString e, int l, int tp, int r, int b) {
    mode = m;
    ifStr = i;
    thenStr = t;
    elseStr = e;
    left = l;
    top = tp;
    right = r;
    bottom = b;
    editable = true;
}

QString TransLogical::toString() const {
    QString str;
    str.append("Logical Filter");

    if ( left != 0 && right != 0 ) {
        std::ostringstream ss;
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
        std::string s = ss.str();
        str.append(s.c_str());
    }
    return str;
}

TransLogical* TransLogical::clone() const {
    return new TransLogical(*this);
}

QStringList TransLogical::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_LOGICAL_ID "\">";
    QString s1,s2,s3,s4,s5,s6,s7,s8;
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
    s5.append("<mode>");
    s5.append(QString::number(mode));
    s5.append("</mode>");
    s6.append("<if>");
    s6.append(ifStr);
    s6.append("</if>");
    s7.append("<then>");
    s7.append(thenStr);
    s7.append("</then>");
    s8.append("<else>");
    s8.append(elseStr);
    s8.append("</else>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << "</transform>";
    return list;
}

int TransLogical::getMode() {
    return mode;
}

QString TransLogical::getIf() {
    return ifStr;
}

QString TransLogical::getThen() {
    return thenStr;
}

QString TransLogical::getElse() {
    return elseStr;
}
