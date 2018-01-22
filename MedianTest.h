#ifndef TESTCASE_H_
#define TESTCASE_H_

#include <cppunit/Test.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include "MedianInterface.h"

class MedianTest: public CppUnit::TestFixture
{
public:

    MedianTest();

    void setMedianInterface(MedianInterface * mediaInterface, std::string name);
    void testSingleNumber();
    void testTwoNumbers();
    void testThreeNumbers();
    void testMaxInt();
    void testMinMaxInt();
    void testSameNumbers();
    void testWideRange();
    void testMedianInsert();
    void testPerformance();

    void addTest(CppUnit::TestSuite *suite, std::string testName, void(MedianTest::* TestMethod)());
    CppUnit::Test * suite();

private:
    std::string m_medianName;
    MedianInterface * m_medianInterface;
};

#endif /* TESTCASE_H_ */
