#ifndef SIZEHINTTABWIDGET_H
#define SIZEHINTTABWIDGET_H

#include <QTabWidget>

//Pomocnicza klasa do obsługi sizeHint
class sizeHintTabWidget : public QTabWidget
{
public:
    sizeHintTabWidget(QWidget *w) : QTabWidget(w) {}

    QSize sizeHint() const {
        return QSize(200,200);
    };
};

#endif // SIZEHINTTABWIDGET_H
