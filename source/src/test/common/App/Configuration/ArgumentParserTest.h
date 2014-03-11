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

        void tearDown();

        CPPUNIT_TEST_SUITE( ArgumentParserTest );

        CPPUNIT_TEST( testSanity );

        CPPUNIT_TEST_SUITE_END();

      private:

        ArgumentParser* obj;

    };
  }
}

#endif
