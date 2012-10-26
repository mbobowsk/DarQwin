#include "transscharr.h"
#include <QStringList>

TransScharr::TransScharr()
{
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
    list << "<transform name=\"" TRANS_SCHARR_ID "\">";
    list << "</transform>";
    return list;
}
