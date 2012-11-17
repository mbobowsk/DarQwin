#include "transbandpass.h"
#include <QStringList>

TransBandPass::TransBandPass(int in, int out)
{
    innerRadius = in;
    outerRadius = out;
}

TransBandPass::TransBandPass(int l, int t, int r, int b, int in, int out) {
    innerRadius = in;
    outerRadius = out;
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransBandPass::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Band-pass filter";

    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }

    ss << ",inner=" << innerRadius;
    ss << ",outer=" << outerRadius;

    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransBandPass* TransBandPass::clone() const {
    return new TransBandPass(*this);
}

QStringList TransBandPass::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_BANDPASS_ID "\">";
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
    s5.append("<inner>");
    s5.append(QString::number(innerRadius));
    s5.append("</inner>");
    s6.append("<outer>");
    s6.append(QString::number(outerRadius));
    s6.append("</outer>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << "</transform>";
    return list;
}

int TransBandPass::getInner() {
    return innerRadius;
}

int TransBandPass::getOuter() {
    return outerRadius;
}
