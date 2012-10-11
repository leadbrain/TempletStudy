#include <stdio.h>

template <typename T1, typename T2>
bool compare(T1 a, T2 b) {
	/* Type size check */
	int size_t1 = sizeof(T1);
	int size_t2 = sizeof(T2);

	if (size_t1 != size_t2) {
		return false;
	}

	/* Type value check */
	char test_value = 1;
	T1 t1_value = test_value;
	T2 t2_value = test_value;

	char* p_byte_t1 = (char*)(&t1_value);
	char* p_byte_t2 = (char*)(&t2_value);

	for (int i = 0; i < 4; i++) {
		if(*(p_byte_t1) != *(p_byte_t2)) {
			return false;
		}
	}

	/* Unsigned check */
	char test_unsigned = -1;
	t1_value = test_unsigned;
	t2_value = test_unsigned;

	bool is_a_not_unsinged = (t1_value < 0)? true:false;
	bool is_b_not_unsigned = (t2_value < 0)? true:false;
	
	if (is_a_not_unsinged != is_b_not_unsigned) {
		return false;
	}

	/* Value compare */
	if (a != b) {
		return false;
	}

	return true;
}

int main(void) {
	int a = 4;
	int b = 5;

	bool result = compare(a, b);

	printf("Compare result : %d\n", result);

	return 0;
}