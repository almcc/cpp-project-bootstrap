#include "LogMessage.h"

namespace App
{
  namespace Logging
  {
    LogMessage::LogMessage()
    {

    }

    LogMessage::~LogMessage()
    {

    }

    string LogMessage::getType()
    {
      return this->type;
    }
    string LogMessage::getDescription()
    {
      return this->description;
    }
    string LogMessage::getTime()
    {
      return this->time;
    }
    string LogMessage::getMessage()
    {
      return this->message;
    }

    void LogMessage::setType(string type)
    {
      this->type = type;
    }
    void LogMessage::setTime(string time)
    {
      this->time = time;
    }
    void LogMessage::setMessage(string message)
    {
      this->message = message;
    }
    void LogMessage::setDescription(string description)
    {
      this->description = description;
    }
  }
}