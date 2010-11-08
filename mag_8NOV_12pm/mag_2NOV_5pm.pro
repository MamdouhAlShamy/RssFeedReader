#-------------------------------------------------
#
# Project created by QtCreator 2010-09-30T02:07:51
#
#-------------------------------------------------

QT       += network xml webkit

TARGET = qrss
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    slidingstackedwidget.cpp \
    itemwidget.cpp \
    xml.cpp

HEADERS  += mainwindow.h \
    slidingstackedwidget.h \
    itemwidget.h \
    xml.h

FORMS    += mainwindow.ui \
    itemwidget.ui
