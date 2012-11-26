#include "logicalfilterparser.h"
#include <QRegExp>

#include <QDebug>

LogicalFilterParser::LogicalFilterParser()
{
}

ASTCondition* LogicalFilterParser::parseRGB(QString str) {
    // Usun whitespace
    QString s = str.simplified();
    s = s.remove(QChar(' '));

    // Sprawdz czy nie ma niedozwolonych znaków @ lub #
    QRegExp specialSigns("[@#]");
    int position = specialSigns.indexIn(s);
    if ( position != -1 )
        return NULL;

    // Sprawdź sekwencje w nawiasach i parsuj je rekursywnie
    std::vector<ASTCondition*> bracketsExp;
    while (1) {
        int indexBeg = -1; // dla '('
        int indexEnd = -1; // dla ')'
        // przeszukaj sekwencję (*)
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) == QChar('(')) {
                if ( indexBeg == -1)
                    indexBeg = i;
                else
                    // zagnieżdżone nawiasy - błąd
                    return NULL;
            }
            if (s.at(i) == QChar(')')) {
                if ( indexBeg == -1)
                    // nawias zamykający przed otwierającym
                    return NULL;
                else {
                    indexEnd = i;
                    break;
                }
            }
        }
        // nie ma nawiasów
        if ( indexBeg == -1 )
            break;
        // +1/-1 nie zawierają nawiasów
        QString brackets = s.mid(indexBeg+1,indexEnd-indexBeg-1);
        ASTCondition* exp = parseRGB(brackets);
        if ( exp == NULL )
            return NULL;
        bracketsExp.push_back(exp);
        s.replace(indexBeg,indexEnd-indexBeg+1,"#");
    }

    // Zapisz w wektorze wszystkie warunki, a na ich miejsce wstaw '@'
    std::vector<ASTCondition*> expresions;
    QRegExp condition ("[A-I][rgb](>|<|==|>=|<=)([A-I][rgb]|(\\d{1,3}))");
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
        //Ar>Br
        if ( digitCounter == 0 && cap.size() == 5  ) {
            expresions.push_back(new ASTCondition(QString(cap[2]), new ASTNode(cap.mid(0,2)), new ASTNode(cap.mid(3,2) )));
        }
        //Ar>10
        else if ( cap.size()-digitCounter == 3 ) {
            expresions.push_back(new ASTCondition(QString(cap[2]), new ASTNode(cap.mid(0,2)), new ASTNode(cap.mid(3,digitCounter)) ));
        }
        //Ar==Br
        else if ( digitCounter == 0 && cap.size() == 6 ) {
            expresions.push_back(new ASTCondition(QString(cap.mid(2,2)), new ASTNode(cap.mid(0,2)), new ASTNode(cap.mid(4,digitCounter)) ));
        }
        //Ar==10
        else {
            expresions.push_back(new ASTCondition(cap.mid(2,2), new ASTNode(cap.mid(0,2)), new ASTNode(cap.mid(4,digitCounter)) ));
        }
    }

    // Sprawdz czy są jakieś znaki poza @,&,# lub |
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != QChar('@') && s.at(i) != QChar('&') && s.at(i) != QChar('|') && s.at(i) != QChar('#') ) {
            //porządki
            for ( int i = 0; i < expresions.size(); i++ ) {
                delete expresions[i];
            }
            for ( int i = 0; i < bracketsExp.size(); i++ ) {
                delete bracketsExp[i];
            }
            return NULL;
        }
    }

    // Merguj wektor poddrzew nawiasów z poddrzewami wyrażeń
    //index - które z kolei wystąpienie znaku @ lub #
    int index = 0;
    for (int i = 0; i <  s.size(); ++i) {
        if ( s.at(i) == QChar('#') ) {
            // tu jest nawias
            ASTCondition *exp = bracketsExp[0];
            bracketsExp.erase(bracketsExp.begin());
            expresions.insert(expresions.begin()+index,exp);
            index++;
        }
        else if ( s.at(i) == QChar('@') )
            index++;
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
        ASTExpression *exp = new ASTExpression(QString(cap.mid(1,2)), expresions[index], expresions[index+1]);
        //Usuń wpisy o warunkach prostych i zastąp warunkiem złożonym
        expresions.erase(expresions.begin()+index, expresions.begin()+index+2);
        expresions.insert(expresions.begin()+index,exp);
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
        ASTExpression *exp = new ASTExpression(QString(cap.mid(1,2)), expresions[index], expresions[index+1]);
        //Usuń wpisy o warunkach prostych i zastąp warunkiem złożonym
        expresions.erase(expresions.begin()+index, expresions.begin()+index+2);
        expresions.insert(expresions.begin()+index,exp);
    }

    // Sprawdź czy zostało coś oprócz '|', '#' i '@'
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != QChar('@') && s.at(i) != QChar('#') && s.at(i) != QChar('|')) {
            //porządki
            for ( int i = 0; i < expresions.size(); i++ ) {
                delete expresions[i];
            }
            return NULL;
        }
    }

    // Buduj drzewo od lewej do prawej
    for ( int i = 0; expresions.size() != 1; ++i ) {
        //Zastąp wyrażenie '#'
        s.replace(0,4,"#");
        ASTExpression *exp = new ASTExpression(QString("||"), expresions[0], expresions[1]);
        //Usuń wpisy o pierwszych dwóch warunkach i zastąp je warunkiem złożonym
        expresions.erase(expresions.begin(), expresions.begin()+2);
        expresions.insert(expresions.begin(),exp);
    }

    // W wektorze pozostaje tylko korzeń
    return expresions[0];
}

ASTCondition* LogicalFilterParser::parseGray(QString str) {
    // Usun whitespace
    QString s = str.simplified();
    s = s.remove(QChar(' '));

    // Sprawdz czy nie ma niedozwolonych znaków @ lub #
    QRegExp specialSigns("[@#]");
    int position = specialSigns.indexIn(s);
    if ( position != -1 )
        return NULL;

    // Sprawdź sekwencje w nawiasach i parsuj je rekursywnie
    std::vector<ASTCondition*> bracketsExp;
    while (1) {
        int indexBeg = -1; // dla '('
        int indexEnd = -1; // dla ')'
        // przeszukaj sekwencję (*)
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) == QChar('(')) {
                if ( indexBeg == -1)
                    indexBeg = i;
                else
                    // zagnieżdżone nawiasy - błąd
                    return NULL;
            }
            if (s.at(i) == QChar(')')) {
                if ( indexBeg == -1)
                    // nawias zamykający przed otwierającym
                    return NULL;
                else {
                    indexEnd = i;
                    break;
                }
            }
        }
        // nie ma nawiasów
        if ( indexBeg == -1 )
            break;
        // +1/-1 nie zawierają nawiasów
        QString brackets = s.mid(indexBeg+1,indexEnd-indexBeg-1);
        ASTCondition* exp = parseGray(brackets);
        if ( exp == NULL )
            return NULL;
        bracketsExp.push_back(exp);
        s.replace(indexBeg,indexEnd-indexBeg+1,"#");
    }

    // Zapisz w wektorze wszystkie warunki, a na ich miejsce wstaw '@'
    std::vector<ASTCondition*> expresions;
    QRegExp condition ("[A-I](>|<|==|>=|<=)([A-I]|(\\d{1,3}))");
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
            expresions.push_back(new ASTCondition(QString(cap[1]), new ASTNode(QString(cap[0])), new ASTNode(QString(cap[2]) )));
        }
        //A>10
        else if ( cap.size()-digitCounter == 2 ) {
            expresions.push_back(new ASTCondition(QString(cap[1]), new ASTNode(QString(cap[0])), new ASTNode(cap.mid(2,digitCounter)) ));
        }
        //A==B
        else if ( digitCounter == 0 && cap.size() == 4 ) {
            expresions.push_back(new ASTCondition(QString(cap.mid(1,2)), new ASTNode(QString(cap[0])), new ASTNode(cap.mid(2,digitCounter)) ));
        }
        //A==10
        else {
            expresions.push_back(new ASTCondition(cap.mid(1,2), new ASTNode(QString(cap[0])), new ASTNode(cap.mid(3,digitCounter)) ));
        }
    }

    // Sprawdz czy są jakieś znaki poza @,&,# lub |
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != QChar('@') && s.at(i) != QChar('&') && s.at(i) != QChar('|') && s.at(i) != QChar('#') ) {
            //porządki
            for ( int i = 0; i < expresions.size(); i++ ) {
                delete expresions[i];
            }
            for ( int i = 0; i < bracketsExp.size(); i++ ) {
                delete bracketsExp[i];
            }
            return NULL;
        }
    }

    // Merguj wektor poddrzew nawiasów z poddrzewami wyrażeń
    //index - które z kolei wystąpienie znaku @ lub #
    int index = 0;
    for (int i = 0; i <  s.size(); ++i) {
        if ( s.at(i) == QChar('#') ) {
            // tu jest nawias
            ASTCondition *exp = bracketsExp[0];
            bracketsExp.erase(bracketsExp.begin());
            expresions.insert(expresions.begin()+index,exp);
            index++;
        }
        else if ( s.at(i) == QChar('@') )
            index++;
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
        ASTExpression *exp = new ASTExpression(QString(cap.mid(1,2)), expresions[index], expresions[index+1]);
        //Usuń wpisy o warunkach prostych i zastąp warunkiem złożonym
        expresions.erase(expresions.begin()+index, expresions.begin()+index+2);
        expresions.insert(expresions.begin()+index,exp);
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
        ASTExpression *exp = new ASTExpression(QString(cap.mid(1,2)), expresions[index], expresions[index+1]);
        //Usuń wpisy o warunkach prostych i zastąp warunkiem złożonym
        expresions.erase(expresions.begin()+index, expresions.begin()+index+2);
        expresions.insert(expresions.begin()+index,exp);
    }

    // Sprawdź czy zostało coś oprócz '|', '#' i '@'
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != QChar('@') && s.at(i) != QChar('#') && s.at(i) != QChar('|')) {
            //porządki
            for ( int i = 0; i < expresions.size(); i++ ) {
                delete expresions[i];
            }
            return NULL;
        }
    }

    // Buduj drzewo od lewej do prawej
    for ( int i = 0; expresions.size() != 1; ++i ) {
        //Zastąp wyrażenie '#'
        s.replace(0,4,"#");
        ASTExpression *exp = new ASTExpression(QString("||"), expresions[0], expresions[1]);
        //Usuń wpisy o pierwszych dwóch warunkach i zastąp je warunkiem złożonym
        expresions.erase(expresions.begin(), expresions.begin()+2);
        expresions.insert(expresions.begin(),exp);
    }

    // W wektorze pozostaje tylko korzeń
    return expresions[0];
}

bool LogicalFilterParser::parseResult(QString str, bool rgb) {
    // Usun whitespace
    QString s = str.simplified();
    s = s.remove(QChar(' '));

    if ( rgb ) {
        QRegExp result ("[A-I][rgb]=\\d{1,3})");
        if ( result.indexIn(s) == -1 )
            return false;
        else
            return true;
    }
    else {
        QRegExp result ("[A-I]=\\d{1,3})");
        if ( result.indexIn(s) == -1 )
            return false;
        else
            return true;
    }

}
