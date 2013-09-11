# include this file in test subprojects

QT       += testlib

CONFIG   += testcase
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../core/release/ -llttngstudiocore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../core/debug/ -llttngstudiocore
else:unix: LIBS += -L$${top_builddir}/core/ -llttngstudiocore

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += babeltrace

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core
