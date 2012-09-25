#include "transopen.h"

TransOpen::TransOpen()
{
    init();
}

TransOpen::TransOpen(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransOpen::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Opening";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransOpen* TransOpen::clone() const {
    return new TransOpen(*this);
}
