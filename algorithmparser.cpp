#include "algorithmparser.h"
#include <iostream>
#include "transbrightness.h"
#include "transaverage.h"
#include "transmedian.h"
#include "transgaussian.h"
#include "transbilateral.h"
#include "transdilate.h"
#include "transerode.h"
#include "transopen.h"
#include "transclose.h"
#include "transgradient.h"
#include "transthresh.h"
#include "transsobel.h"
#include "translaplacian.h"
#include "transcanny.h"
#include "transscharr.h"
#include "transconversion.h"
#include "transequalize.h"
#include "transcustomfilter.h"
#include "transrankfilter.h"

algorithmParser::algorithmParser(const QDomDocument &document)
{
    doc = document;
}

int algorithmParser::parse(std::vector<Transformation*> &vector) {
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    //iteracjach pierwszego stopnia - po kolejnych transformacjach
    while(!n.isNull()) {
        QDomElement e = n.toElement();
        //sygnalizacja błędu - nie ma elementu transformacji
        if(e.isNull()) {
            return 1;
        }
        std::cout << qPrintable(e.tagName()) << std::endl;

        QDomAttr attr = e.attributeNode("name");
        //sygnalizacja błędu - nie ma atrybutu dla nazwy
        if (attr.isNull())
            return 1;
        std::cout << qPrintable(attr.value()) << std::endl;
        if ( attr.value() == TRANS_BRIGHTNESS_ID )
            parseBrightness(e);


        /*QDomNode innerNode = e.firstChild();
        while (!innerNode.isNull()) {
            QDomElement param = innerNode.toElement();
            //sygnalizacja błędu
            if (param.isNull())
                return 1;
            std::cout << qPrintable(param.tagName()) << std::endl;
            innerNode = innerNode.nextSibling();
        }*/

        n = n.nextSibling();
    }
    return 0;
}

Transformation* algorithmParser::parseBrightness(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    //<left>0</left>
    QDomElement param = innerNode.toElement();
    //sygnalizacja błędu
    if (param.isNull())
        return NULL;
    int left = param.text().toInt();

    //<top>0</top>
    innerNode = innerNode.nextSibling();
    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    int top = param.text().toInt();

    //<right>0</right>
    innerNode = innerNode.nextSibling();
    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    int right = param.text().toInt();

    //<bottom>0</bottom>
    innerNode = innerNode.nextSibling();
    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    int bottom = param.text().toInt();

    //<channel>a</channel>
    innerNode = innerNode.nextSibling();
    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    char channel = param.text().at(0).toAscii();

    //<value>143</value>
    innerNode = innerNode.nextSibling();
    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    int value = param.text().toInt();

    return new TransBrightness(top,left,bottom,right,value,channel);

}
