#include "astexpression.h"

ASTExpression::ASTExpression(QString v, ASTNode *left, ASTNode *right) : ASTCondition(v,left,right)
{
}

ASTExpression::~ASTExpression() {
    delete leftChild;
    delete rightChild;
}

ASTNode* ASTExpression::clone() {
    return new ASTExpression(value,leftChild->clone(),rightChild->clone());
}

bool ASTExpression::satisfied() const {
    if ( value == "&&" )
        return leftChild->satisfied() && rightChild->satisfied();
    else if ( value == "||" )
        return leftChild->satisfied() || rightChild->satisfied();

    // Nie powinno mieć miejsca
    return false;
}
