#include "transformation.h"

Transformation::Transformation() {
    left = 0;
    right = 0;
    top = 0;
    bottom = 0;
    editable = false;
}

int Transformation::getLeft() {
    return left;
}

int Transformation::getRight() {
    return right;
}

int Transformation::getTop() {
    return top;
}

int Transformation::getBottom() {
    return bottom;
}

bool Transformation::isEditable() {
    return editable;
}

QRect Transformation::getRect() {
    return QRect(QPoint(left,top),QPoint(right,bottom));
}
