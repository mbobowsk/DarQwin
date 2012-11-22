#ifndef HELPMODEL_H
#define HELPMODEL_H

#include <map>
#include <QString>
#include <QDomDocument>

#define CONFIG_INDEX "INDEX"
#define CONFIG_CANNY "CANNY"

class HelpModel
{
public:
    HelpModel(QDomDocument doc);
    QString find(QString key);

private:
    std::map<QString, QString> helpMap;

};

#endif // HELPMODEL_H
