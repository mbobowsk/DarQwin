#ifndef TRANSCUSTOMFILTER_H
#define TRANSCUSTOMFILTER_H

#include "transformation.h"
#include <vector>

class TransCustomFilter : public Transformation
{
public:
    TransCustomFilter(const std::vector<float> &params);
    TransCustomFilter(int left, int top, int right, int bottom, const std::vector<float> &params);
    QString toString() const;
    virtual TransCustomFilter* clone() const;
    QStringList getXML() const;
private:
    std::vector<float> mask;
};

#endif // TRANSCUSTOMFILTER_H
