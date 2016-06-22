#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T14:34:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    socketserver.cpp \
    serverthread.cpp

HEADERS  += mainwindow.h \
    socketserver.h \
    serverthread.h

FORMS    += mainwindow.ui
LIBS += -lws2_32
CONFIG += c++11
