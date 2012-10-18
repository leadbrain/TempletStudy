#ifndef __CONDITIONSTACK_H__
#define __CONDITIONSTACK_H__

#include <stack>

struct AlwaysRemove {
  bool operator()() {
    return true;
  }
};

template <typename T, typename Condition = AlwaysRemove>
class ConditionStack : public std::stack<T> {
public:
  typedef std::stack<T> BaseType;
  typedef Condition ConditionType;

  void pop();

private:
  ConditionType condition_;
};

template <typename T, typename Condition>
void ConditionStack<T, Condition>::pop() {
  if (condition_() == true) {
    BaseType::pop();
  }
}

#endif //__CONDITIONSTACK_H__
