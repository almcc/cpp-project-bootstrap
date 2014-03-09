#include "App/Logging/Message.h"

namespace App
{
  namespace Logging
  {
    Message::Message()
    {

    }

    Message::~Message()
    {

    }

    string Message::getType()
    {
      return this->type;
    }
    string Message::getDescription()
    {
      return this->description;
    }
    string Message::getTime()
    {
      return this->time;
    }
    string Message::getMessage()
    {
      return this->message;
    }

    void Message::setType(string type)
    {
      this->type = type;
    }
    void Message::setTime(string time)
    {
      this->time = time;
    }
    void Message::setMessage(string message)
    {
      this->message = message;
    }
    void Message::setDescription(string description)
    {
      this->description = description;
    }
  }
}