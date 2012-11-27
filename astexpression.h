#ifndef ASTEXPRESSION_H
#define ASTEXPRESSION_H

#include "astcondition.h"

/// Klasa prezentująca złożony warunek np. A>B && B<C
/// Wartością węzła jest operator && albo ||

class ASTExpression : public ASTCondition
{
public:
    ASTExpression(QString v, ASTNode *left, ASTNode *right);
    ~ASTExpression();
    virtual bool satisfied() const;
    ASTNode* clone();
};

#endif // ASTEXPRESSION_H
