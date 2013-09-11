TEMPLATE = subdirs

SUBDIRS += \
    core \
    tests

TEST_LIB_PATHS += $$OUT_PWD/core
include(3rdparty/QMakeTestRunner/testtarget.pri)
