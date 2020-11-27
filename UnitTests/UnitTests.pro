QT += testlib
QT -= gui

TARGET = tst_statistics
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../Game/chaser.cpp \
    tst_chaser.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../Game/chaser.h

INCLUDEPATH +=
    ../Game/
