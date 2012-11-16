
template <typename T>
class InsertionSort {
public:
  static void Run(T* data) {
    int i, j, remember;
    int size_data = data->size();
    for (i = 1; i < (int)size_data; i++) {
      remember = data->at(j=i);
      while ( --j >= 0 && remember < data->at(j)) {
        data->at(j+1) = data->at(j);
      }
      data->at(j+1) = remember;
    }
  }
};

template <typename T>
class BubbleSort {
public:
  static void Run(T* data) {
    int i, j, flag = 1;
    int temp;
    int size_data = data->size();
    for (i = 1; (i <= size_data) && flag; i++) {
      flag = 0;
      for (j = 0; j < (size_data -1); j++) {
        if (data->at(j+1) < data->at(j)) { 
          temp = data->at(j);
          data->at(j) = data->at(j+1);
          data->at(j+1) = temp;
          flag = 1;
        }
      }
    }
  }
};

template <typename T>
class QuickSort {
public:
  static void Run(T* data) {
    Sort(data, 0, data->size() - 1);
  }

private:
  static void Sort(T* data, int left, int right) {
    int pivot, l_hold, r_hold;
    l_hold = left;
    r_hold = right;
    pivot = data->at(left);
    while (left < right) {
      while ((data->at(right) >= pivot) && (left < right))
        right--;
      if (left != right) {
        data->at(left) = data->at(right);
        left++;
      }
      while ((data->at(left) <= pivot) && (left < right))
        left++;
      if (left != right) {
        data->at(right) = data->at(left);
        right--;
      }
    }
    data->at(left) = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
      Sort(data, left, pivot-1);
    if (right > pivot)
      Sort(data, pivot+1, right);
  }
};
