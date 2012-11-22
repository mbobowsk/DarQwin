#include "helpmodel.h"

HelpModel::HelpModel(QDomDocument doc)
{
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    //iteracja pierwszego stopnia - po kolejnych wpisach
    while(!n.isNull()) {
        QDomElement e = n.toElement();

        QString tagName = e.tagName();
        if ( tagName == CONFIG_INDEX ) {
            helpMap.insert(std::make_pair(QString(CONFIG_INDEX),e.text()));
        }
        else if ( tagName == CONFIG_CANNY ) {
            helpMap.insert(std::make_pair(QString(CONFIG_CANNY),e.text()));
        }
        n = n.nextSibling();
    }
}

QString HelpModel::find(QString key) {
    std::map<QString,QString>::iterator it = helpMap.find(key);
    if ( it == helpMap.end() )
        return QString("");
    QString ret = it->second;
    if ( !ret.size() == 0 )
        return ret;
}
