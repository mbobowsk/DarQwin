#include "transrankfilter.h"

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
