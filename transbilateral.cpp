#include "transbilateral.h"
#include <sstream>

TransBilateral::TransBilateral(int d, int sc, int ss)
{
    diameter = d;
    sigmaColor = sc;
    sigmaSpace = ss;
    init();
}

TransBilateral::TransBilateral(int d, int sc, int ss, int l, int t, int r, int b) {
    diameter = d;
    sigmaColor = sc;
    sigmaSpace = ss;
    left = l;
    top = t;
    right = r;
    bottom = b;
}

QString TransBilateral::toString() const {
    QString ret;
    std::ostringstream ss;
    ss << "Bilateral Filter " << diameter << "x" << diameter << ","<< sigmaColor << "," << sigmaSpace;
    if ( left != 0 && right != 0 ) {
        ss << ",(" << left << "," << top << "," << right << "," << bottom << ")";
    }
    std::string str = ss.str();
    ret.append(str.c_str());
    return ret;
}

TransBilateral* TransBilateral::clone() const {
    return new TransBilateral(*this);
}
