#include <iostream>

#include "ArgumentParser.h"

using namespace std;

int main(int argc, char *argv[])
{
  ArgumentParser args;
  args.defineAlias("f", "foo");
  args.parse(argc, argv);

  return 0;
}
