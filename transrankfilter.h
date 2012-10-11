#ifndef TRANSRANKFILTER_H
#define TRANSRANKFILTER_H

#include "transformation.h"

class TransRankFilter : public Transformation
{
public:
    TransRankFilter(int s, int r);
    TransRankFilter(int left, int top, int right, int bottom, int s, int r);
    QString toString() const;
    TransRankFilter* clone() const;
private:
    int size;
    int rank;
};

#endif // TRANSRANKFILTER_H
