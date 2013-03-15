template <int N, int M>
class Pow {
public:
	enum { result = M * Pow<N-1, M>::result };
};

template <int M>
class Pow<0, M> {
public:
	enum { result = 1 };
};

template <int DEGREE, typename T>
class SubBCD {
public:
	static T convert(T* a) {
		return *a * Pow<DEGREE, 2>::result + SubBCD<DEGREE-1, T>::convert(a+1);
	}
};

template <typename T>
class SubBCD<0, T> {
public:
	static T convert(T* a) {
		return *a;
	}
};

template <int DIM, typename T>
class BCD {
public:
	static T convert(T* a) {
		return SubBCD<3, int>::convert(a) * Pow<DIM-1, 10>::result + BCD<DIM-1, T>::convert(a+4);
	}
};

template <typename T>
class BCD<1, T> {
public:
	static T convert(T* a) {
		return SubBCD<3, int>::convert(a);
	}
};

int main() {
	int binary[12] = {0,1,1,1,0,1,1,1,0,1,1,1};
	int decimal = BCD<3,int>::convert(binary);
	std::cout<<"decimal : "<<decimal<<"\n";

	return 0;
}