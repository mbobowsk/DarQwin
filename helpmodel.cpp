#include "helpmodel.h"

#include <QDebug>

HelpModel::HelpModel() {}


HelpModel::HelpModel(QDomDocument doc)
{
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    //iteracja pierwszego stopnia - po kolejnych wpisach
    while(!n.isNull()) {
        QDomElement e = n.toElement();

        QString tagName = e.tagName();
        if ( tagName == CONFIG_INDEX && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_INDEX),e.text()));
        }
        else if ( tagName == CONFIG_CANNY && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_CANNY),e.text()));
        }
        else if ( tagName == CONFIG_BILATERAL && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_BILATERAL),e.text()));
        }
        else if ( tagName == CONFIG_IDEAL && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_IDEAL),e.text()));
        }
        else if ( tagName == CONFIG_GAUSS && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_GAUSS),e.text()));
        }
        else if ( tagName == CONFIG_BUTTERWORTH && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_BUTTERWORTH),e.text()));
        }
        else if ( tagName == CONFIG_RESIZE && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_RESIZE),e.text()));
        }
        else if ( tagName == CONFIG_CUSTOM && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_CUSTOM),e.text()));
        }
        else if ( tagName == CONFIG_RANK && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_RANK),e.text()));
        }
        else if ( tagName == CONFIG_THRESH && e.text() != "" ) {
            helpMap.insert(std::make_pair(QString(CONFIG_THRESH),e.text()));
        }
        else if ( tagName == CONFIG_LOGIC && e.text() != "" ) {
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
    return "";
}

void HelpModel::createConfig(QTextStream& out, QString path) {
    QDomDocument doc("CONFIG");

    //root element
    QDomElement root = doc.createElement("CONFIG");
    doc.appendChild(root);

    // CONFIG_INDEX
    QDomElement e = doc.createElement(CONFIG_INDEX);
    QDomText text = doc.createTextNode(path);
    e.appendChild(text);
    root.appendChild(e);

    // Usuń nazwę pliku i zostaw tylko ściężkę do folderu
    while ( !path.isEmpty() ) {
        if ( path.at(path.size()-1) != '/' && path.at(path.size()-1) != '\\' ) {
           path.truncate(path.size()-1);
        }
        else
            break;
    }

    // CONFIG_CANNY
    e = doc.createElement(CONFIG_CANNY);
    text = doc.createTextNode(path + "canny.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_BILATERAL
    e = doc.createElement(CONFIG_BILATERAL);
    text = doc.createTextNode(path + "bilateral.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_IDEAL
    e = doc.createElement(CONFIG_IDEAL);
    text = doc.createTextNode(path + "fourier_ideal.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_GAUSS
    e = doc.createElement(CONFIG_GAUSS);
    text = doc.createTextNode(path + "fourier_gauss.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_BUTTERWORTH
    e = doc.createElement(CONFIG_BUTTERWORTH);
    text = doc.createTextNode(path + "fourier_butterworth.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_RESIZE
    e = doc.createElement(CONFIG_RESIZE);
    text = doc.createTextNode(path + "resize.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_CUSTOM
    e = doc.createElement(CONFIG_CUSTOM);
    text = doc.createTextNode(path + "convolution.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_RANK
    e = doc.createElement(CONFIG_RANK);
    text = doc.createTextNode(path + "rank.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_THRESH
    e = doc.createElement(CONFIG_THRESH);
    text = doc.createTextNode(path + "thresh.html");
    e.appendChild(text);
    root.appendChild(e);
    // CONFIG_LOGIC
    e = doc.createElement(CONFIG_LOGIC);
    text = doc.createTextNode(path + "logic.html");
    e.appendChild(text);
    root.appendChild(e);

    out << doc.toString();
}
