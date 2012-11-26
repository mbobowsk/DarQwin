#include "astexpression.h"

ASTExpression::ASTExpression(QString v, ASTCondition *left, ASTCondition *right) : ASTCondition(v,left,right)
{
}

ASTExpression::~ASTExpression() {
    delete leftChild;
    delete rightChild;
}

bool ASTExpression::satisfied() const {
    if ( value == "&&" )
        return leftChild->satisfied() && rightChild->satisfied();
    else if ( value == "||" )
        return leftChild->satisfied() || rightChild->satisfied();

    // Nie powinno mieć miejsca
    return false;
}
