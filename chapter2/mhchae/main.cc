#include <iostream>
#include "func.h"

using namespace std;

int main() {

  cout << "Template Compare Function Test" << endl;

  cout << "1 > 2 = " << func::Compare(1,2) << endl;

  return 0;
}