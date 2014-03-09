#include "App/Configuration/FileParser.h"

namespace App
{
  namespace Configuration
  {
    FileParser::FileParser()
    {

    }

    FileParser::~FileParser()
    {

    }

    bool FileParser::parse(string filename, Settings* settings)
    {
      bool success = true;
      string line;
      ifstream myfile(filename.c_str());
      if (myfile.is_open())
      {
        while (getline(myfile, line))
        {
          this->parseLine(line, settings);
        }
        myfile.close();
      }
      else
      {
        success = false;
      }
      return success;
    }

    bool FileParser::parseLine(string line, Settings* settings)
    {
      string delimiter = "=";
      string key = line.substr(0, line.find(delimiter));
      string value = line.substr(line.find(delimiter)+delimiter.size(), line.size());

      boost::algorithm::trim(key);
      boost::algorithm::trim(value);

      settings->set(key, value);
      return true;
    }
  }
}
