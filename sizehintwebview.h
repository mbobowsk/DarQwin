#ifndef SIZEHINTWEBVIEW_H
#define SIZEHINTWEBVIEW_H

#include <QWebView>

class SizeHintWebView : public QWebView
{
public:
    SizeHintWebView(QWidget *w) : QWebView(w) {}

    QSize sizeHint() const {
        return QSize(450,900);
    };
};

#endif // SIZEHINTWEBVIEW_H
