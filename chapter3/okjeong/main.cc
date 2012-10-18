#include "condition_stack.h"

#include <assert.h>


struct HalfRemove {

  HalfRemove() : flag(false) {}

  bool operator()() {
    bool result = false;
    if (flag == true) {
      flag = false;
      result = true;
    } else {
      flag = true;
      result = false;
    }
    return result;
  }

private:
  bool flag;
};


int main(int argc, char* argv[]) {
  typedef ConditionStack<int, HalfRemove> CustomStack;
  typedef ConditionStack<int> NormalStack;

  CustomStack::ConditionType condition;

  CustomStack custom_stack;
  NormalStack normal_stack;

  custom_stack.push(3);
  custom_stack.push(4);
  custom_stack.pop();
  custom_stack.pop();

  assert(custom_stack.top() == 3);

  normal_stack.push(4);
  normal_stack.pop();

  assert(normal_stack.empty() == true);

  return 0;
}
