#include "transfourierlow.h"
#include <QStringList>

TransFourierLow::TransFourierLow(char t, int c, int o) {
    type = t;
    cutoff = c;
    order = o;
}

TransFourierLow::TransFourierLow(int l, int t, int r, int b, char tt, int c, int o) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    type = tt;
    cutoff = c;
    order = o;
}

QString TransFourierLow::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Low-pass ";

    if ( type == 'i' )
        ss << "ideal";
    else if ( type == 'g' )
        ss << "gaussian";
    else if ( type == 'b' )
        ss << "butterworth";

    ss << " filter";

    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }

    ss << ",cutoff=" << cutoff;

    if ( type == 'b' )
        ss << ",order=" << order;

    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransFourierLow* TransFourierLow::clone() const {
    return new TransFourierLow(*this);
}

QStringList TransFourierLow::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_FOURIERLOW_ID "\">";
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
    s5.append("<cutoff>");
    s5.append(QString::number(cutoff));
    s5.append("</cutoff>");
    s6.append("<order>");
    s6.append(QString::number(order));
    s6.append("</order>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << "</transform>";
    return list;
}

char TransFourierLow::getType() {
    return type;
}

int TransFourierLow::getCutoff() {
    return cutoff;
}

int TransFourierLow::getOrder() {
    return order;
}
