#ifndef __FACTORIAL_H__
#define __FACTORIAL_H__


template <int N>
struct Factorial {
  static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
  static const int value = 1;
};


#endif //__FACTORIAL_H__
