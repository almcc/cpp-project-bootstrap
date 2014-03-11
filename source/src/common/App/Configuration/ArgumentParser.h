#ifndef App_Configuration_ArgumentParser_H
#define App_Configuration_ArgumentParser_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <set>

#include "App/Configuration/Settings.h"

using namespace std;

namespace App
{
  namespace Configuration
  {
    class ArgumentParser
    {
      friend class ArgumentParserTest;

      public:
        ArgumentParser();
        ~ArgumentParser();

        bool parse(int argc, char *argv[]);

        bool defineOption(string optionName, string defaultValue);

        void exportOptions(Settings* settings);

      private:

        bool parseArg(string arg);
        bool setFlag(string flag);
        bool setOption(string optionValue);

        // set<string> flags;
        // map<string, string> aliases;
        map<string, string> options;
    };
  }
}

#endif
