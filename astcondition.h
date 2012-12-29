#ifndef ASTCONDITION_H
#define ASTCONDITION_H

#include "astnode.h"

/// Klasa warunku w drzewie rozbioru np A > B
/// Wartością węzła jest operator, a dzieci reprezentują operandy

class ASTCondition : public ASTNode
{
public:
    ASTCondition(QString v, ASTNode *left, ASTNode* right);
    virtual ~ASTCondition();

    ASTNode *getLeft();
    ASTNode *getRight();

    virtual bool satisfied() const;
    virtual void map(const cv::Mat &window);
    virtual ASTNode* clone();

protected:
    ASTNode *leftChild;
    ASTNode *rightChild;

};

#endif // ASTCONDITION_H
