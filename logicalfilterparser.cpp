#include "logicalfilterparser.h"
#include <QRegExp>

#include <QDebug>

LogicalFilterParser::LogicalFilterParser()
{
}

ASTNode* LogicalFilterParser::parseGray(QString str) {
    // Usun whitespace
    QString s = str.simplified();
    s = s.remove(QChar(' '));

    // Sprawdz czy nie ma niedozwolonych znaków @ lub #
    QRegExp specialSigns("[@#]");
    int position = specialSigns.indexIn(s);
    if ( position != -1 )
        return NULL;

    // Zapisz w wektorze wszystkie warunki, a na ich miejsce wstaw '@'
    std::vector<ASTCondition*> conditions;
    QRegExp condition ("[A-I](>|<|==)([A-I]|(\\d{1,3}))");
    while ( (position = condition.indexIn(s)) != -1 ) {
        QString cap = condition.cap(0);
        // Ile jest cyfr w tekście
        int digitCounter = 0;
        for (int i = 2; i < cap.size(); ++i) {
             if (cap.at(i) >= QChar('0') && cap.at(i) <= QChar('9'))
                 digitCounter++;
         }
        //Operator może zajmować jeden lub dwa znaki - rozważone różne przypadki zależne również
        //od liczby cyfr w stringu
        s.replace(position,cap.size(),"@");
        //A>B
        if ( digitCounter == 0 && cap.size() == 3  ) {
            conditions.push_back(new ASTCondition(QString(cap[1]), new ASTNode(QString(cap[0])), new ASTNode(QString(cap[2]) )));
        }
        //A>10
        else if ( cap.size()-digitCounter == 2 ) {
            conditions.push_back(new ASTCondition(QString(cap[1]), new ASTNode(QString(cap[0])), new ASTNode(cap.mid(2,digitCounter)) ));
        }
        //A==B
        else if ( digitCounter == 0 && cap.size() == 4 ) {
            conditions.push_back(new ASTCondition(QString(cap.mid(1,2)), new ASTNode(QString(cap[0])), new ASTNode(cap.mid(2,digitCounter)) ));
        }
        //A==10
        else {
            conditions.push_back(new ASTCondition(cap.mid(1,2), new ASTNode(QString(cap[0])), new ASTNode(cap.mid(3,digitCounter)) ));
        }
    }

    // Sprawdz czy są jakieś znaki poza @,& lub |
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != QChar('@') && s.at(i) != QChar('&') && s.at(i) != QChar('|')) {
            //porządki
            for ( int i = 0; i < conditions.size(); i++ ) {
                delete conditions[i];
            }
            return NULL;
        }
    }

    // Znajdź w tekście wzorce typu @&&@
    QRegExp conditionAnd ("@&&@");
    while ( (position = conditionAnd.indexIn(s)) != -1 ) {
        QString cap = conditionAnd.cap(0);
        //index - które z kolei wystąpienie znaku @ lub #
        int index = 0;
        for (int i = 0; i <  position; ++i) {
            if (cap.at(i) == QChar('@') || cap.at(i) == QChar('#') )
                index++;
        }

        //Zastąp wyrażenie '#'
        s.replace(position,4,"#");
        ASTExpression *exp = new ASTExpression(QString(cap.mid(1,2)), conditions[index], conditions[index+1]);
        //Usuń wpisy o warunkach prostych i zastąp warunkiem złożonym
        conditions.erase(conditions.begin()+index, conditions.begin()+index+2);
        conditions.insert(conditions.begin()+index,exp);
    }


    // Znajdź w tekście wzorce typu @&&# lub #&&@
    QRegExp conditionAnd1 ("#&&@|@&&#");
    while ( (position = conditionAnd1.indexIn(s)) != -1 ) {
        QString cap = conditionAnd1.cap(0);
        //index - które z kolei wystąpienie znaku @ lub #
        int index = 0;
        for (int i = 0; i <  position; ++i) {
            if (cap.at(i) == QChar('@') || cap.at(i) == QChar('#') )
                index++;
        }

        //Zastąp wyrażenie '#'
        s.replace(position,4,"#");
        ASTExpression *exp = new ASTExpression(QString(cap.mid(1,2)), conditions[index], conditions[index+1]);
        //Usuń wpisy o warunkach prostych i zastąp warunkiem złożonym
        conditions.erase(conditions.begin()+index, conditions.begin()+index+2);
        conditions.insert(conditions.begin()+index,exp);
    }

    // Sprawdź czy zostało coś oprócz '|', '#' i '@'
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != QChar('@') && s.at(i) != QChar('#') && s.at(i) != QChar('|')) {
            //porządki
            for ( int i = 0; i < conditions.size(); i++ ) {
                delete conditions[i];
            }
            return NULL;
        }
    }

    // Buduj drzewo od lewej do prawej
    qDebug() << "String przed:" << s;
    for ( int i = 0; conditions.size() != 1; ++i ) {
        //Zastąp wyrażenie '#'
        s.replace(0,4,"#");
        ASTExpression *exp = new ASTExpression(QString("||"), conditions[0], conditions[1]);
        //Usuń wpisy o pierwszych dwóch warunkach i zastąp je warunkiem złożonym
        conditions.erase(conditions.begin(), conditions.begin()+2);
        conditions.insert(conditions.begin(),exp);
    }


    qDebug() << "String po:" << s;
    for ( int i = 0; i < conditions.size(); i++ ) {
        qDebug() << "Warunek: " << conditions[i]->getValue() << conditions[i]->getLeft()->getValue() << conditions[i]->getRight()->getValue() ;
    }

    // W wektorze pozostaje tylko korzeń
    return conditions[0];
}

ASTNode* LogicalFilterParser::parseRGB(QString str) {
    return new ASTNode("WTF");
}
