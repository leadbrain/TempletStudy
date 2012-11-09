/*
 * sort.hpp
 *
 *  Created on: 2012. 11. 5.
 *      Author: duofi_000
 */

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef SORT_HPP_
#define SORT_HPP_

template <typename T>
class BaseSort {
public:
  virtual ~BaseSort() = 0;
  virtual bool Run(T* src, int size) = 0;
};

template <typename T>
BaseSort<T>::~BaseSort() {}

template <typename T>
class InsertionSort : public BaseSort<T> {
public:
  virtual ~InsertionSort() {};
  virtual bool Run(T* src, int size) {
    int i, j;
    T backup;
    for (i = 1; i < size; i++) {
      backup = src[i];
      for (j = i - 1; j >= 0 && src[j] > backup; j--) {
        src[j + 1] = src[j];
      }
      src[j + 1] = backup;
    }

    return true;
  }
};

template <typename T>
class BubbleSort : public BaseSort<T> {
public:
  virtual ~BubbleSort(){};
  virtual bool Run(T* src, int size) {
    int i, j;
    bool is_change = true;

    for (i = size - 1; i > 0 ; i--) {
      if (is_change == true) {
        for (j = 0; j < i; j++) {
          is_change = src[j] > src[j + 1] ? Swap(src[j], src[j + 1]) : false;
        }
      } else {
        return true;
      }
    }
    return true;
  }
private:
  bool Swap(T& lhs, T& rhs) {
    std::swap(lhs, rhs);
    return true;
  }
};

template <typename T>
class QuickSort : public BaseSort<T> {
public:
  virtual ~QuickSort(){};
  virtual bool Run(T* src, int size) {
    if (size > 0) {
      qsort(src, size, sizeof(T), Compare);
      return true;
    } else {
      return false;
    }
  }
private:
  static int Compare(const void *lhs, const void *rhs) {
    return (*(T*)lhs - *(T*)rhs);
  }
};

template <typename T,
  template<typename> class SORTER = QuickSort>
class ArraySorter {
public:
  explicit ArraySorter() : array_(NULL), size_(0) {}
  explicit ArraySorter(T* array, const int& size) :
  array_(array), size_(size) {}

  bool Run() {
    time_t begin_time = clock();
    bool result = sorter.Run(array_, size_);
    elapsed_time = (double)(clock() - begin_time) / CLOCKS_PER_SEC;

    return result;
  }

  void PrintResult(bool print_array = false) {
    if (array_ != NULL) {
      if (print_array == true) {
        printf("-\tSorted Array\t-\n");
        for (int i = 0; i < size_; i++)
          printf("%d ", array_[i]);
      }
      printf("Elapsed Time = %f(sec)\n", elapsed_time);

    } else {
      printf("ERROR: NULL pointer referenced...");
    }
  }

private:
  SORTER<T> sorter;
  T* array_;
  int size_;
  double elapsed_time;

};

template <typename T>
void RandomizeArray(T* array, const int size) 
  int i = 0;
  while (int i = 1; i < size;) {
    array[i] = i++;
  }

  srand(time(NULL));
  for (int i = 0; i < size; ++i) {
    std::swap(array[i], array[(rand() % size)]);
  }
}

#endif /* SORT_HPP_ */
