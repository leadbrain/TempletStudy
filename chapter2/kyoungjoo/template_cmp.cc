#include <stdio.h>

template <typename T>
bool cmp(const T& var1, const T& var2){
	if (var1 == var2) {
		return true;
	} else {
		return false;
	}
}

void main() {
	int a=1;
	int b=5;

	if (cmp(a, b) == true) {
		printf("%d and %d is equal\n", a, b);
	} else {
		printf("%d and %d is not equal\n", a, b);
	}
	return;

}