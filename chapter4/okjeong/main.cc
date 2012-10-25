#include <iostream>

#include "factorial.h"
#include "lcm.h"


int main(int argc, char* argv[]) {
  //factorial
  const int kFactorialN = 8;
  std::cout << "Factorial<" << kFactorialN << "> = ";
  std::cout << Factorial<kFactorialN>::value << std::endl;

  //LCM
  const int kLcmLeft = 25;
  const int kLcmRight = 82;
  std::cout << "LCM " << kLcmLeft << ", " << kLcmRight << " = ";
  std::cout << Lcm<kLcmLeft, kLcmRight>::value << std::endl;

  return 0;
}
