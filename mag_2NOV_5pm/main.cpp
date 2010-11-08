#include <QtGui/QApplication>
#include <QS60MainApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //QDesktopWidget *h=new QDesktopWidget();
  // w.setFixedSize(h->size());

#if defined(Q_WS_S60)
    w.showMaximized();

#else
    w.show();
#endif

    return a.exec();
}
