#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stdio.h>


#include "statck4.hpp"

template<typename T, int VAl>
T AddValue(T const& x) {
  return x + VAl;
}

int main() {

  std::vector<int> source, dest;    

  source.push_back(1);
  source.push_back(2);
  source.push_back(3);
  source.push_back(4);

  dest.resize(source.size());

  /*std::transform(source.begin(), source.end(),
    dest.begin(), AddValue<int, 5>);*/

  std::transform(source.begin(), source.end(),
    dest.begin(), (int(*)(int const&))AddValue<int, 1>);

  for (int i = 0; i < source.size(); i++) {
    std::cout << dest[i] << std::endl;
  }  
  

}