#include "array_sorter.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include <Windows.h>


template <class T>
class InsertionSort {
public:
  void operator()(T* array, int size) {
    int i, j;
    T insert_value;

    for (i = 1; i < size; i++) {
      insert_value = array[i];
      for (j = i - 1; j >= 0 ; j--) {
        if (array[j] < insert_value) {
          break;
        }
        array[j + 1] = array[j];
      }
      array[j + 1] = insert_value;
    }
  }
};

template <class T>
class BubbleSort {
public:
  void operator()(T* array, int size) {
    int i, j, sorted = 0;
    T temp;

    for (i = 0; i < size - 1; i++) {
      for (j = 1; j < size; j++) {
        if (array[j - 1] > array[j]) {
          temp = array[j - 1];
          array[j - 1] = array[j];
          array[j] = temp;
        }
      }
    }
  }
};


void MakeTestArray(int* array, int size) {
  srand(time(NULL));

  int i;
  for (i = 0; i < size; i++) {
    array[i] = rand();
  }
}

template <class T>
bool CheckSorted(T* array, int size) {
  int i;
  for (i = 1; i < size; i++) {
    if (array[i - 1] > array[i]) {
      return false;
    }
  }
  return true;
}

int main(int agrc, char* argv[]) {
  const int kTestSize = 50000;

  int* original_array = new int[kTestSize];
  int* copied_array = new int[kTestSize];

  DWORD begin, default;

  MakeTestArray(original_array, kTestSize);

  memcpy(copied_array, original_array, sizeof(int) * kTestSize);
  ArraySorter<int> default_sorter;
  begin = GetTickCount();
  default_sorter.SortArray(copied_array, kTestSize);
  printf("default = %d\n", GetTickCount() - begin);
  assert(CheckSorted(copied_array, kTestSize));

  memcpy(copied_array, original_array, sizeof(int) * kTestSize);
  ArraySorter<int, InsertionSort> insertion_sorter;
  begin = GetTickCount();
  insertion_sorter.SortArray(copied_array, kTestSize);
  printf("insertion = %d\n", GetTickCount() - begin);
  assert(CheckSorted(copied_array, kTestSize));

  memcpy(copied_array, original_array, sizeof(int) * kTestSize);
  ArraySorter<int, BubbleSort> bubble_sorter;
  begin = GetTickCount();
  bubble_sorter.SortArray(copied_array, kTestSize);
  printf("bubble = %d\n", GetTickCount() - begin);
  assert(CheckSorted(copied_array, kTestSize));

  delete[] original_array;
  delete[] copied_array;

  return 0;
}
