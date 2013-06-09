#include <iostream>
#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestResult.h"

using namespace std;
using namespace CppUnit;

/**
 * Runs the unit tests in CLI mode printing to the screen.
 * @return success == 0
 */
int runCli()
{
  TextUi::TestRunner runner;
  TestFactoryRegistry &registry = TestFactoryRegistry::getRegistry();
  runner.addTest( registry.makeTest() );
  int returnValue = 1;
  if(runner.run( "", false ))
  {
    returnValue = 0;
  }
  return returnValue;
}

/**
 * Runs the unit tests in XML mode, producing the results in a xml file.
 * @param  outputFile Xml file to place output.
 * @return            0.
 */
int runXml(string outputFile)
{
  TestResult controller;
  TestResultCollector result;
  controller.addListener(&result);

  TextUi::TestRunner runner;
  runner.addTest( TestFactoryRegistry::getRegistry().makeTest() );
  runner.run(controller);

  ofstream xmlFileOut(outputFile.c_str());
  XmlOutputter xmlOut(&result, xmlFileOut);
  xmlOut.write();

  return 0;
}

/**
 * Main function parses command line args and either runs required mode or prints usage information.
 * @param  argc Number of arguments
 * @param  argv Array of arguments
 * @return      success == 0
 */
int main( int argc, char **argv)
{
  int returnValue = 0;

  if(argc == 1)
  {
    returnValue = runCli();
  }
  else if (argc == 2 && string(argv[1]) == "--xml")
  {
    returnValue = runXml(string("cppunit-results.xml"));
  }
  else if (argc == 3 && string(argv[1]) == "--xml")
  {
    returnValue = runXml(argv[2]);
  }
  else
  {
    cout << "Usage: " << argv[0] << " [--xml]" << " [output_file.xml]"<< endl;
    returnValue = 1;
  }
  return returnValue;
}



