#include <iostream>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

#include "MedianMap.h"
#include "MedianMapV2.h"
#include "MedianTest.h"

int main()
{
    MedianTest medianMapTest;
    MedianMap medianMap;
    medianMapTest.setMedianInterface(&medianMap, "MedianMap");

    MedianTest medianMapV2Test;
    MedianMapV2 medianMapV2;
    medianMapV2Test.setMedianInterface(&medianMapV2, "medianMapV2");

    CppUnit::TestResult controller;

    CppUnit::TestResultCollector result;
    controller.addListener( &result );

    CppUnit::BriefTestProgressListener progressListener;
    controller.addListener( &progressListener );

    CppUnit::TestRunner runner;
    runner.addTest(medianMapTest.suite());
    runner.addTest(medianMapV2Test.suite());
    runner.run( controller );
    return 0;
}

