#ifndef App_Logging_Message_h
#define App_Logging_Message_h

#include <iostream>
#include <sstream>

using namespace std;

namespace App
{
  namespace Logging
  {
    class Message
    {
      friend class MessageTest;
      public:
        Message();
        ~Message();

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
  }
}

#endif
