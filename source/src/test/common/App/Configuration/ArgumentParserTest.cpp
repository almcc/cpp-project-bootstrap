#include "App/Configuration/ArgumentParserTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ArgumentParserTest );

namespace App
{
  namespace Configuration
  {
    void ArgumentParserTest::setUp()
    {
      this->obj = new ArgumentParser();
    }

    void ArgumentParserTest::testSanity()
    {
      CPPUNIT_ASSERT_EQUAL(true, true);
    }

    void ArgumentParserTest::tearDown()
    {
      delete this->obj;
    }
  }
}
