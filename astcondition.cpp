#include "astcondition.h"

ASTCondition::ASTCondition(QString v, ASTNode *left, ASTNode *right) : ASTNode(v)
{
    leftChild = left;
    rightChild = right;
}

ASTCondition::~ASTCondition() {
    delete leftChild;
    delete rightChild;
}

bool ASTCondition::satisfied() {
    if ( value == ">")
        return leftChild->getValue() > rightChild->getValue();
    else if ( value == "<")
        return leftChild->getValue() < rightChild->getValue();
    else if ( value == "==")
        return leftChild->getValue() == rightChild->getValue();
    else if ( value == ">=")
        return leftChild->getValue() >= rightChild->getValue();
    else if ( value == "<=")
        return leftChild->getValue() <= rightChild->getValue();

    // Nie powinno mieć miejsca
    return false;
}

ASTNode* ASTCondition::getLeft() {
    return leftChild;
}

ASTNode* ASTCondition::getRight() {
    return rightChild;
}
