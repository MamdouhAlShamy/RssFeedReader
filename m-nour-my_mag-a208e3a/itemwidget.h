#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include"slidingstackedwidget.h"
#include"QListWidgetItem"
#include"QXmlStreamReader"
#include <QtXml>
#include <QWebView>
#include"QByteArray"

namespace Ui {
    class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(SlidingStackedWidget *,QWidget *parent = 0);
    ~ItemWidget();

    void setTopicBody(QListWidgetItem *,QXmlStreamReader *,QByteArray);
    int selectTag(QString tag);

private:
    Ui::ItemWidget *ui;
};

#endif // ITEMWIDGET_H
