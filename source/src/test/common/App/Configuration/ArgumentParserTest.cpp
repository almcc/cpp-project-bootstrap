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

    void ArgumentParserTest::testSetFlag()
    {
      this->obj->defineAlias("f", "foo");
      bool actual = true;
      bool expected = this->obj->parseArg("-f");
      CPPUNIT_ASSERT_EQUAL(expected, actual);
    }

    void ArgumentParserTest::testBadFlag1()
    {
      this->obj->defineAlias("f", "foo");
      bool actual = false;
      bool expected = this->obj->parseArg("f");
      CPPUNIT_ASSERT_EQUAL(expected, actual);
    }

    void ArgumentParserTest::testBadFlag2()
    {
      bool actual = false;
      bool expected = this->obj->parseArg("-f");
      CPPUNIT_ASSERT_EQUAL(expected, actual);
    }

    void ArgumentParserTest::testCapitalFlag()
    {
      this->obj->defineAlias("F", "foo");
      bool actual = true;
      bool expected = this->obj->parseArg("-F");
      CPPUNIT_ASSERT_EQUAL(expected, actual);
    }

    void ArgumentParserTest::tearDown()
    {
      delete this->obj;
    }
  }
}
