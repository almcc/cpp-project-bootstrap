#include "App/Configuration/Settings.h"

namespace App
{
  namespace Configuration
  {
    Settings::Settings()
    {

    }

    Settings::~Settings()
    {

    }

    void Settings::set(string key, string value)
    {
      this->settings.insert(make_pair(key, value));
    }

    string Settings::get(string key)
    {
      string value = "";
      map<string,string>::iterator it;
      it = this->settings.find(key);
      if(it != this->settings.end())
      {
        value = it->second;
      }
      return value;
    }
  }
}
