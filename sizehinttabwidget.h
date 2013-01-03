#ifndef SIZEHINTTABWIDGET_H
#define SIZEHINTTABWIDGET_H

#include <QTabWidget>

//Pomocnicza klasa do obsługi sizeHint
class sizeHintTabWidget : public QTabWidget
{
public:
    sizeHintTabWidget(QWidget *w) : QTabWidget(w) {setMaximumWidth(480);}

    QSize sizeHint() const {
        return QSize(280,900);
    };
};

#endif // SIZEHINTTABWIDGET_H
