#include "helpmodel.h"

HelpModel::HelpModel() {}


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
        else if ( tagName == CONFIG_BILATERAL ) {
            helpMap.insert(std::make_pair(QString(CONFIG_BILATERAL),e.text()));
        }
        else if ( tagName == CONFIG_IDEAL ) {
            helpMap.insert(std::make_pair(QString(CONFIG_IDEAL),e.text()));
        }
        else if ( tagName == CONFIG_GAUSS ) {
            helpMap.insert(std::make_pair(QString(CONFIG_GAUSS),e.text()));
        }
        else if ( tagName == CONFIG_BUTTERWORTH ) {
            helpMap.insert(std::make_pair(QString(CONFIG_BUTTERWORTH),e.text()));
        }
        else if ( tagName == CONFIG_RESIZE ) {
            helpMap.insert(std::make_pair(QString(CONFIG_RESIZE),e.text()));
        }
        else if ( tagName == CONFIG_CUSTOM ) {
            helpMap.insert(std::make_pair(QString(CONFIG_CUSTOM),e.text()));
        }
        else if ( tagName == CONFIG_RANK ) {
            helpMap.insert(std::make_pair(QString(CONFIG_RANK),e.text()));
        }
        else if ( tagName == CONFIG_THRESH ) {
            helpMap.insert(std::make_pair(QString(CONFIG_THRESH),e.text()));
        }
        else if ( tagName == CONFIG_LOGIC ) {
            helpMap.insert(std::make_pair(QString(CONFIG_LOGIC),e.text()));
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

void HelpModel::createConfig(QTextStream& out) {
    QDomDocument doc("CONFIG");

    //root element
    QDomElement root = doc.createElement("CONFIG");
    doc.appendChild(root);

    // CONFIG_INDEX
    QDomElement e = doc.createElement(CONFIG_INDEX);
    QDomText text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_CANNY
    e = doc.createElement(CONFIG_CANNY);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_BILATERAL
    e = doc.createElement(CONFIG_BILATERAL);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_IDEAL
    e = doc.createElement(CONFIG_IDEAL);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_GAUSS
    e = doc.createElement(CONFIG_GAUSS);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_BUTTERWORTH
    e = doc.createElement(CONFIG_BUTTERWORTH);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_RESIZE
    e = doc.createElement(CONFIG_RESIZE);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_CUSTOM
    e = doc.createElement(CONFIG_CUSTOM);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_RANK
    e = doc.createElement(CONFIG_RANK);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_THRESH
    e = doc.createElement(CONFIG_THRESH);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_LOGIC
    e = doc.createElement(CONFIG_LOGIC);
    text = doc.createTextNode(" ");
    e.appendChild(text);
    root.appendChild(e);

    out << doc.toString();
}
