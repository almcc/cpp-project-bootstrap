#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <iostream>
#include <pthread.h>

using namespace std;

class Singleton{

public:

   static Singleton* Instance();
   virtual ~Singleton();

private:

   Singleton();
   static Singleton* instance;

};

#endif
