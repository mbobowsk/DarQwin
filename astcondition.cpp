#include "astcondition.h"

ASTCondition::ASTCondition(QString v, ASTNode *left, ASTNode *right) : ASTNode(v)
{
    leftChild = left;
    rightChild = right;
}

ASTCondition::~ASTCondition() {
    delete leftChild;
    leftChild = NULL;
    delete rightChild;
    rightChild = NULL;
}

ASTNode* ASTCondition::clone() {
    return new ASTCondition(value,leftChild->clone(),rightChild->clone());
}

bool ASTCondition::satisfied() const {
    if ( value == ">")
        return leftChild->getValue().toInt() > rightChild->getValue().toInt();
    else if ( value == "<")
        return leftChild->getValue().toInt() < rightChild->getValue().toInt();
    else if ( value == "==")
        return leftChild->getValue().toInt() == rightChild->getValue().toInt();
    else if ( value == ">=")
        return leftChild->getValue().toInt() >= rightChild->getValue().toInt();
    else if ( value == "<=")
        return leftChild->getValue().toInt() <= rightChild->getValue().toInt();
    else if ( value == "!=")
        return leftChild->getValue().toInt() != rightChild->getValue().toInt();

    // Nie powinno mieć miejsca
    return false;
}

ASTNode* ASTCondition::getLeft() {
    return leftChild;
}

ASTNode* ASTCondition::getRight() {
    return rightChild;
}

void ASTCondition::map(const cv::Mat &window) {
    leftChild->map(window);
    rightChild->map(window);
}
