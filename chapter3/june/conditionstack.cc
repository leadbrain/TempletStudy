#include <stdio.h>
#include <vector>
#include "conditionstack.h"

void main(int argc, char* argv[]) {

  ConditionStack<double, Condition<double>> test;
  test.Push(10.0);
  test.Push(11.0);
  test.Push(12.0);
  test.Push(13.0);
  double val = test.Top();
  bool result = test.Pop();

  ConditionStack<double> test2;

  test2.Push(15.0);
  test2.Push(-15.0);
  bool result2 = test2.Pop();
  return;
}

