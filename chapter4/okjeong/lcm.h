#ifndef __LCM_H__
#define __LCM_H__

#include "gcd.h"

template <int A, int B>
struct Lcm {
  static const int value = A * B / Gcd<A, B>::value;
};


#endif //__LCM_H__
