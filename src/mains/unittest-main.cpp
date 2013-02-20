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

int main( int argc, char **argv)
{
  if(argc == 1)
  {
    return runCli();
  }
  else if (argc == 2 && string(argv[1]) == "--xml")
  {
    return runXml(string("cppunit-results.xml"));
  }
  else if (argc == 3 && string(argv[1]) == "--xml")
  {
    return runXml(argv[2]);
  }
  else
  {
    cout << "Usage: " << argv[0] << " [--xml]" << " [output_file.xml]"<< endl;
    return 1;
  }

}



