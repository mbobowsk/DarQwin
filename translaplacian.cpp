#include "translaplacian.h"

TransLaplacian::TransLaplacian()
{
    init();
}

QString TransLaplacian::toString() const {
    QString str;
    std::ostringstream ss;
    ss << "Laplace Operator";
    std::string s = ss.str();
    str.append(s.c_str());
    return str;
}

TransLaplacian* TransLaplacian::clone() const {
    return new TransLaplacian(*this);
}
