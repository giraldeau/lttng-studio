#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T16:00:13
#
#-------------------------------------------------

QT       -= gui

TARGET = lttngstudiocore
TEMPLATE = lib

DEFINES += LTTNG_STUDIO_CORE_LIBRARY

SOURCES += core.cpp \
    unwind.cpp

HEADERS += core.h\
        core_global.h \
    unwind.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

LIBS += -L/usr/lib/x86_64-linux-gnu -lunwind -lunwind-x86_64
LIBS += -lbabeltrace -lbabeltrace-ctf
