#include "transcanny.h"

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
