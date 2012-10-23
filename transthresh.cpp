#include "transthresh.h"
#include <QStringList>

TransThresh::TransThresh(int m, int v)
{
    init();
    mode = m;
    value = v;
}

QString TransThresh::toString() const {
    QString str;
    std::ostringstream ss;
    if ( mode == 0 )
        ss << "Binary ";
    else
        ss << "Binary Inverted ";
    ss << "Threshold";
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransThresh* TransThresh::clone() const {
    return new TransThresh(*this);
}

QStringList TransThresh::getXML() const {
    QStringList list;
    return list;
}
