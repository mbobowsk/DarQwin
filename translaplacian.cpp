#include "translaplacian.h"
#include <QStringList>

TransLaplacian::TransLaplacian()
{
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

QStringList TransLaplacian::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_LAPLACIAN_ID "\">";
    list << "</transform>";
    return list;
}
