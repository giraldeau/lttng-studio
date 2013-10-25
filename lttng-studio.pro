TEMPLATE = subdirs

SUBDIRS += \
    lib \
    tests

TEST_LIB_PATHS += $$OUT_PWD/lib/lttngstudio
TEST_CUSTOM_ENV += \\\"top_srcdir="$$top_srcdir"\\\"
TEST_CUSTOM_ENV += \\\"top_builddir="$$top_builddir"\\\"
include(3rdparty/QMakeTestRunner/testtarget.pri)
