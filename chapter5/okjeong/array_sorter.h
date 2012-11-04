#ifndef __ARRAY_SORTER_H__
#define __ARRAY_SORTER_H__


#include <algorithm>


template <class T>
class QuickSort {
public:
  void operator()(T* array, int size) {
    std::sort(array, array + size);
  }
};

template <class T, template <typename> class S = QuickSort>
class ArraySorter {
public:
  bool SortArray(T* array, int size) {
    S<T> sort_algorithm;
    sort_algorithm(array, size);
    return true;
  }
};


#endif //__ARRAY_SORTER_H__
