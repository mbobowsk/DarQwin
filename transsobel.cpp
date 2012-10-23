#include "transsobel.h"
#include <QStringList>

TransSobel::TransSobel()
{
    init();
}

QString TransSobel::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Sobel Derivative";
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransSobel* TransSobel::clone() const {
    return new TransSobel(*this);
}

QStringList TransSobel::getXML() const {
    QStringList list;
    return list;
}
