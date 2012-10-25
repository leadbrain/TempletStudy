template<int X, int Y>
struct gcd {
	enum {
		value = gcd<Y, X%Y>::value,
	};
};

template<int X>
struct gcd<X, 0> {
	enum {
		value = X,
	};
};