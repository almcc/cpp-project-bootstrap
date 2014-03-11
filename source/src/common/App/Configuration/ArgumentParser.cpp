#include "App/Configuration/ArgumentParser.h"

namespace App
{
  namespace Configuration
  {
    ArgumentParser::ArgumentParser()
    {

    }

    ArgumentParser::~ArgumentParser()
    {

    }

    bool ArgumentParser::parse(int argc, char *argv[])
    {
      bool success = true;
      if(argc > 1)
      {
        int i=1;
        while(i<argc && success)
        {
          stringstream arg;
          arg << argv[i];
          success = this->parseArg(arg.str());
          ++i;
        }
      }
      return success;
    }

    bool ArgumentParser::defineOption(string optionName, string defaultValue)
    {
      this->options.insert(make_pair(optionName, defaultValue));
      return true;
    }

    void ArgumentParser::exportOptions(Settings* settings)
    {
      std::map<std::string, std::string>::iterator it;
      for (it = this->options.begin(); it != this->options.end(); ++it)
      {
        settings->set(it->first, it->second);
      }
    }

    bool ArgumentParser::parseArg(string arg)
    {
      bool success = false;

      string flag = "--";
      string option = "=";

      std::size_t flagPos = arg.find(flag);
      std::size_t optionPos = arg.find(option);

      bool flagFound = flagPos!=std::string::npos;
      bool optionFound = optionPos!=std::string::npos;

      if( flagFound && !optionFound )
      {
        success = this->setFlag(arg);
      }
      else if( flagFound && optionFound )
      {
        success = this->setOption(arg);
      }

      return success;
    }

    /**
     * A flag is just an option that will default to a value of TRUE.
     * @param  flag [description]
     * @return      [description]
     */
    bool ArgumentParser::setFlag(string flag)
    {
      bool success = false;
      flag = flag.substr(2,flag.length());

      map<string,string>::iterator it;
      it = this->options.find(flag);
      if(it != this->options.end())
      {
        it->second = "TRUE";
        success = true;
      }

      return success;
    }

    bool ArgumentParser::setOption(string optionValue)
    {
      bool success = false;
      string option = optionValue.substr(2, optionValue.find("=")-2);
      string value = optionValue.substr(optionValue.find("=")+1, optionValue.length());

      map<string,string>::iterator it;
      it = this->options.find(option);
      if(it != this->options.end())
      {
        it->second = value;
        success = true;
      }

      return success;
    }
  }
}