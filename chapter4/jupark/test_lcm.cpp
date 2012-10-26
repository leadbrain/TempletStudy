#include <iostream>

#include "lcm.h"

int main() {
  CalcLCM<int, 2> test_1;
  test_1.Push(6);
  test_1.Push(9);

  std::cout << test_1.Run() << std::endl;

  return 0;
}