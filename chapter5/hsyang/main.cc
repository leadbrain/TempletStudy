#include <time.h> 
#include <iostream>
#include "sort.h"

#define ARRAY_SIZE 30000

void init_test_array(int* test_array, int size) {
	for (int i = 0 ; i < size; i++) {
		test_array[i] = size - i;
	}
}

int main() {
	int test_array[ARRAY_SIZE];

	// insrtion sort
	init_test_array(test_array, ARRAY_SIZE);
	ArraySorter<int, InsertionSort> insertion_sort;
	clock_t start_time = clock();
	insertion_sort.SortArray(test_array, ARRAY_SIZE);
	clock_t finish_time = clock();
	std::cout << "Insertion sort : " << (finish_time-start_time)/CLOCKS_PER_SEC << " sec" << std::endl; 

	// bubble sort
	init_test_array(test_array, ARRAY_SIZE);
	ArraySorter<int, BubbleSort> bubble_sort;
	start_time = clock();
	bubble_sort.SortArray(test_array, ARRAY_SIZE);
	finish_time = clock();
	std::cout << "Bubble sort : " << (finish_time-start_time)/CLOCKS_PER_SEC << " sec"  << std::endl; 

	// quick sort
	init_test_array(test_array, ARRAY_SIZE);
	ArraySorter<int> quick_sort; // default : quick sort
	start_time = clock();
	quick_sort.SortArray(test_array, ARRAY_SIZE);
	finish_time = clock();
	std::cout << "Quick sort : " << (finish_time-start_time)/CLOCKS_PER_SEC << " sec"  << std::endl;

	return 0;
}