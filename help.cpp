#include "help.h"

std::string IntToString ( int number )
{
  std::ostringstream oss;
  oss<< number;
  return oss.str();
}
