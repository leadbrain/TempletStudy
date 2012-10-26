#ifndef LCM_H_
#define LCM_H_ 1

#include <vector>

template <typename T, int maxsize>
class CalcLCM {
private:
  std::vector<T> elements;
  int count;

private:  
  int CalcGCD(int num_1, int num_2); 
   
public:
  CalcLCM();
  int Run();
  void Push(T const& element);
  void Pop();
};

template <typename T, int maxsize>
CalcLCM<T, maxsize>::CalcLCM() {
  count = 0;
}

template <typename T, int maxsize>
void CalcLCM<T, maxsize>::Push(T const& element) {
  if (count < maxsize) {
    elements.push_back(element);
    count++;
  }  
}

template <typename T, int maxsize>
void CalcLCM<T, maxsize>::Pop() {
  if (!elements.empty()) {
      elements.pop_back();
      count--;
  }
}

template <typename T, int maxsize>
int CalcLCM<T, maxsize>::Run() {
  int lcm_num = 1;
  int num_1, num_2;
  int gcd = 1;

  std::vector<T>::iterator it_ele = elements.begin();

  num_1 = elements.front();
  it_ele++;

  for(; it_ele != elements.end(); ++it_ele) {
    num_2 = *it_ele;
    gcd = CalcGCD(num_1, num_2);
  }

  lcm_num = num_1 * num_2 / gcd;

  return lcm_num;
}

template <typename T, int maxsize>
int CalcLCM<T, maxsize>::CalcGCD(int num_1, int num_2) {
  int bigger_num, smaller_num, temp_number;

  if (num_1 > num_2) {
    bigger_num = num_1;
    smaller_num = num_2;
  } else {
    bigger_num = num_2;
    smaller_num = num_1;
  }

  while (smaller_num != 0) {
    temp_number = bigger_num - smaller_num;

    if (temp_number > smaller_num) {
      bigger_num = temp_number;
    } else {
      bigger_num = smaller_num;
      smaller_num = temp_number;
    }
  }

  return bigger_num;
}

#endif  // LCM_H