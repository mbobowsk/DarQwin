#ifndef LOGICALFILTERPARSER_H
#define LOGICALFILTERPARSER_H

#include "astexpression.h"

/// Klasa budująca drzewo rozbioru dla filtrów logicznych
class LogicalFilterParser
{
public:
    /// Singleton
    static LogicalFilterParser& getInstance() {
        static LogicalFilterParser instance;
        return instance;
    }
    LogicalFilterParser();
    ASTNode *parseGray(QString str);
    ASTNode *parseRGB(QString str);
};

#endif // LOGICALFILTERPARSER_H
