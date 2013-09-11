#include <QString>
#include <QtTest>
#include <QProcessEnvironment>

#include <iostream>

#include <babeltrace/babeltrace.h>
#include <babeltrace/format.h>
#include <babeltrace/context.h>
#include <babeltrace/iterator.h>
#include <babeltrace/ctf/events.h>
#include <babeltrace/ctf/iterator.h>

using namespace std;

class BabeltraceTest : public QObject
{
    Q_OBJECT
    
public:
    BabeltraceTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

BabeltraceTest::BabeltraceTest()
{
}

void BabeltraceTest::initTestCase()
{
}

void BabeltraceTest::cleanupTestCase()
{
}

void BabeltraceTest::testCase1()
{
    struct bt_ctf_iter *iter;
    struct bt_iter_pos begin_pos;
    struct bt_ctf_event *ctf_event;
    int count = 0;

    QString path = SRCDIR "/ctf-traces/succeed/wk-heartbeat-u/";
    // open a trace
    struct bt_context *ctx = bt_context_create();
    int trace_id = bt_context_add_trace(ctx, path.toStdString().c_str(), "ctf", NULL, NULL, NULL);
    QVERIFY2(trace_id >= 0, "Failed: bt_context_add_trace");

    // read all event
    begin_pos.type = BT_SEEK_BEGIN;
    iter = bt_ctf_iter_create(ctx, &begin_pos, NULL);
    while((ctf_event = bt_ctf_iter_read_event(iter))) {
        count++;
        bt_iter_next(bt_ctf_get_iter(iter));
    }
    QVERIFY2(count == 20, "Wrong event count");
}

QTEST_APPLESS_MAIN(BabeltraceTest)

#include "tst_babeltracetest.moc"
