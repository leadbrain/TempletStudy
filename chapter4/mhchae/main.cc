#include <iostream>
#include "hw_4.hpp"

using namespace std;

int main() {

  cout << "4! = " << Factorial<4>::result << endl;
  cout << "GCD(12, 18) = " << GCD<12, 18>::result << endl;
  cout << "GCD(17, 11) = " << LCM<17, 11>::result << endl;

}