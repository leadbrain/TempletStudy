#include <stdio.h>

template<typename T>
bool compare(const T& first, const T& second) {
  if (first == second) {
    return true;
  }
  return false;
}

void main(int argc, char* argv[]) {
  int foo = 1;
  int bar = 1;
  printf("compare return: %d\n", compare(foo, bar));

  char foo_char = 'a';
  char bar_char = 'b';
  printf("compare return: %d\n", compare(foo_char, bar_char));

  printf("compare return: %d\n", compare(foo, static_cast<int>(bar_char)));
}
