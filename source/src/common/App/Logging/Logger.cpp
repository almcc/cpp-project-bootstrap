#include "App/Logging/Logger.h"

namespace App
{
  namespace Logging
  {
    string Logger::separator = " - ";

    Logger::Logger()
    {
      this->level = WISPER;
    }

    Logger::~Logger()
    {

    }

    void Logger::setLevel(Level level)
    {
      this->level = level;
    }

    void Logger::logFatel(string message)
    {
      this->log(FATEL, message);
    }

    void Logger::logError(string message)
    {
      this->log(ERROR, message);
    }

    void Logger::logDanger(string message)
    {
      this->log(DANGER, message);
    }

    void Logger::logWarning(string message)
    {
      this->log(WARNING, message);
    }

    void Logger::logSuccess(string message)
    {
      this->log(SUCCESS, message);
    }

    void Logger::logInformation(string message)
    {
      this->log(INFORMATION, message);
    }

    void Logger::logDebug(string message)
    {
      this->log(DEBUG, message);
    }

    void Logger::log(Type type, string message)
    {
      if(this->translateTypeToLevel(type) <= this->level)
      {
        Message logMsg;
        logMsg.setType(this->getLogType(type));
        logMsg.setTime(currentDateTime());
        logMsg.setMessage(message);
        this->distribute(&logMsg);
      }
    }

    void Logger::distribute(Message* message)
    {
      this->print(message);
      this->store(message);
      this->publish(message);
    }
    void Logger::print(Message* message)
    {
      cout << message->getTime() <<
              this->separator <<
              message->getType() <<
              this->separator <<
              message->getMessage() <<
              endl;
    }

    void Logger::store(Message* message)
    {

    }

    void Logger::publish(Message* message)
    {

    }

    string Logger::currentDateTime()
    {
      time_t     now = time(0);
      struct tm  tstruct;
      char       buf[80];
      tstruct = *localtime(&now);
      strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
      return buf;
    }

    string Logger::getLogType(Type type)
    {
      string typeStr;
      switch (type)
      {
        case FATEL:
          typeStr = "FATEL";
          break;
        case ERROR:
          typeStr = "ERROR";
          break;
        case DANGER:
          typeStr = "DANGER";
          break;
        case WARNING:
          typeStr = "WARNING";
          break;
        case SUCCESS:
          typeStr = "SUCCESS";
          break;
        case INFORMATION:
          typeStr = "INFORMATION";
          break;
        case DEBUG:
          typeStr = "DEBUG";
          break;
        default:
          typeStr = "UNKNOWN";
      }
      return typeStr;
    }

    Level Logger::translateTypeToLevel(Type type)
    {
      Level level;
      switch (type)
      {
        case FATEL:
          level = WISPER;
          break;
        case ERROR:
          level = WISPER;
          break;
        case DANGER:
          level = QUIET;
          break;
        case WARNING:
          level = NORMAL;
          break;
        case SUCCESS:
          level = NORMAL;
          break;
        case INFORMATION:
          level = LOUD;
          break;
        case DEBUG:
          level = SHOUT;
          break;
        default:
          level = SHOUT;
      }
      return level;
    }
  }
}