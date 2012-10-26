#include <stdio.h>

template <int N>
struct Factorial {
  enum { value = N * Factorial<N -1>::value };
};

template <>
struct Factorial<0> {
  enum { value = 1 };
};

int main(int argc, char* argv[]) {
  printf("Factorial 10 = %d\n", Factorial<10>::value);  // 3628800
  printf("Factorial 20 = %d\n", Factorial<20>::value);  // -2102132736

  return 0;
}

