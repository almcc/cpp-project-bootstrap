#include <iostream>
#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestResult.h"

using namespace std;
using namespace CppUnit;

int runCli()
{
  TextUi::TestRunner runner;
  TestFactoryRegistry &registry = TestFactoryRegistry::getRegistry();
  runner.addTest( registry.makeTest() );
  bool wasSucessful = runner.run( "", false );
  return wasSucessful;

}

int runXml()
{
  TestResult controller;
  TestResultCollector result;
  controller.addListener(&result);

  TextUi::TestRunner runner;
  runner.addTest( TestFactoryRegistry::getRegistry().makeTest() );
  runner.run(controller);

  ofstream xmlFileOut("cppunit-results.xml");
  XmlOutputter xmlOut(&result, xmlFileOut);
  xmlOut.write();

  return 0;
}

int main( int argc, char **argv)
{
  if(argc == 1)
  {
    return runCli();
  }
  else if (argc == 2 && string(argv[1]) == "--xml")
  {
    return runXml();
  }
  else
  {
    cout << "Usage: " << argv[0] << " [--xml]" << endl;
    return 1;
  }

}



