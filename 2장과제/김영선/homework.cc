//
//  homework.cc
//  chapter2
//
//  Created by Young sun Kim on 12. 10. 12..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#include <iostream>
#include <string>

template <typename T>
bool equal(T const& first, T const& second) {
    return first == second;
}

int main(int argc, const char * argv[]) {
    int a = 42;
    int b = 50;
    std::cout << "equal(a, b) : " << ::equal(a, b) << std::endl;
    std::cout << "equal(a, a) : " << ::equal(a, a) << std::endl;
    
    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "equal(f1, f2) : " << ::equal(f1, f2) << std::endl;
    std::cout << "equal(f1, f1) : " << ::equal(f1, f1) << std::endl;
    
    std::string s1 = "mathmatics";
    std::string s2 = "math";
    std::cout << "equal(s1, s2) : " << ::equal(s1, s2) << std::endl;
    std::cout << "equal(s1, s1) : " << ::equal(s1, s1) << std::endl;
    
    return 0;
}
