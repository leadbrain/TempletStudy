
template<bool c, typename Ta, typename Tb>
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
  typedef typename IfThenElse<(sizeof(T1) > sizeof(T2)), T1,
    typename IfThenElse<(sizeof(T1) < sizeof(T2)), T2, void>::ResultT>::ResultT ResultT;
};

template<typename T>
class Promotion<T, T> {
public:
  typedef T ResultT;
};

template <typename RESULT, typename T1, typename T2>
class SumPolicy {
public:
    static RESULT compute(T1 t1, T2 t2) { // RESULT는 T1과 T2중에 큰 자료형
        return t1 + t2;
    }
}; // 정책 클래스


template <typename T1, typename T2,
  template<typename, typename, typename> class Policy = SumPolicy,
  typename Traits = Promotion<T1, T2> >
class Calculator {
public:
  typedef typename Traits::ResultT ResultT;

  static ResultT calculate(T1 a, T2 b) {
    return Policy<ResultT, T1, T2>::compute(a, b);
  }
};

int main() {
    int a = 4;
    double b = 2.0;
    double result = Calculator<int, double>::calculate(a, b); // Default Policy = SumPolicy
    // double result = Calculator<int, double, SumPolicy>::calculate(a, b);

    return 0;
}

