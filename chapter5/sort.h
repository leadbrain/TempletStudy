template<class T>
class InsertionSort {
public:
	void Sort(T* target_array, int n) {
		int i, j;
		T key;
		for (i = 1; i < n; i++) {
			key = target_array[i];
			for (j = i-1; j >= 0 && target_array[j] > key; j--)
				target_array[j+1] = target_array[j];
			target_array[j+1] = key;
		}
	}
};

template<class T>
class BubbleSort {
public:
	void Sort(T* target_array,int n) {
		int i, j;
		for (i = n-1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (target_array[j] > target_array[j+1]) {
					T temp = target_array[j];
					target_array[j] = target_array[j+1];
					target_array[j+1] = temp;
				}
			}
		}
	}
};

template<class T>
class QuickSort {
public:
	void Sort(T* target_array, int n) {
		int left = 0;
		int right = n - 1;
       
		Sort(target_array, left, right);
	}

private: 
	void Sort(T* target_array, int left, int right) {
		if (left < right) {
			int q = Partition(target_array, left, right);
			Sort(target_array, left, q-1);
			Sort(target_array, q+1, right);
		}
	}

	int Partition(T* target_array, int left, int right) {
		int pivot;
		T temp;
		int low, high;
		low = left;
		high = right + 1;
		pivot = target_array[left];
		do {
			do {
				low++;
			} while (low <= right && target_array[low] < pivot);
			do {
				high--;
			} while (high >= left && target_array[high] > pivot);
			if (low < high) {
				temp = target_array[low];
				target_array[low] = target_array[high];
				target_array[high] = temp;
			}
		} while (low < high);
		temp = target_array[left];
		target_array[left] = target_array[high];
		target_array[high] = temp;
		return high;
	}
};

template<class T, 
	template <class> class SORTTYPE = QuickSort>
class ArraySorter {
public:
	void SortArray(T* target_array, int n) {
		sort_algorithm.Sort(target_array, n);
	}

private:
	SORTTYPE<T> sort_algorithm;
};