#include "caculator.h"

template <class T1, class T2> 
T1 sum(T1 a, T2 b) {
  Calculator<T1, Sum> sum_runner;
  return sum_runner.Run(a, b);
}

template <class T>
T sum(T a, T b) {
  Calculator<T, Sum> sum_runner;
  return sum_runner.Run(a, b);
}

template <class T1, class T2> 
T1 minus(T1 a, T2 b) {
  Calculator<T1, Minus> minus_runner;
  return minus_runner.Run(a, b);
}

template <class T>
T minus(T a, T b) {
  Calculator<T, Minus> minus_runner;
  return minus_runner.Run(a, b);
}

template <class T1, class T2> 
T1 multi(T1 a, T2 b) {
  Calculator<T1, Multi> multi_runner;
  return multi_runner.Run(a, b);
}

template <class T>
T multi(T a, T b) {
  Calculator<T, Multi> multi_runner;
  return multi_runner.Run(a, b);
}

template <class T1, class T2> 
T1 devision(T1 a, T2 b) {
  Calculator<T1, Division> division_runner;
  return division.Run(a, b);
}

template <class T>
T devision(T a, T b) {
  Calculator<T, Division> division_runner;
  return division.Run(a, b);
}
