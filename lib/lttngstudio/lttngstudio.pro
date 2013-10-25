#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T16:00:13
#
#-------------------------------------------------

QT       -= gui

TARGET = lttngstudio
TEMPLATE = lib

DEFINES += LTTNG_STUDIO_CORE_LIBRARY

SOURCES += lttngstudio.cpp

HEADERS += lttngstudio.h\
        lttngstudio_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

#-------------------------------------------------
# Unwind
#-------------------------------------------------
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../unwind/release/ -lunwind
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../unwind/debug/ -lunwind
else:unix: LIBS += -L$$OUT_PWD/../unwind/ -lunwind

INCLUDEPATH += $$PWD/../unwind
DEPENDPATH += $$PWD/../unwind

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../unwind/release/unwind.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../unwind/debug/unwind.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../unwind/libunwind.a
