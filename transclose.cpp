#include "transclose.h"

TransClose::TransClose()
{
    init();
}

TransClose::TransClose(int l, int t, int r, int b) {
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransClose::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Closing";
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransClose* TransClose::clone() const {
    return new TransClose(*this);
}
