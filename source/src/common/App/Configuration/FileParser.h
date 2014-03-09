#ifndef App_Logging_FileParser_h
#define App_Logging_FileParser_h

#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

#include "App/Configuration/Settings.h"

using namespace std;

namespace App
{
  namespace Configuration
  {
    class FileParser
    {
      friend class FileParserTest;

      public:
        FileParser();
        ~FileParser();

        bool parse(string filename, Settings* settings);

      private:

        bool parseLine(string line, Settings* settings);
    };
  }
}

#endif
