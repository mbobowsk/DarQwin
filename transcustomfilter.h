#ifndef TRANSCUSTOMFILTER_H
#define TRANSCUSTOMFILTER_H

#include "transformation.h"
#include <vector>
#define TRANS_CUSTOM_ID "custom"

class TransCustomFilter : public Transformation
{
public:
    TransCustomFilter(const std::vector<float> &params, int div);
    TransCustomFilter(int left, int top, int right, int bottom, const std::vector<float> &params, int div);
    QString toString() const;
    virtual TransCustomFilter* clone() const;
    QStringList getXML() const;
private:
    std::vector<float> mask;
    int div;
};

#endif // TRANSCUSTOMFILTER_H
