#ifndef ARGUMENT_PARSER_TEST_H
#define ARGUMENT_PARSER_TEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "ArgumentParser.h"

using namespace std;

class ArgumentParserTest : public CppUnit::TestFixture
{
  public:

    void setUp();

    void testSanity();
    void testSetFlag();
    void testBadFlag1();
    void testBadFlag2();
    void testCapitalFlag();
    //NEXT_TEST_DEC

    void tearDown();

    CPPUNIT_TEST_SUITE( ArgumentParserTest );

    CPPUNIT_TEST( testSanity );
    CPPUNIT_TEST( testSetFlag );
    CPPUNIT_TEST( testBadFlag1 );
    CPPUNIT_TEST( testBadFlag2 );
    CPPUNIT_TEST( testCapitalFlag );
    //NEXT_TEST_ADD

    CPPUNIT_TEST_SUITE_END();

  private:

    ArgumentParser* obj;

};

#endif
