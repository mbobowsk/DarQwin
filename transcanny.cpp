#include "transcanny.h"
#include <QStringList>

TransCanny::TransCanny(int lt)
{
    init();
    lowThreshold = lt;
}

QString TransCanny::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Canny Edge Detection, Low Threshold = " << lowThreshold;
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransCanny* TransCanny::clone() const {
    return new TransCanny(*this);
}

QStringList TransCanny::getXML() const {
    QStringList list;
    list << "<transform name=\"canny\">";
    QString s1,s2,s3,s4,s5;
    s1.append("<left>");
    s1.append(QString::number(left));
    s1.append("</left>");
    s2.append("<top>");
    s2.append(QString::number(top));
    s2.append("</top>");
    s3.append("<right>");
    s3.append(QString::number(right));
    s3.append("</right>");
    s4.append("<bottom>");
    s4.append(QString::number(bottom));
    s4.append("</bottom>");
    s5.append("<thresh>");
    s5.append(QString::number(lowThreshold));
    s5.append("</thresh>");
    list << s1 << s2 << s3 << s4 << s5 << "</transform>";
    return list;
}
