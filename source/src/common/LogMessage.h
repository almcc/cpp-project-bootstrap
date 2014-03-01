#ifndef LogMessage_h
#define LogMessage_h

#include <iostream>
#include <sstream>

using namespace std;

class LogMessage
{
  friend class LogMessageTest;
  public:
    LogMessage();
    ~LogMessage();

    string getType();
    string getDescription();
    string getTime();
    string getMessage();

    void setType(string type);
    void setTime(string time);
    void setMessage(string message);
    void setDescription(string description);

  private:
    string type;
    string time;
    string message;
    string description;
};

#endif
