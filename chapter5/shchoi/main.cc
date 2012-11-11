#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

template <class T>
class QuickSort {
public:
	template <class IteratorType>
	void operator() (IteratorType begin, IteratorType end) {
		std::sort(begin, end);
	}
};

template <class T>
class MergeSort {
public:
	template <class IteratorType>
	void operator() (IteratorType begin, IteratorType end) {
		std::stable_sort(begin, end);
	}
};

template <class T, template <class> class A = QuickSort>
class Sorter {
public:
	typedef A<T> AlgorithmType;

public:
	template <class IteratorType>
	void operator() (IteratorType begin, IteratorType end) {
		sorter_(begin, end);
	}

private:
	AlgorithmType sorter_;
};

int main(void) {
#if 1
	int data[] = { 3, 4, 5, 6, 7, 1, 2 };
	int size_data = sizeof(data) / sizeof(int);
#else
	const int size_data = 100000;
	int data[size_data];
	for (int i = 0; i < size_data; i++) {
		data[i] = rand() % size_data;
	}
#endif
	struct timespec tp1, tp2;

	Sorter<int> qsorter;
	std::vector<int> qsort_array(data, data + size_data);
	clock_gettime(CLOCK_REALTIME, &tp1);
	qsorter(qsort_array.begin(), qsort_array.end());
	clock_gettime(CLOCK_REALTIME, &tp2);
	printf("%ld.%ld\n", tp2.tv_sec - tp1.tv_sec, tp2.tv_nsec - tp1.tv_nsec);

	Sorter<int, MergeSort> merge_sorter;
	std::vector<int> merge_array(data, data + size_data);
	clock_gettime(CLOCK_REALTIME, &tp1);
	merge_sorter(merge_array.begin(), merge_array.end());
	clock_gettime(CLOCK_REALTIME, &tp2);
	printf("%ld.%ld\n", tp2.tv_sec - tp1.tv_sec, tp2.tv_nsec - tp1.tv_nsec);

	return EXIT_SUCCESS;
}
