#ifndef ASTNODE_H
#define ASTNODE_H

#include <QString>

/// Klasa ASTNode jest podstawowym budulcem drzewa rozbioru

class ASTNode
{
public:
    ASTNode(QString v);
    QString getValue();
    // Funkcja określa czy warunek jest spełniony
    // Nie ma sensu dla pojedynczego tokena np. A, ale umieszczenie jej tutaj
    // znacznie upraszcza operacje na drzewie
    virtual bool satisfied();

protected:
    // Zmienna przechowująca opis węzła (zazwyczaj jednoliterowy, ale może być też np. Er)
    QString value;
};

#endif // ASTNODE_H
