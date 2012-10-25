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
    list << "<transform name=\"" TRANS_THRESH_ID "\">";
    QString s1,s2;
    s1.append("<mode>");
    s1.append(QString::number(mode));
    s1.append("</mode>");
    s2.append("<value>");
    s2.append(QString::number(value));
    s2.append("</value>");
    list << "</transform>";
    return list;
}
