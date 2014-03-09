#ifndef App_Configuration_ArgumentParserTest_H
#define App_Configuration_ArgumentParserTest_H

#include <cppunit/extensions/HelperMacros.h>

#include "App/Configuration/ArgumentParser.h"

using namespace std;
using namespace App::Configuration;

namespace App
{
  namespace Configuration
  {
    class ArgumentParserTest : public CppUnit::TestFixture
    {
      public:

        void setUp();

        void testSanity();
        void testSetFlag();
        void testBadFlag1();
        void testBadFlag2();
        void testCapitalFlag();

        void tearDown();

        CPPUNIT_TEST_SUITE( ArgumentParserTest );

        CPPUNIT_TEST( testSanity );
        CPPUNIT_TEST( testSetFlag );
        CPPUNIT_TEST( testBadFlag1 );
        CPPUNIT_TEST( testBadFlag2 );
        CPPUNIT_TEST( testCapitalFlag );
    
        CPPUNIT_TEST_SUITE_END();

      private:

        ArgumentParser* obj;

    };
  }
}

#endif
