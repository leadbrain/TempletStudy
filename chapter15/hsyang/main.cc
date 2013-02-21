template<bool C, typename Ta, typename Tb>
class IfThenElse;

template<typename Ta, typename Tb>
class IfThenElse<true, Ta, Tb> {
public:
	typedef Ta ResultT;
};

template<typename Ta, typename Tb>
class IfThenElse<false, Ta, Tb> {
public:
	typedef Tb ResultT;
};

template<typename T1, typename T2>
class Promotion {
public:
	typedef typename
		IfThenElse<(sizeof(T1) > sizeof(T2)), 
		T1, 
		             typename IfThenElse<(sizeof(T1) < sizeof(T2)), 
					 T2, 
					 void
					 >::ResultT
					 >::ResultT ResultT;
};

template <typename T>
class Promotion<T, T> {
public:
    typedef T ResultT;
};

template <typename RESULT, typename T1, typename T2>
class SumPolicy {
public:
	static RESULT compute(T1 t1, T2 t2) {
		return t1 + t2;
	}
};

template <typename T1, typename T2,
	      template<typename, typename, typename> class POLICY = SumPolicy>
class Calculator {
public:
	typedef typename Promotion<T1, T2>::ResultT ResultT;
	static ResultT compute(T1 t1, T2 t2) {
		return POLICY<ResultT, T1, T2>::compute(t1, t2);
	}
};

int main() {
	int a = 4;
	double b = 2.0;
	double result = Calculator<int, double>::compute(a, b);

	return 0;
}