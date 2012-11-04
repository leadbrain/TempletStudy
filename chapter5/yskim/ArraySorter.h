//
//  ArraySorter.h
//  chapter5
//
//  Created by Young sun Kim on 12. 11. 4..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#ifndef chapter5_ArraySorter_h
#define chapter5_ArraySorter_h

#include<algorithm>

template<typename TYPE>
class InsertionSort {
public:
    void operator()(TYPE* target_array, int n) {
		int i, j;
		TYPE key;
		for (i = 1; i < n; i++) {
			key = target_array[i];
			for (j = i-1; j >= 0 && target_array[j] > key; j--)
				target_array[j+1] = target_array[j];
			target_array[j+1] = key;
		}
	}
};

template<typename TYPE>
class BubbleSort {
public:
	void operator()(TYPE* target_array,int n) {
		int i, j;
		for (i = n-1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (target_array[j] > target_array[j+1]) {
					TYPE temp = target_array[j];
					target_array[j] = target_array[j+1];
					target_array[j+1] = temp;
				}
			}
		}
	}
};

template <typename TYPE>
class QuickSort {
public:
    void operator ()(TYPE* array, int size) {
        std::sort(array, array + size);
    }
};

template <typename TYPE,
  template <typename> class SORTER = QuickSort>
class ArraySorter {
public:
    void SortArray(TYPE* array, int size) {
        SORTER<TYPE> Sorter;
        Sorter(array, size);
    }
};


#endif
