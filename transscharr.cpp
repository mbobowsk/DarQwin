#include "transscharr.h"
#include <QStringList>

TransScharr::TransScharr()
{
    init();
}

QString TransScharr::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Scharr Derivative";
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransScharr* TransScharr::clone() const {
    return new TransScharr(*this);
}

QStringList TransScharr::getXML() const {
    QStringList list;
    list << "<transform name=\"scharr\">";
    list << "</transform>";
    return list;
}
