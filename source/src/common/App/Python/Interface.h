#ifndef App_Python_Interface_H
#define App_Python_Interface_H

#include <string>
#include <vector>

using namespace std;

class Interface
{
  friend class InterfaceTest;

  public:
    Interface();
    ~Interface();

    int add(int a, int b);

  private:


};

#endif
