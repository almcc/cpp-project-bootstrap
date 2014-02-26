#include "ArgumentParser.h"

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

bool ArgumentParser::defineAlias(string alias, string actual)
{
  this->aliases.insert(make_pair(alias, actual));
  return true;
}

bool ArgumentParser::isFlag(string flag)
{
  bool success = false;
  set<string>::iterator it;
  it = this->flags.find(flag);
  if(it != this->flags.end())
  {
    success = true;
  }
  return success;
}

bool ArgumentParser::isOption(string option)
{
  bool success = false;
  if(this->getOption(option) != "")
  {
    success = true;
  }
  return success;
}

string ArgumentParser::getOption(string option)
{
  string value = "";

  map<string,string>::iterator it;
  it = this->options.find(option);
  if(it != this->options.end())
  {
    value = it->second;
  }

  return value;
}

bool ArgumentParser::parseArg(string arg)
{
  bool success = false;

  string alias = "-";
  string flag = "--";
  string option = "=";

  std::size_t aliasPos = arg.find(alias);
  std::size_t flagPos = arg.find(flag);
  std::size_t optionPos = arg.find(option);

  bool aliasFound = aliasPos!=std::string::npos;
  bool flagFound = flagPos!=std::string::npos;
  bool optionFound = optionPos!=std::string::npos;

  if( aliasFound && !flagFound && !optionFound )
  {
    success = this->setAlias(arg);
  }
  else if( aliasFound && flagFound && !optionFound )
  {
    success = this->setFlag(arg);
  }
  else if( !aliasFound && !flagFound && optionFound )
  {
    success = this->setOption(arg);
  }

  return success;
}

bool ArgumentParser::setAlias(string alias)
{
  bool success = false;
  alias = alias.substr(1,alias.length());

  if(alias.length() != 1)
  {
    this->setAlias(alias.substr(1,alias.length()));
    alias = alias = alias.substr(0,1);
  }

  map<string,string>::iterator it;
  it = this->aliases.find(alias);
  if(it != this->aliases.end())
  {
    this->flags.insert(it->second);
    success = true;
  }
  return success;

}

bool ArgumentParser::setFlag(string flag)
{
  bool success = true;
  flag = flag.substr(2,flag.length());
  this->flags.insert(flag);
  return success;
}

bool ArgumentParser::setOption(string optionValue)
{
  bool success = true;
  string option = optionValue.substr(0,optionValue.find("="));
  string value = optionValue.substr(optionValue.find("=")+1,optionValue.length());

  this->options.insert(make_pair(option, value));

  return success;
}


