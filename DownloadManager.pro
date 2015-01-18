/*
    Copyright (C) Oleg Ziakun
*/

QT  += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++0x
QMAKE_MAC_SDK = macosx10.9

TARGET = DownloadManager
TEMPLATE = app

SOURCES += main.cpp
SOURCES +=  display.cpp
SOURCES += mainwindow.cpp
SOURCES += networkmanager.cpp
SOURCES += download.cpp
SOURCES +=progressbar.cpp

HEADERS += mainwindow.h
HEADERS += unittests.h
HEADERS += display.h
HEADERS += networkmanager.h
HEADERS += download.h
HEADERS +=progressbar.h

FORMS  += mainwindow.ui
