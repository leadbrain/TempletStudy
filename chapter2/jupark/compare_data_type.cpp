#include <iostream>

template <typename T1, typename T2>
bool compare(T1 const& first, T2 const& second) {  
  if (typeid(T1).name() == typeid(T2).name()) {
    return (first == second);
  } else {
    return false;
  }
}

using namespace std;

int main() {
  int a = 4;
  int b = 4;
  int c = 3;
  double d = 4.0;

  cout << ::compare(a,b) << endl;
  cout << ::compare(a,c) << endl;
  cout << ::compare(a,d) << endl;

  return 0;
}