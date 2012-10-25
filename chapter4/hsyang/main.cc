#include <iostream>
#include "math_template.h"


int main()
{
	Factorial<5> f;
	int factorial_result = f.GetResult();
	std::cout << "factorial_result(5) : " << factorial_result << std::endl;

	LCM<5, 13> l;
	int lcm_result = l.GetResult();
	std::cout << "lcm_result(5, 13) : " << lcm_result << std::endl;

    return 0;
}
