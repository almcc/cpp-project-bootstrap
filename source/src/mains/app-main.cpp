#include "App/Logging/Logger.h"
#include "App/Configuration/ArgumentParser.h"

using namespace App::Logging;
using namespace App::Configuration;

/**
 * Main
 * @param  argc
 * @param  argv
 * @return
 */
int main( int argc, char **argv)
{
  int returnValue = 0;
  ArgumentParser parser;
  parser.parse(argc, argv);

  Logger log;
  log.logError("Error message here.");
  return returnValue;
}