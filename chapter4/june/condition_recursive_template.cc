#include <stdio.h>

template <int X, int Y, int C>
struct LCMCondition {
  enum {
    value = C % X == 0 && C % Y == 0
  }; 
};

template <int X, int Y, int C = 1, bool cond = 0> 
struct LCM {
  enum {
    value = C, 
  }; 
};

template <int X, int Y, int C>
struct LCM<X, Y, C, 0> {
  enum {
    value = LCM<X, Y, C + 1, LCMCondition<X, Y, C + 1>::value>::value
  };
};

template<int X> 
struct Factorial {
  enum {
    value = X * Factorial<X - 1>::value, 
  }; 
};

template<> 
struct Factorial<1> {
  enum {
    value = 1
  }; 
};

int main() {
  int success_factorial = Factorial<10>::value;
  int success_lcm = LCM<24, 34>::value;

  //int fail_factorial = Factorial<10000>::value;
  //int fail_lcm = LCM<50, 34>::value;
  return 0;
}
