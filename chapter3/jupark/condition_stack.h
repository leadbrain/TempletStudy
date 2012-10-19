#include <vector>
#include "condition.h"
#include <stdexcept>

#ifndef CONDITION_STACK_H_
#define CONDITION_STACK_H_ 1

template <typename Type, typename CONT = Condition<Type> >
class ConditionStack {
private:
  std::vector<Type> elements;
  CONT condition;  

public:
  void Push(Type const& element);
  void Pop();
  Type Top() const;
};

template <typename Type, typename CONT>
void ConditionStack<Type, CONT>::Push(Type const& element) {
  elements.push_back(element);
}

template <typename Type, typename CONT>
void ConditionStack<Type, CONT>::Pop() {
  if (!elements.empty()) {
    condition.SetVector(elements);
    condition.SetElement(elements.back());

    bool exist = condition.Run();

    if (exist) {
      elements.pop_back();
    }
  }
}

template <typename Type, typename CONT>
Type ConditionStack<Type, CONT>::Top() const {
  if (elements.empty()) {
    throw std::out_of_range("ConditionStack<>::Top() : empty stack");
  }

  return elements.back();
}

#endif  // CONDITION_STACK_H_