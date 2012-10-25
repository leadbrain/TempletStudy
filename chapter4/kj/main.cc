#include <iostream>
#include "gcd.h"
#include "factorial.h"

void main(int argc, char argv[]) {

	std::cout << "==================== LCM ====================" <<std::endl;
	std::cout << "LCM of 4 and 6 : " << (4*6) / gcd<4, 6>::value << std::endl;
	std::cout << "LCM of 5 and 8 : " << (5*8) / gcd<5, 8>::value << std::endl;
	std::cout << "LCM of 12 and 8 : " << (12*8) / gcd<12, 8>::value << std::endl;

	std::cout << "================= Factorial =================" <<std::endl;
	std::cout << "factorial 3 : " << factorial<3>::value << std::endl;
	std::cout << "factorial 5 : " << factorial<5>::value << std::endl;
	std::cout << "factorial 7 : " << factorial<7>::value << std::endl;
	
}