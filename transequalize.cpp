#include "transequalize.h"
#include <QStringList>

TransEqualize::TransEqualize()
{
    init();
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
    return list;
}
