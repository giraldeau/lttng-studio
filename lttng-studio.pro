TEMPLATE = subdirs

SUBDIRS += \
    core \
    tests

TEST_LIB_PATHS += $$OUT_PWD/core
TEST_CUSTOM_ENV += \\\"top_srcdir="$$top_srcdir"\\\"
TEST_CUSTOM_ENV += \\\"top_builddir="$$top_builddir"\\\"
include(3rdparty/QMakeTestRunner/testtarget.pri)
