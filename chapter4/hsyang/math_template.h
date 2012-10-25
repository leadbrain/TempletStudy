template <int N>
class Factorial {
public:
	Factorial() {
		Factorial<N-1> sub_factorial;
		this->number_ = N * sub_factorial.GetResult();
	}

	inline int GetResult() {
		return number_;
	}

private:
	int number_;
};

template <>
class Factorial<1> {
public:
	Factorial() : number_(1) {}

	inline int GetResult() {
		return number_;
	}

private:
	int number_;
};

template <int N1, int N2>
class GCD {
public:
	GCD() {
		GCD<N2, N1 % N2> sub_gcd;
		number_ = sub_gcd.GetResult();
	}

	inline int GetResult() {
		return number_;
	}

private:
	int number_;
};

template <int N1>
class GCD <N1, 0> {
public:
	GCD() : number_(N1) {}

	inline int GetResult() {
		return number_;
	}

private:
	int number_;
};

template <int N1, int N2>
class LCM {
public:
	LCM() {
		GCD<N1, N2> sub_gcd;
		int gcd_result = sub_gcd.GetResult();
		number_ = N1 * N2 / gcd_result;
	}

	inline int GetResult() {
		return number_;
	}

private:
	int number_;
};