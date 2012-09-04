#include "transbrightness.h"
#include <sstream>
#include <string>


TransBrightness::TransBrightness(int v, char ch)
{
    value = v;
    channel = ch;
}

QString TransBrightness::toString() {
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
            ret.append("red");
        else if ( channel == 'g' )
            ret.append("green");
        else
            ret.append("blue");
    }
    return ret;
}
