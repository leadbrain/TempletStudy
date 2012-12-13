#include <stdio.h>
#include "caculate_funtions.h"


int main() {
  float result_sum = sum(1.0, 4);
  int result_multi = multi(3, 4.7);

  printf("Sum float result : %f\n", result_sum);
  printf("Multi int result : %d\n", result_multi);

  return 0;
}