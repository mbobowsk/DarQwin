#include "transcustomfilter.h"
#include <QStringList>

TransCustomFilter::TransCustomFilter(const std::vector<float> &params)
{
    init();
    for ( unsigned i = 0; i < params.size(); ++i )
        mask.push_back(params[i]);
}

TransCustomFilter::TransCustomFilter(int l, int t, int r, int b, const std::vector<float> &params) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    for ( unsigned i = 0; i < params.size(); ++i )
        mask.push_back(params[i]);
}

QString TransCustomFilter::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Custom Filter";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransCustomFilter* TransCustomFilter::clone() const {
    return new TransCustomFilter(*this);
}

QStringList TransCustomFilter::getXML() const {
    QStringList list;
    list << "<transform name=\"custom\">";
    QString s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
    s1.append("<size>");
    s1.append(QString::number(mask.size()));
    s1.append("</size>");
    s2.append("<value>");
    s2.append(QString::number(mask[0]));
    s2.append("</value>");
    s3.append("<value>");
    s3.append(QString::number(mask[1]));
    s3.append("</value>");
    s4.append("<value>");
    s4.append(QString::number(mask[2]));
    s4.append("</value>");
    s5.append("<value>");
    s5.append(QString::number(mask[3]));
    s5.append("</value>");
    s6.append("<value>");
    s6.append(QString::number(mask[4]));
    s6.append("</value>");
    s7.append("<value>");
    s7.append(QString::number(mask[5]));
    s7.append("</value>");
    s8.append("<value>");
    s8.append(QString::number(mask[6]));
    s8.append("</value>");
    s9.append("<value>");
    s9.append(QString::number(mask[7]));
    s9.append("</value>");
    s10.append("<value>");
    s10.append(QString::number(mask[8]));
    s10.append("</value>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << s9 << s10 << "</transform>";
    return list;
}
