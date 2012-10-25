template<int X>
struct factorial {
	enum {
		value = X * factorial<X-1>::value,
	};
};

template<>
struct factorial<0> {
	enum {
		value = 0,
	};
};

template <>
struct factorial<1> {
	enum {
		value = 1,
	};
};