#include <QString>
#include <QtTest>
#include <QProcessEnvironment>
#include <QOptParser>

class tst_Basic : public QObject
{
    Q_OBJECT

public:
    tst_Basic();

private Q_SLOTS:
    void testEnvironment_data();
    void testEnvironment();
    void testArguments();
};

tst_Basic::tst_Basic()
{
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

void tst_Basic::testArguments()
{
    char *argv[] = { "--test", "hello" };
    QOptParser parser(1, argv);
    QVERIFY(true);
}

QTEST_MAIN(tst_Basic)

#include "tst_basic.moc"
