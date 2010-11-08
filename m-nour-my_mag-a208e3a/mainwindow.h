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
#include"QByteArray"
#include"QDebug"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //Attri
    QXmlStreamReader *xml;
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

    //FUNCS
    void communicateWithWeb();

  static  int selectTag(QString);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void rss_render();
//    void setTopicBody(QListWidgetItem*);
    void errorInConnection();
    void drawWidget(QListWidgetItem*);


};

#endif // MAINWINDOW_H
