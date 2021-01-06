#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class xx : public QObject
{
    Q_OBJECT

public:
    xx();
    ~xx();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

xx::xx()
{

}

xx::~xx()
{

}

void xx::initTestCase()
{

}

void xx::cleanupTestCase()
{

}

void xx::test_case1()
{

}

QTEST_MAIN(xx)

#include "tst_xx.moc"
