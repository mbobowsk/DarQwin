#include "transbilateral.h"
#include <sstream>

TransBilateral::TransBilateral(int d, int sc, int ss)
{
    diameter = d;
    sigmaColor = sc;
    sigmaSpace = ss;
}

QString TransBilateral::toString() {
    QString ret;
    std::ostringstream ss;
    ss << "Bilateral Filter " << diameter << "x" << diameter << ","<< sigmaColor << "," << sigmaSpace;
    std::string str = ss.str();
    ret.append(str.c_str());
    return ret;
}

TransBilateral* TransBilateral::clone() const {
    return new TransBilateral(*this);
}
