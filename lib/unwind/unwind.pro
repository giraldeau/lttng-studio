#-------------------------------------------------
#
# Project created by QtCreator 2013-10-25T12:04:13
#
#-------------------------------------------------

QT       -= gui

TARGET = unwind
TEMPLATE = lib
CONFIG += staticlib

SOURCES += unwind.cpp

HEADERS += unwind.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
