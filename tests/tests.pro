#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T16:02:34
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_teststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_testsbasic.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core/release/ -llttngstudiocore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core/debug/ -llttngstudiocore
else:unix: LIBS += -L$$OUT_PWD/../core/ -llttngstudiocore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core
