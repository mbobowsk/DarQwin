#include "algorithmparser.h"
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
#include "transfourierlow.h"
#include "transfourierhigh.h"
#include "transbandpass.h"
#include "transhsv.h"
#include "translogical.h"

algorithmParser::algorithmParser(const QDomDocument &document)
{
    doc = document;
}

int algorithmParser::parse(std::vector<Transformation*> &vector) {
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    //iteracja pierwszego stopnia - po kolejnych transformacjach
    while(!n.isNull()) {
        QDomElement e = n.toElement();
        //sygnalizacja błędu - nie ma elementu transformacji
        if(e.isNull()) {
            return 1;
        }

        QDomAttr attr = e.attributeNode("name");
        //sygnalizacja błędu - nie ma atrybutu dla nazwy
        if (attr.isNull())
            return 1;
        Transformation *trans = NULL;
        //na podstawie nazwy parsujemy co trzeba
        if ( attr.value() == TRANS_BRIGHTNESS_ID )
            trans = parseBrightness(e);
        else if ( attr.value() == TRANS_AVERAGE_ID )
            trans = parseAverage(e);
        else if ( attr.value() == TRANS_BILATERAL_ID )
            trans = parseBilateral(e);
        else if ( attr.value() == TRANS_CANNY_ID )
            trans = parseCanny(e);
        else if ( attr.value() == TRANS_CLOSE_ID )
            trans = parseClose(e);
        else if ( attr.value() == TRANS_CONVERSION_ID )
            trans = parseConversion(e);
        else if ( attr.value() == TRANS_CUSTOM_ID )
            trans = parseCustom(e);
        else if ( attr.value() == TRANS_DILATE_ID )
            trans = parseDilate(e);
        else if ( attr.value() == TRANS_EQUALIZE_ID )
            trans = parseEqualize(e);
        else if ( attr.value() == TRANS_ERODE_ID )
            trans = parseErode(e);
        else if ( attr.value() == TRANS_GAUSSIAN_ID )
            trans = parseGaussian(e);
        else if ( attr.value() == TRANS_GRADIENT_ID )
            trans = parseGradient(e);
        else if ( attr.value() == TRANS_LAPLACIAN_ID )
            trans = parseLaplacian(e);
        else if ( attr.value() == TRANS_MEDIAN_ID )
            trans = parseMedian(e);
        else if ( attr.value() == TRANS_OPEN_ID )
            trans = parseOpen(e);
        else if ( attr.value() == TRANS_RANK_ID )
            trans = parseRank(e);
        else if ( attr.value() == TRANS_SCHARR_ID )
            trans = parseScharr(e);
        else if ( attr.value() == TRANS_SOBEL_ID )
            trans = parseSobel(e);
        else if ( attr.value() == TRANS_THRESH_ID )
            trans = parseThresh(e);
        else if ( attr.value() == TRANS_FOURIERLOW_ID )
            trans = parseLowFourier(e);
        else if ( attr.value() == TRANS_FOURIERHIGH_ID )
            trans = parseHighFourier(e);
        else if ( attr.value() == TRANS_BANDPASS_ID )
            trans = parseBandPass(e);
        else if ( attr.value() == TRANS_HSV_ID )
            trans = parseHSV(e);
        else if ( attr.value() == TRANS_LOGICAL_ID )
            trans = parseLogical(e);

        //funkcja parsująca zwróciła NULL
        //albo nazwa się nie zgadza
        if ( trans == NULL )
            return 1;
        vector.push_back(trans);
        n = n.nextSibling();
    }
    return 0;
}

Transformation* algorithmParser::parseBrightness(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, value;
    char channel;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseChar(innerNode,channel) ||
         parseInt(innerNode,value) )
        return NULL;

    return new TransBrightness(top,left,bottom,right,value,channel);
}

int algorithmParser::parseInt(QDomNode &node, int &value) {
    QDomElement param = node.toElement();
    if (param.isNull())
        return 1;
    value = param.text().toInt();
    node = node.nextSibling();
    return 0;
}

int algorithmParser::parseChar(QDomNode &node, char &ch) {
    QDomElement param = node.toElement();
    if (param.isNull())
        return 1;
    ch = param.text().at(0).toAscii();
    node = node.nextSibling();
    return 0;
}

Transformation* algorithmParser::parseAverage(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, size;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,size) )
        return NULL;

    return new TransAverage(size,left,top,right,bottom);
}

Transformation* algorithmParser::parseBilateral(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, diameter, sigmaC, sigmaS;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,diameter) ||
         parseInt(innerNode,sigmaC) ||
         parseInt(innerNode,sigmaS) )
        return NULL;

    return new TransBilateral(diameter,sigmaC,sigmaS,left,top,right,bottom);
}

Transformation* algorithmParser::parseCanny(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int thresh;
    if ( parseInt(innerNode,thresh) )
        return NULL;

    return new TransCanny(thresh);
}

Transformation* algorithmParser::parseClose(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) )
        return NULL;

    return new TransClose(left,top,right,bottom);
}

Transformation* algorithmParser::parseConversion(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int type;
    if ( parseInt(innerNode,type) )
        return NULL;

    return new TransConversion(type);
}

Transformation* algorithmParser::parseCustom(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, div, size;
    std::vector<float> params;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,size) ||
         parseInt(innerNode,div) )
        return NULL;
    //parsowanie parametrów
    for (int i = 0; i != size; ++i) {
        int p;
        if ( parseInt(innerNode,p) )
            return NULL;
        params.push_back((float)p);
    }

    return new TransCustomFilter(left,top,right,bottom,params,div);
}

Transformation* algorithmParser::parseDilate(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) )
        return NULL;

    return new TransDilate(left,top,right,bottom);
}

Transformation* algorithmParser::parseEqualize(QDomElement) {
    return new TransEqualize();
}

Transformation* algorithmParser::parseErode(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) )
        return NULL;

    return new TransErode(left,top,right,bottom);
}

Transformation* algorithmParser::parseGaussian(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) )
        return NULL;

    return new TransGaussian(left,top,right,bottom);
}

Transformation* algorithmParser::parseGradient(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) )
        return NULL;

    return new TransGradient(left,top,right,bottom);
}

Transformation* algorithmParser::parseLaplacian(QDomElement) {
    return new TransLaplacian();
}

Transformation* algorithmParser::parseMedian(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, size;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,size) )
        return NULL;

    return new TransMedian(size,left,top,right,bottom);
}

Transformation* algorithmParser::parseOpen(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) )
        return NULL;

    return new TransOpen(left,top,right,bottom);
}

Transformation* algorithmParser::parseRank(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, size, rank;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,size) ||
         parseInt(innerNode,rank) )
        return NULL;

    return new TransRankFilter(left,top,right,bottom,size,rank);
}

Transformation* algorithmParser::parseScharr(QDomElement) {
    return new TransScharr();
}

Transformation* algorithmParser::parseSobel(QDomElement) {
    return new TransSobel();
}

Transformation* algorithmParser::parseThresh(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int thresh;
    if ( parseInt(innerNode,thresh) )
        return NULL;

    return new TransConversion(thresh);
}

Transformation* algorithmParser::parseLowFourier(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, cutoff, order;
    char type;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,cutoff) ||
         parseInt(innerNode,order) ||
         parseChar(innerNode,type) )
        return NULL;
    return new TransFourierLow(left,top,right,bottom,type,cutoff,order);
}

Transformation* algorithmParser::parseHighFourier(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, cutoff, order;
    char type;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,cutoff) ||
         parseInt(innerNode,order) ||
         parseChar(innerNode,type) )
        return NULL;
    return new TransFourierHigh(left,top,right,bottom,type,cutoff,order);
}

Transformation* algorithmParser::parseBandPass(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, inner, outer;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,inner) ||
         parseInt(innerNode,outer) )
        return NULL;
    return new TransBandPass(left,top,right,bottom,inner,outer);
}

Transformation* algorithmParser::parseHSV(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, hue, saturation;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,hue) ||
         parseInt(innerNode,saturation) )
        return NULL;
    return new TransHSV(left,top,right,bottom,hue,saturation);
}

Transformation* algorithmParser::parseLogical(QDomElement elem) {
    QDomNode innerNode = elem.firstChild();
    int left, top, right, bottom, mode;
    QString ifStr, thenStr, elseStr;
    if ( parseInt(innerNode,left) ||
         parseInt(innerNode,top) ||
         parseInt(innerNode,right) ||
         parseInt(innerNode,bottom) ||
         parseInt(innerNode,mode) )
        return NULL;

    QDomElement param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    ifStr = param.text();
    innerNode = innerNode.nextSibling();

    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    thenStr = param.text();
    innerNode = innerNode.nextSibling();

    param = innerNode.toElement();
    if (param.isNull())
        return NULL;
    elseStr = param.text();

    return new TransLogical(mode,ifStr,thenStr,elseStr,left,top,right,bottom);
}
