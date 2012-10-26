#include "transconversion.h"
#include <QStringList>

TransConversion::TransConversion(int t)
{
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
    list << "<transform name=\"" TRANS_CONVERSION_ID "\">";
    QString s1;
    s1.append("<type>");
    s1.append(QString::number(type));
    s1.append("</type>");
    list << s1 << "</transform>";
    return list;
}

int TransConversion::getType() {
    return type;
}
