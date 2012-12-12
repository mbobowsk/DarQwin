#include "transcustomfilter.h"
#include <QStringList>

TransCustomFilter::TransCustomFilter(const std::vector<float> &params, int divisor)
{
    div = divisor;
    for ( unsigned i = 0; i < params.size(); ++i )
        mask.push_back(params[i]);
    editable = true;
}

TransCustomFilter::TransCustomFilter(int l, int t, int r, int b, const std::vector<float> &params, int divisor) {
    left = l;
    top = t;
    right = r;
    bottom = b;
    div = divisor;
    for ( unsigned i = 0; i < params.size(); ++i )
        mask.push_back(params[i]);
    editable = true;
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

QStringList TransCustomFilter::getXML() const {
    QStringList list;
    list << "<transform name=\"" TRANS_CUSTOM_ID "\">";
    QString s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,s16,s17,
            s18,s19,s20,s21,s22,s23,s24,s25,s26,l,t,r,b;

    l.append("<left>");
    l.append(QString::number(mask.size()));
    l.append("</left>");
    t.append("<top>");
    t.append(QString::number(mask.size()));
    t.append("</top>");
    r.append("<right>");
    r.append(QString::number(mask.size()));
    r.append("</right>");
    b.append("<bottom>");
    b.append(QString::number(mask.size()));
    b.append("</bottom>");

    s1.append("<size>");
    s1.append(QString::number(mask.size()));
    s1.append("</size>");
    s0.append("<div>");
    s0.append(QString::number(div));
    s0.append("</div>");
    s2.append("<value>");
    s2.append(QString::number(mask[0]));
    s2.append("</value>");
    s3.append("<value>");
    s3.append(QString::number(mask[1]));
    s3.append("</value>");
    s4.append("<value>");
    s4.append(QString::number(mask[2]));
    s4.append("</value>");
    s5.append("<value>");
    s5.append(QString::number(mask[3]));
    s5.append("</value>");
    s6.append("<value>");
    s6.append(QString::number(mask[4]));
    s6.append("</value>");
    s7.append("<value>");
    s7.append(QString::number(mask[5]));
    s7.append("</value>");
    s8.append("<value>");
    s8.append(QString::number(mask[6]));
    s8.append("</value>");
    s9.append("<value>");
    s9.append(QString::number(mask[7]));
    s9.append("</value>");
    s10.append("<value>");
    s10.append(QString::number(mask[8]));
    s10.append("</value>");
    if ( mask.size() == 25 ) {
        s11.append("<value>");
        s11.append(QString::number(mask[9]));
        s11.append("</value>");
        s12.append("<value>");
        s12.append(QString::number(mask[10]));
        s12.append("</value>");
        s13.append("<value>");
        s13.append(QString::number(mask[11]));
        s13.append("</value>");
        s14.append("<value>");
        s14.append(QString::number(mask[12]));
        s14.append("</value>");
        s15.append("<value>");
        s15.append(QString::number(mask[13]));
        s15.append("</value>");
        s16.append("<value>");
        s16.append(QString::number(mask[14]));
        s16.append("</value>");
        s17.append("<value>");
        s17.append(QString::number(mask[15]));
        s17.append("</value>");
        s18.append("<value>");
        s18.append(QString::number(mask[16]));
        s18.append("</value>");
        s19.append("<value>");
        s19.append(QString::number(mask[17]));
        s19.append("</value>");
        s20.append("<value>");
        s20.append(QString::number(mask[18]));
        s20.append("</value>");
        s21.append("<value>");
        s21.append(QString::number(mask[19]));
        s21.append("</value>");
        s22.append("<value>");
        s22.append(QString::number(mask[20]));
        s22.append("</value>");
        s23.append("<value>");
        s23.append(QString::number(mask[21]));
        s23.append("</value>");
        s24.append("<value>");
        s24.append(QString::number(mask[22]));
        s24.append("</value>");
        s25.append("<value>");
        s25.append(QString::number(mask[23]));
        s25.append("</value>");
        s26.append("<value>");
        s26.append(QString::number(mask[24]));
        s26.append("</value>");
    }
    list << l << t << r << b << s1 << s0 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << s9 << s10
            << s11 << s12 << s13 << s14 << s15 << s16 << s17 << s18
            << s19 << s20 << s21 << s22 << s23 << s23 << s25 << s26
            << "</transform>";
    return list;
}

int TransCustomFilter::getDiv() {
    return div;
}

std::vector<float> TransCustomFilter::getMask() {
    return mask;
}
