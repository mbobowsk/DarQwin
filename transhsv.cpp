#include "transhsv.h"
#include <sstream>
#include <string>
#include <QStringList>


TransHSV::TransHSV(int h, int sat)
{
    hue = h;
    saturation = sat;
    editable = true;
}

TransHSV::TransHSV(int t, int l, int b, int r, int h, int sat) {
    top = t;
    left = l;
    bottom = b;
    right = r;
    hue = h;
    saturation = sat;
    editable = true;
}

QString TransHSV::toString() const {
    QString str;
    std::ostringstream ss;
    if ( hue > 0 ) {
        ss << "Hue +" << hue << ", ";
    }
    if ( hue < 0 ) {
        ss << "Hue " << hue << ", ";
    }

    if ( saturation > 0 ) {
        ss << "Saturation +" << saturation;
    }
    if ( saturation < 0 ) {
        ss << "Saturation " << saturation;
    }

    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransHSV* TransHSV::clone() const {
    return new TransHSV(*this);
}

QStringList TransHSV::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_HSV_ID "\">";
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
    s5.append("<hue>");
    s5.append(QString::number(hue));
    s5.append("</hue>");
    s6.append("<saturation>");
    s6.append(QString::number(saturation));
    s6.append("</saturation>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << "</transform>";
    return list;
}

int TransHSV::getHue() {
    return hue;
}

int TransHSV::getSaturation() {
    return saturation;
}
