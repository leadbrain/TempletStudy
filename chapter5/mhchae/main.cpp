//============================================================================
// Name        : hw_5.cpp
// Author      : mhchae
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "sort.hpp"

enum {
  kArraySize = 100000
};

int main() {
  int shook_array[kArraySize] = {};
  RandomizeArray(shook_array, kArraySize);

  ArraySorter<int, QuickSort> sorter(shook_array, kArraySize);
  sorter.Run();
  sorter.PrintResult();

  return 0;
}
