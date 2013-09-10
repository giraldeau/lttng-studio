#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T16:02:34
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

#TARGET = tst_basic
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_basic.cpp \

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../core/release/ -llttngstudiocore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../core/debug/ -llttngstudiocore
else:unix: LIBS += -L$$OUT_PWD/../../core/ -llttngstudiocore

INCLUDEPATH += $$PWD/../../core
DEPENDPATH += $$PWD/../../core

# This works on Unix to load local shared library
# at runtime without setting LD_LIBRARY_PATH
QMAKE_RPATHDIR += $$OUT_PWD/../../core
