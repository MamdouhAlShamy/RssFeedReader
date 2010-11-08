#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXml>
#include <QtNetwork>
#include <QWebView>
#include <QListWidgetItem>
#include <QIcon>
#include <QListWidget>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QGridLayout>
#include"slidingstackedwidget.h"
#include"itemwidget.h"
#include"QListWidgetItem"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //Attri
    QXmlStreamReader xml;
    QUrl url;
    QNetworkAccessManager *mgr;
    QNetworkRequest req;
    QNetworkReply *rep;
    QIcon *icon;
    QByteArray data;

    SlidingStackedWidget *sstacked_widget;


    QListWidget *list;

    QWebView *web_view;

    int no_of_rss_topics;

    int count;

    ItemWidget *nm;
    QList<ItemWidget*> list_of_itemsWidget;


    //FUNCS
    void communicateWithWeb();
    void drawWidget(int);
    int select_tag(QString);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

public slots:
    void rss_render();
    //    void setTopicBody(QListWidgetItem*);
    void errorInConnection();
    void drawAll();
    void full_screen(QListWidgetItem*);


};

#endif // MAINWINDOW_H
