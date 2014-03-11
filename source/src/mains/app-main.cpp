#include "App/Logging/Logger.h"
#include "App/Configuration/FileParser.h"
#include "App/Configuration/ArgumentParser.h"
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

  // Load settings from a file.
  FileParser fparser;
  fparser.parse("/etc/app/settings.txt", &settings);

  // Overide settings with the command line.
  ArgumentParser aparser;
  aparser.defineOption("LOG_FILE", "/var/log/app/app.log");
  aparser.defineOption("LOG_LEVEL", "NORMAL");
  aparser.parse(argc, argv);
  aparser.exportOptions(&settings);

  Logger log;
  log.setLevel(settings.get("LOG_LEVEL"));
  log.logSuccess("Setting Loaded.");

  log.logInformation("Exiting.");
  return returnValue;
}