# include this file in test subprojects

QT       += testlib

CONFIG   += testcase
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/lttngstudio/release/ -llttngstudio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/lttngstudio/debug/ -llttngstudio
else:unix: LIBS += -L$${top_builddir}/lib/lttngstudio/ -llttngstudio

#unix: CONFIG += link_pkgconfig
#unix: PKGCONFIG += babeltrace

LIBS += -L/usr/lib/x86_64-linux-gnu -lunwind -lunwind-x86_64 -lbabeltrace -lbabeltrace-ctf

INCLUDEPATH += $$PWD/../lib/lttngstudio
DEPENDPATH += $$PWD/../lib/lttngstudio

