#ifndef ALGORITHMPARSER_H
#define ALGORITHMPARSER_H
#include <QDomDocument>
#include "transformation.h"
#include <vector>
class algorithmParser
{
public:
    algorithmParser(const QDomDocument&);
    //zwraca 0 przy poprawnym parsowaniu
    int parse(std::vector<Transformation*> &vector);
private:
    QDomDocument doc;
    //funkcje parsujące transformacje
    Transformation *parseBrightness(QDomElement);
    Transformation *parseAverage(QDomElement);
    Transformation *parseBilateral(QDomElement);
    Transformation *parseCanny(QDomElement);
    Transformation *parseClose(QDomElement);
    Transformation *parseConversion(QDomElement);
    Transformation *parseCustom(QDomElement);
    Transformation *parseDilate(QDomElement);
    Transformation *parseEqualize(QDomElement);
    Transformation *parseErode(QDomElement);
    Transformation *parseGaussian(QDomElement);
    Transformation *parseGradient(QDomElement);
    Transformation *parseLaplacian(QDomElement);
    Transformation *parseMedian(QDomElement);
    Transformation *parseOpen(QDomElement);
    Transformation *parseRank(QDomElement);
    Transformation *parseScharr(QDomElement);
    Transformation *parseSobel(QDomElement);
    Transformation *parseThresh(QDomElement);
    Transformation *parseLowFourier(QDomElement);
    Transformation *parseHighFourier(QDomElement);
    Transformation *parseBandPass(QDomElement);
    Transformation *parseHSV(QDomElement);
    Transformation *parseLogical(QDomElement);

    //funkcje parsujące pojedyncze wartości
    int parseInt(QDomNode &node, int &value);
    int parseChar(QDomNode &node, char &ch);
    QString parseString(QDomNode &node);
};

#endif // ALGORITHMPARSER_H
