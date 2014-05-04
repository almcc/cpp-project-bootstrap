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
    /**
     * Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod
     * tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam,
     * quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.
     */
    class ArgumentParserTest : public CppUnit::TestFixture
    {
      public:

        void setUp();

        /**
         * Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod
         */
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
