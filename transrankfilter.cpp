#include "transrankfilter.h"
#include <QStringList>

TransRankFilter::TransRankFilter(int s, int r)
{
    init();
    size = s;
    rank = r;
}

TransRankFilter::TransRankFilter(int l, int t, int r, int b, int s, int rnk) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    size = s;
    rank = rnk;
}

QString TransRankFilter::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Rank Filter ";
    if (size == 3)
        ss << "3x3";
    else
        ss << "5x5";
    ss << " (" << rank << ")";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransRankFilter* TransRankFilter::clone() const {
    return new TransRankFilter(*this);
}

QStringList TransRankFilter::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_RANK_ID "\">";
    QString s1,s2,s3,s4,s5,s6;
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
    s5.append("<size>");
    s5.append(QString::number(size));
    s5.append("</size>");
    s6.append("<rank>");
    s6.append(QString::number(rank));
    s6.append("</rank>");
    list << s1 << s2 << s3 << s4 << s5 << s6 << "</transform>";
    return list;
}
