#include "astnode.h"
#include <QDebug>

ASTNode::ASTNode(QString v) {
    value = v;
}

QString ASTNode::getValue() {
    return value;
}

bool ASTNode::satisfied() const {
    return false;
}

ASTNode* ASTNode::clone() {
    return new ASTNode(*this);
}

void ASTNode::map(const cv::Mat &window) {
    // Jeżeli węzeł jest liczbą to nie ma co ukonkretniać
    if ( value[0].isDigit() )
        return;
    // Mapowanie w grayscale
    if ( value.size() == 1 ) {
        /*if ( value == "A" )
            value = QString::number(window.at<uchar>(0,0));
        else if ( value == "B")
            value = QString::number(window.at<uchar>(0,1));
        else if ( value == "C")
            value = QString::number(window.at<uchar>(0,2));
        else if ( value == "D")
            value = QString::number(window.at<uchar>(1,0));
        else if ( value == "E")
            value = QString::number(window.at<uchar>(1,1));
        else if ( value == "F")
            value = QString::number(window.at<uchar>(1,2));
        else if ( value == "G")
            value = QString::number(window.at<uchar>(2,0));
        else if ( value == "H")
            value = QString::number(window.at<uchar>(2,1));
        else if ( value == "I")
            value = QString::number(window.at<uchar>(2,2));
        else
            value = QString('0');*/
        value = QString::number(mapGray(window,value));
    }
    // Mapowanie rgb
    else {

    }
}

int ASTNode::mapGray(const cv::Mat &window, QString str) {
    if ( str == "A" )
        return window.at<uchar>(0,0);
    else if ( str == "B")
        return window.at<uchar>(0,1);
    else if ( str == "C")
         return window.at<uchar>(0,2);
    else if ( str == "D")
        return window.at<uchar>(1,0);
    else if ( str == "E")
        return window.at<uchar>(1,1);
    else if ( str == "F")
        return window.at<uchar>(1,2);
    else if ( str == "G")
        return window.at<uchar>(2,0);
    else if ( str == "H")
        return window.at<uchar>(2,1);
    else if ( str == "I")
        return window.at<uchar>(2,2);

    else
        return 0;
}
