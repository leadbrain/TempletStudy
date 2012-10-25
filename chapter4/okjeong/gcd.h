#ifndef __GCD_H__
#define __GCD_H__


template <int A, int B>
struct Gcd {
  static const int value = Gcd<B, A % B>::value;
};

template <int A>
struct Gcd<A, 0> {
  static const int value = A;
};


#endif //__GCD_H__
