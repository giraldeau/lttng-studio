#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T16:00:13
#
#-------------------------------------------------

QT       -= gui

TARGET = lttngstudio
TEMPLATE = lib

include(unwind/unwind.pri)

isEmpty(PREFIX) {
    PREFIX = /usr/local
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = $$PREFIX
    }
    INSTALLS += target
}

