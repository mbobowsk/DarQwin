#ifndef SIZEHINTLISTWIDGET_H
#define SIZEHINTLISTWIDGET_H

#include <QListWidget>

class SizeHintListWidget : public QListWidget
{
public:
    SizeHintListWidget(QWidget *w) : QListWidget(w) {}

    QSize sizeHint() const {
        return QSize(450,900);
    };
};

#endif // SIZEHINTLISTWIDGET_H
