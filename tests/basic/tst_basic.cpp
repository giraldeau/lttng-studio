#include <QString>
#include <QtTest>
#include <QProcessEnvironment>

#include <lttngstudio.h>

class tst_Basic : public QObject
{
    Q_OBJECT

public:
    tst_Basic();

private Q_SLOTS:
    void testImportCore();
    void testEnvironment_data();
    void testEnvironment();
};

tst_Basic::tst_Basic()
{
}

void tst_Basic::testImportCore()
{
    Core *core = new Core();
    QVERIFY2(core, "Failure");
    delete core;
}

void tst_Basic::testEnvironment_data()
{
    QTest::addColumn<QString>("var");
    QTest::newRow("top source dir") << "top_srcdir";
    QTest::newRow("top build dir") << "top_builddir";
}

void tst_Basic::testEnvironment()
{
    QFETCH(QString, var);

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QVERIFY2(env.value(var, "").length() > 0, "undefined env var");
}

QTEST_MAIN(tst_Basic)

#include "tst_basic.moc"
