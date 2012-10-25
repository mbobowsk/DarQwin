#ifndef TRANSRANKFILTER_H
#define TRANSRANKFILTER_H

#include "transformation.h"
#define TRANS_RANK_ID "rank"

class TransRankFilter : public Transformation
{
public:
    TransRankFilter(int s, int r);
    TransRankFilter(int left, int top, int right, int bottom, int s, int r);
    QString toString() const;
    TransRankFilter* clone() const;
    QStringList getXML() const;
private:
    int size;
    int rank;
};

#endif // TRANSRANKFILTER_H
