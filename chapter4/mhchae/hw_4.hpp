template <int NUM>
class Factorial {
public:
  enum {
    result = NUM * Factorial<NUM - 1>::result
  };
};

template<>
class Factorial<0> {
public:
  enum {
    result = 1
  };
};

template <int X, int Y>
struct GCD {
  enum {
    result = GCD<Y, X % Y>::result
  };
};

template <int X>
struct GCD<X, 0> {
  enum {
    result = X
  };
};

template <int X, int Y>
struct LCM {
  enum {
    result = X * Y / GCD<X, Y>::result 
  };
};


