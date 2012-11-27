#ifndef ASTNODE_H
#define ASTNODE_H

#include <QString>
#include <cv.h>
/// Klasa ASTNode jest podstawowym budulcem drzewa rozbioru

class ASTNode
{
public:
    ASTNode(QString v);
    QString getValue();
    // Funkcja określa czy warunek jest spełniony
    // Nie ma sensu dla pojedynczego tokena np. A, ale umieszczenie jej tutaj
    // znacznie upraszcza operacje na drzewie
    virtual bool satisfied() const;
    // Funkcja ukonkretniająca
    virtual void map(const cv::Mat &window);

    virtual ASTNode* clone();

    static int mapGray(const cv::Mat &window, QString str);

protected:
    // Zmienna przechowująca opis węzła (zazwyczaj jednoliterowy, ale może być też np. Er)
    QString value;
};

#endif // ASTNODE_H
