#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T21:42:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pacman
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    ghost.cpp

HEADERS  += mainwindow.h \
    ghost.h

FORMS    += mainwindow.ui

DISTFILES += \
    .astylerc
