#include "transbrightness.h"
#include <sstream>
#include <string>
#include <QStringList>


TransBrightness::TransBrightness(int v, char ch)
{
    value = v;
    channel = ch;
    init();
}

QString TransBrightness::toString() const {
    QString ret;
    ret.append("Brightness ");
    if ( value > 0 )
        ret.append("+");

    std::ostringstream ss;
    ss << value << " ";
    std::string str = ss.str();

    ret.append(str.c_str());
    if ( channel != 'a' ) {
        if ( channel == 'r' )
            ret.append("in red channel");
        else if ( channel == 'g' )
            ret.append("in green channel");
        else
            ret.append("in blue channel");
    }
    return ret;
}

TransBrightness* TransBrightness::clone() const {
    return new TransBrightness(*this);
}

QStringList TransBrightness::getXML() const {
    QStringList list;
    return list;
}
