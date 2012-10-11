#ifndef TRANSCUSTOMFILTER_H
#define TRANSCUSTOMFILTER_H

#include "transformation.h"
#include <vector>

class TransCustomFilter : public Transformation
{
public:
    TransCustomFilter(const std::vector<int> &params);
    TransCustomFilter(int left, int top, int right, int bottom, const std::vector<int> &params);
    QString toString() const;
    virtual TransCustomFilter* clone() const;
private:
    std::vector<int> mask;
};

#endif // TRANSCUSTOMFILTER_H
