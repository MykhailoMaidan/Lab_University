#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T00:37:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IPZ_Hubish
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    payment.cpp \
    clientsocket.cpp

HEADERS  += mainwindow.h \
    payment.h \
    clientsocket.h

FORMS    += mainwindow.ui \
    payment.ui
LIBS += -lws2_32
CONFIG += c++11
