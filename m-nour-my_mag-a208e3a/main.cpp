#include <QtGui/QApplication>
#include <QS60MainApplication>
#include "mainwindow.h"
#include"QTime"
#include"fstream"
using namespace std;
ofstream logfile;

void SimpleLoggingHandler(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Debug: " << msg << "\n";
        break;
    case QtCriticalMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Critical: " << msg << "\n";
        break;
    case QtWarningMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Warning: " << msg << "\n";
        break;
    case QtFatalMsg:
        logfile << QTime::currentTime().toString().toAscii().data() <<  " Fatal: " << msg << "\n";
        abort();
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    logfile.open("./logfile.txt", ios::app);
//    qInstallMsgHandler(SimpleLoggingHandler);

    MainWindow w;




#if defined(Q_WS_S60)
    w.showMaximized();

#else
    w.show();
#endif

    return a.exec();
}
