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
    /// Funkcje parsujące warunek
    ASTCondition *parseGray(QString str);
    ASTCondition *parseRGB(QString str);
    /// Funkcja parsująca then i else
    bool parseResult(QString str, bool rgb);
};

#endif // LOGICALFILTERPARSER_H
