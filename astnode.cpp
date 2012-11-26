#include "astnode.h"

ASTNode::ASTNode(QString v) {
    value = v;
}

QString ASTNode::getValue() {
    return value;
}

bool ASTNode::satisfied() {
    return false;
}
