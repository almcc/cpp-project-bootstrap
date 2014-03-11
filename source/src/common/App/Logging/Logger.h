#ifndef App_Logging_Logger_h
#define App_Logging_Logger_h

#include <iostream>
#include <sstream>

#include "App/Logging/Message.h"

using namespace std;

namespace App
{
  namespace Logging
  {
    enum Level
    {
      WISPER,
      QUIET,
      NORMAL,
      LOUD,
      SHOUT
    };

    enum Type
    {
      FATEL,
      ERROR,
      DANGER,
      WARNING,
      SUCCESS,
      INFORMATION,
      DEBUG,
    };

    class Logger
    {
      friend class LoggerTest;

      public:
        Logger();
        ~Logger();

        // Public setup functions
        void setLevel(Level level);
        void setLevel(string level);

        // Public usage functions
        void logFatel(string message);
        void logError(string message);
        void logDanger(string message);
        void logWarning(string message);
        void logSuccess(string message);
        void logInformation(string message);
        void logDebug(string message);

      private:
        // Private functions
        void log(Type type, string message);
        void distribute(Message* message);
        void print(Message* message);
        void store(Message* message);
        void publish(Message* message);

        string currentDateTime();
        string getLogType(Type type);
        Level translateTypeToLevel(Type type);

        // Private members
        Level level;

        // Static Private members
        static string separator;

    };
  }
}

#endif
