#include "MedianTest.h"
#include <chrono>
#include <cppunit/TestAssert.h>

MedianTest::MedianTest() :
        m_medianInterface(NULL)
{

}

void MedianTest::setMedianInterface(MedianInterface * mediaInterface,
        std::string name)
{
    m_medianInterface = mediaInterface;
    m_medianName = name;
}

void MedianTest::testSingleNumber()
{
    m_medianInterface->add(1);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 1);
    m_medianInterface->clear();

    m_medianInterface->add(0);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 0);
    m_medianInterface->clear();
}

void MedianTest::testTwoNumbers()
{
    m_medianInterface->add(1);
    m_medianInterface->add(2);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 1.5);
    m_medianInterface->clear();
}

void MedianTest::testThreeNumbers()
{
    m_medianInterface->add(1);
    m_medianInterface->add(2);
    m_medianInterface->add(3);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 2);
    m_medianInterface->clear();
}

void MedianTest::testMaxInt()
{
    m_medianInterface->add(2147483647);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 2147483647);
    m_medianInterface->clear();
}

void MedianTest::testMinMaxInt()
{
    m_medianInterface->add(-2147483648);
    m_medianInterface->add(2147483647);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == -0.5);
    m_medianInterface->clear();
}

void MedianTest::testSameNumbers()
{
    m_medianInterface->add(2);
    m_medianInterface->add(2);
    m_medianInterface->add(2);
    m_medianInterface->add(2);
    m_medianInterface->add(2);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 2);
    m_medianInterface->clear();

    m_medianInterface->add(3);
    m_medianInterface->add(3);
    m_medianInterface->add(3);
    m_medianInterface->add(3);
    m_medianInterface->add(3);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 3);
    m_medianInterface->clear();

    m_medianInterface->add(2);
    m_medianInterface->add(2);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 2);
    m_medianInterface->clear();

    m_medianInterface->add(3);
    m_medianInterface->add(3);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 3);
    m_medianInterface->clear();

    m_medianInterface->add(3);
    m_medianInterface->add(3);
    m_medianInterface->add(4);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 3);
    m_medianInterface->clear();
}

void MedianTest::testWideRange()
{
    // 1:100
    for (int i = 1; i <= 100; i++)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 50.5);
    m_medianInterface->clear();

    // 1:10:1
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 1; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 5);
    m_medianInterface->clear();

    // 1:100:1
    for (int i = 1; i <= 100; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 99; i >= 1; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 50);
    m_medianInterface->clear();

    // 2:100:1
    for (int i = 2; i <= 100; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 99; i >= 1; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 50.5);
    m_medianInterface->clear();

    // 1:100:1 step 2
    for (int i = 1; i <= 100; i += 2)
    {
        m_medianInterface->add(i);
    }
    for (int i = 99; i >= 1; i -= 2)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 50);
    m_medianInterface->clear();
}

void MedianTest::testMedianInsert()
{
    m_medianInterface->add(1);
    m_medianInterface->add(2);
    m_medianInterface->add(3);
    m_medianInterface->add(2);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 2);
    m_medianInterface->clear();

    m_medianInterface->add(1);
    m_medianInterface->add(2);
    m_medianInterface->add(3);
    m_medianInterface->add(2);
    m_medianInterface->add(1);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 2);
    m_medianInterface->clear();

    m_medianInterface->add(1);
    m_medianInterface->add(2);
    m_medianInterface->add(3);
    m_medianInterface->add(2);
    m_medianInterface->add(1);
    m_medianInterface->add(1);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 1.5);
    m_medianInterface->clear();

    m_medianInterface->add(1);
    m_medianInterface->add(2);
    m_medianInterface->add(3);
    m_medianInterface->add(2);
    m_medianInterface->add(1);
    m_medianInterface->add(1);
    m_medianInterface->add(1);
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 1);
    m_medianInterface->clear();

    // 1:10:7
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 7; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 7);
    m_medianInterface->clear();

    // 1:10:6
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 6; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 6.5);
    m_medianInterface->clear();

    // 1:10:5
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 5; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 6);
    m_medianInterface->clear();

    // 1:10:4
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 4; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 6);
    m_medianInterface->clear();

    // 1:10:3
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 3; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 6);
    m_medianInterface->clear();

    // 1:10:2
    for (int i = 1; i <= 10; i++)
    {
        m_medianInterface->add(i);
    }
    for (int i = 9; i >= 2; i--)
    {
        m_medianInterface->add(i);
    }
    CPPUNIT_ASSERT(m_medianInterface->getMedian() == 5.5);
    m_medianInterface->clear();
}

void MedianTest::testPerformance()
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 10000; i++)
    {
        m_medianInterface->add(i);
    }
    m_medianInterface->getMedian();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << " time: " << elapsed.count() << "s ";
    m_medianInterface->clear();
}

void MedianTest::addTest(CppUnit::TestSuite *suite, std::string testName, void(MedianTest::* TestMethod)())
{
    suite->addTest(
            new CppUnit::TestCaller<MedianTest>(m_medianName + " " + testName,
                    TestMethod, new MedianTest(*this)));
}

CppUnit::Test * MedianTest::suite()
{
    CppUnit::TestSuite *suite = new CppUnit::TestSuite;
    if (m_medianInterface)
    {
        addTest(suite, "testSingleNumber", &MedianTest::testSingleNumber);
        addTest(suite, "testTwoNumbers", &MedianTest::testTwoNumbers);
        addTest(suite, "testThreeNumbers", &MedianTest::testThreeNumbers);
        addTest(suite, "testMaxInt", &MedianTest::testMaxInt);
        addTest(suite, "testMinMaxInt", &MedianTest::testMinMaxInt);
        addTest(suite, "testSameNumbers", &MedianTest::testSameNumbers);
        addTest(suite, "testWideRange", &MedianTest::testWideRange);
        addTest(suite, "testMedianInsert", &MedianTest::testMedianInsert);
        addTest(suite, "testPerformance", &MedianTest::testPerformance);
    }
    return suite;
}

