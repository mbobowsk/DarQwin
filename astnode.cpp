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
        value = QString::number(mapGray(window,value));
    }
    // Mapowanie rgb
    else {
        value = QString::number(mapRGB(window,value));
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

int ASTNode::mapRGB(const cv::Mat &window, QString str) {
    if ( str[1] == 'r') {
        if ( str[0] == 'A' )
            return window.at<cv::Vec3b>(0,0)[0];
        else if ( str[0] == 'B' )
            return window.at<cv::Vec3b>(0,1)[0];
        else if ( str[0] == 'C' )
            return window.at<cv::Vec3b>(0,2)[0];
        else if ( str[0] == 'D' )
            return window.at<cv::Vec3b>(1,0)[0];
        else if ( str[0] == 'E' )
            return window.at<cv::Vec3b>(1,1)[0];
        else if ( str[0] == 'F' )
            return window.at<cv::Vec3b>(1,2)[0];
        else if ( str[0] == 'G' )
            return window.at<cv::Vec3b>(2,0)[0];
        else if ( str[0] == 'H' )
            return window.at<cv::Vec3b>(2,1)[0];
        else if ( str[0] == 'I' )
            return window.at<cv::Vec3b>(2,2)[0];
    }
    else if ( str[1] == 'g') {
        if ( str[0] == 'A' )
            return window.at<cv::Vec3b>(0,0)[1];
        else if ( str[0] == 'B' )
            return window.at<cv::Vec3b>(0,1)[1];
        else if ( str[0] == 'C' )
            return window.at<cv::Vec3b>(0,2)[1];
        else if ( str[0] == 'D' )
            return window.at<cv::Vec3b>(1,0)[1];
        else if ( str[0] == 'E' )
            return window.at<cv::Vec3b>(1,1)[1];
        else if ( str[0] == 'F' )
            return window.at<cv::Vec3b>(1,2)[1];
        else if ( str[0] == 'G' )
            return window.at<cv::Vec3b>(2,0)[1];
        else if ( str[0] == 'H' )
            return window.at<cv::Vec3b>(2,1)[1];
        else if ( str[0] == 'I' )
            return window.at<cv::Vec3b>(2,2)[1];
    }
    else if ( str[1] == 'b') {
        if ( str[0] == 'A' )
            return window.at<cv::Vec3b>(0,0)[2];
        else if ( str[0] == 'B' )
            return window.at<cv::Vec3b>(0,1)[2];
        else if ( str[0] == 'C' )
            return window.at<cv::Vec3b>(0,2)[2];
        else if ( str[0] == 'D' )
            return window.at<cv::Vec3b>(1,0)[2];
        else if ( str[0] == 'E' )
            return window.at<cv::Vec3b>(1,1)[2];
        else if ( str[0] == 'F' )
            return window.at<cv::Vec3b>(1,2)[2];
        else if ( str[0] == 'G' )
            return window.at<cv::Vec3b>(2,0)[2];
        else if ( str[0] == 'H' )
            return window.at<cv::Vec3b>(2,1)[2];
        else if ( str[0] == 'I' )
            return window.at<cv::Vec3b>(2,2)[2];
    }

    // Coś dziwnego
    else
        return -1;
}
