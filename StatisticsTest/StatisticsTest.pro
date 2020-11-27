QT += testlib
QT -= gui

target = tst_statisticstest
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_statisticstest.cpp \
    ../game/statistics.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += ../game/statistics.h

INCLUDEPATH += ../game/
