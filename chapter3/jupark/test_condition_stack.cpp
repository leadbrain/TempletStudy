#include <iostream>
#include <cstdlib>

#include "condition.h"
#include "condition_stack.h"

int main() {
  try {
    ConditionStack<int> int_condition_stack;

    int_condition_stack.Push(3);
    int_condition_stack.Push(4);
    int_condition_stack.Push(5);
    int_condition_stack.Push(4);
    std::cout << int_condition_stack.Top() << std::endl;

    int_condition_stack.Pop();
    std::cout << int_condition_stack.Top() << std::endl;

    int_condition_stack.Pop();
    std::cout << int_condition_stack.Top() << std::endl;
  } catch (std::exception const& ex) {
    std::cerr << "Exception: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  };

  return 0;
}