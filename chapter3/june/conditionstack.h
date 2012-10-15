/*!
 *      @date   2012/10/15
 *      @file   conditionstack.h
 *      @author jskim
 *
 *      Copyright   2012 by DIOTEK Co.,LTD. All rights reserved.
 */

#ifndef _CONDITION_STACK_
#define _CONDITION_STACK_ 1;

template<typename T, typename C = Condition<T>>
class ConditionStack {
public:
  void Push(const T&);
  const T& Top();
  bool Pop();

private:
  std::vector<T> elems;
};

template<typename T, typename C>
inline void ConditionStack<T, C>::Push(const T& x) {
  elems.push_back(x);
}

template<typename T, typename C>
inline const T& ConditionStack<T, C>::Top() {
  return elems.back();
}

template<typename T, typename C>
inline bool ConditionStack<T, C>::Pop() {
  if (elems.empty() == true || C::Pop(elems.back()) == false)
    return false;
  elems.pop_back();
  return true;
}

template<typename T>
class Condition {
public:
  static bool Pop(const T& x) {
    if (x < 0)
      return true;
    return false;
  }
};

#endif // _CONDITION_STACK_
