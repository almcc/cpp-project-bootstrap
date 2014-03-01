#ifndef Logger_h
#define Logger_h

#include <iostream>
#include <sstream>

#include "Loggable.h"
#include "LogMessage.h"

using namespace std;

enum LogLevel
{
    WISPER,
    QUIET,
    NORMAL,
    LOUD,
    SHOUT
};

enum LogType
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
    void setLevel(LogLevel level);

    // Public usage functions
    void logFatel(string message);
    void logError(string message);
    void logDanger(string message);
    void logWarning(string message);
    void logSuccess(string message);
    void logInformation(string message);
    void logDebug(string message);
    void logDebug(string message, Loggable* object);

  private:
    // Private functions
    void log(LogType type, string message);
    void distribute(LogMessage* message);
    void print(LogMessage* message);
    void store(LogMessage* message);
    void publish(LogMessage* message);

    string currentDateTime();
    string getLogType(LogType type);
    LogLevel translateTypeToLevel(LogType type);

    // Private members
    LogLevel level;

    // Static Private members
    static string separator;

};

#endif
