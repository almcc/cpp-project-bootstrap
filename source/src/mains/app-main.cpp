#include "App/Logging/Logger.h"
#include "App/Configuration/FileParser.h"
#include "App/Configuration/Settings.h"

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

  Settings settings;

  FileParser parser;
  parser.parse("/etc/app/settings.txt", &settings);

  cout << settings.get("LOG_FILE") << endl;
  cout << settings.get("LOG_LEVEL") << endl;
  cout << settings.get("NONSENCE") << endl;

  Logger log;
  log.logError("Error message here.");
  return returnValue;
}