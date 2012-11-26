#ifndef HELPMODEL_H
#define HELPMODEL_H

#include <map>
#include <QString>
#include <QDomDocument>
#include <QTextStream>

#define CONFIG_INDEX "INDEX"
#define CONFIG_CANNY "CANNY"
#define CONFIG_BILATERAL "BILATERAL"
#define CONFIG_IDEAL "FOURIER_IDEAL"
#define CONFIG_GAUSS "FOURIER_GAUSS"
#define CONFIG_BUTTERWORTH "FOURIER_BUTTERWORTH"
#define CONFIG_RESIZE "RESIZE"
#define CONFIG_CUSTOM "CONVOLUTION"
#define CONFIG_RANK "RANK"
#define CONFIG_THRESH "THRESHOLD"
#define CONFIG_LOGIC "LOGICAL_FILTER"

class HelpModel
{
public:
    HelpModel();
    HelpModel(QDomDocument doc);
    QString find(QString key);
    void createConfig(QTextStream& out);

private:
    std::map<QString, QString> helpMap;

};

#endif // HELPMODEL_H
