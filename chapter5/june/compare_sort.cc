#include "sort.h"
#include <stdio.h>
#include <time.h> 
#include <vector>

template <typename T, template <typename> class ALGORITHM>
class ArraySorter {
public:
  typedef T DataType;

public:
  void operator() (T* data) const {
    ALGORITHM<T>::Run(data);
  }
};

template <class SORTER>
void CaculateAlgoritmTime(const int size_data, const char* title, const SORTER& sorter) {
  SORTER::DataType data(size_data, 0);
  for (int i = 0 ; i < size_data; i++)
    data.at(i) = size_data - i;

  clock_t start = clock();
  sorter(&data);
  clock_t cost = clock() - start;
  printf("%s : %d msec\n", title, cost);
};

int main() {
  typedef std::vector<int> DataType;
  static const int kDataSize = 50000;

  CaculateAlgoritmTime(kDataSize, "Quick Sort", ArraySorter<DataType, QuickSort>());
  CaculateAlgoritmTime(kDataSize, "Bubble Sort", ArraySorter<DataType, BubbleSort>());
  CaculateAlgoritmTime(kDataSize, "Insertion Sort", ArraySorter<DataType, InsertionSort>());
  return 0;
}