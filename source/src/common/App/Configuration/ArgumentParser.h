#ifndef ArgumentParser_H
#define ArgumentParser_H

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <set>

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
        bool defineAlias(string alias, string actual);

        bool isFlag(string flag);
        bool isOption(string option);
        string getOption(string option);

      private:

        bool parseArg(string arg);
        bool setAlias(string alias);
        bool setFlag(string flag);
        bool setOption(string optionValue);

        set<string> flags;
        map<string, string> aliases;
        map<string, string> options;
    };
  }
}

#endif
