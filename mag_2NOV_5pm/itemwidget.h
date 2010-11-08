#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include"slidingstackedwidget.h"
#include"QWebView"
#include"QListWidget"

namespace Ui {
    class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(SlidingStackedWidget *,QWidget *parent = 0);
    ~ItemWidget();
//    QWebView *web_view;
//    QListWidget *m_list;

    QString title, description, pub_date;

    QUrl *link;
    QList<ItemWidget*>m_list;

    //Func
    void getHtml(QString html);

    void setTopicBody();

    void setItemWidgetList(QList<ItemWidget*>);

private:
    Ui::ItemWidget *ui;

public slots:
    void myNextItem();

};

#endif // ITEMWIDGET_H
