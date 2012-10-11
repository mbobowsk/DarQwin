#include "transcustomfilter.h"

TransCustomFilter::TransCustomFilter(const std::vector<int> &params)
{
    init();
    for ( int i = 0; i < params.size(); ++i )
        mask.push_back(params[i]);
}

TransCustomFilter::TransCustomFilter(int l, int t, int r, int b, const std::vector<int> &params) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    for ( int i = 0; i < params.size(); ++i )
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
