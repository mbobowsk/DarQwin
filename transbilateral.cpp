#include "transbilateral.h"
#include <sstream>
#include <QStringList>

TransBilateral::TransBilateral(int d, int sc, int ss)
{
    diameter = d;
    sigmaColor = sc;
    sigmaSpace = ss;
    init();
}

TransBilateral::TransBilateral(int d, int sc, int ss, int l, int t, int r, int b) {
    diameter = d;
    sigmaColor = sc;
    sigmaSpace = ss;
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransBilateral::toString() const {
    QString ret;
    std::ostringstream ss;
    ss << "Bilateral Filter " << diameter << "x" << diameter << ","<< sigmaColor << "," << sigmaSpace;
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string str = ss.str();
    ret.append(str.c_str());
    return ret;
}

TransBilateral* TransBilateral::clone() const {
    return new TransBilateral(*this);
}

QStringList TransBilateral::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_BILATERAL_ID "\">";
    QString s1,s2,s3,s4,s5,s6,s7;
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
    s5.append("<diameter>");
    s5.append(QString::number(diameter));
    s5.append("</diameter>");
    s6.append("<sigmaColor>");
    s6.append(QString::number(sigmaColor));
    s6.append("</sigmaColor>");
    s7.append("<sigmaSpace>");
    s7.append(QString::number(sigmaSpace));
    s7.append("</sigmaSpace>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << s7 << "</transform>";
    return list;
}
