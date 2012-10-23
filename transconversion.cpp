#include "transconversion.h"
#include <QStringList>

TransConversion::TransConversion(int t)
{
    init();
    type = t;
}

QString TransConversion::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Conversion to ";
    if ( type == 0 )
        ss << "Grayscale";
    else
        ss << "RGB";
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransConversion* TransConversion::clone() const {
    return new TransConversion(*this);
}

QStringList TransConversion::getXML() const {
    QStringList list;
    return list;
}
