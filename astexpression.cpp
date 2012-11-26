#include "astexpression.h"

ASTExpression::ASTExpression(QString v, ASTCondition *left, ASTCondition *right) : ASTCondition(v,left,right)
{
}

bool ASTExpression::satisfied() const {
    if ( value == "&&" )
        return leftChild->satisfied() && rightChild->satisfied();
    else if ( value == "||" )
        return leftChild->satisfied() || rightChild->satisfied();

    // Nie powinno mieć miejsca
    return false;
}
