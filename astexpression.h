#ifndef ASTEXPRESSION_H
#define ASTEXPRESSION_H

#include "astcondition.h"

/// Klasa prezentująca złożony warunek np. A>B && B<C
/// Wartością węzła jest operator && albo ||

class ASTExpression : public ASTCondition
{
public:
    ASTExpression(QString v, ASTCondition *left, ASTCondition *right);
    ~ASTExpression();
    bool satisfied() const;
};

#endif // ASTEXPRESSION_H
