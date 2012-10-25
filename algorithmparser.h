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
    Transformation *parseBrightness(QDomElement);
};

#endif // ALGORITHMPARSER_H
