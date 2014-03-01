#include <iostream>

#include "Release.h"
#include "Logger.h"
#include "Dummy.h"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "Release: " << RELEASE << endl;

  int success = 0;
  Logger logger;
  logger.setLevel(SHOUT);
  logger.logWarning("Hello World");

  Dummy dumb;
  logger.logDebug("My message", &dumb);
  return success;
}

