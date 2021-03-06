#include "transequalize.h"
#include <QStringList>

TransEqualize::TransEqualize()
{
}


QString TransEqualize::toString() const {
    QString str;
    str.append("Histogram Equalization");
    return str;
}

TransEqualize* TransEqualize::clone() const {
    return new TransEqualize(*this);
}

QStringList TransEqualize::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_EQUALIZE_ID "\">";
    list << "</transform>";
    return list;
}
