#ifndef Dummy_h
#define Dummy_h

#include <iostream>

#include "Loggable.h"

using namespace std;

class Dummy : public Loggable
{
  public:
    Dummy();
    ~Dummy();
    string log();
};

#endif
