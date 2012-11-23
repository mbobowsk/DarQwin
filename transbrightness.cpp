#include "transbrightness.h"
#include <sstream>
#include <string>
#include <QStringList>


TransBrightness::TransBrightness(int v, char ch)
{
    value = v;
    channel = ch;
}

TransBrightness::TransBrightness(int t, int l, int b, int r, int v, char ch) {
    top = t;
    left = l;
    bottom = b;
    right = r;
    value = v;
    channel = ch;
}

QString TransBrightness::toString() const {    
    QString ret;
    ret.append("Brightness ");
    if ( value > 0 )
        ret.append("+");

    std::ostringstream ss;
    ss << value << " ";

    if ( channel != 'a' ) {
        if ( channel == 'r' )
            ss << "in red channel";
        else if ( channel == 'g' )
            ss << "in green channel";
        else
            ss << "in blue channel";
    }

    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }

    std::string str = ss.str();
    ret.append(str.c_str());
    return ret;
}

TransBrightness* TransBrightness::clone() const {
    return new TransBrightness(*this);
}

QStringList TransBrightness::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_BRIGHTNESS_ID "\">";
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
    s5.append("<channel>");
    s5.append(channel);
    s5.append("</channel>");
    s6.append("<value>");
    s6.append(QString::number(value));
    s6.append("</value>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << "</transform>";
    return list;
}

int TransBrightness::getValue() {
    return value;
}

char TransBrightness::getChannel() {
    return channel;
}
