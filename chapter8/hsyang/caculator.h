template <class T>
class Sum {
public:
  T Calculate(T a, T b) {
    return a + b;
  }

};

template <class T>
class Multi {
public:
  T Calculate(T a, T b) {
    return a * b;
  }
};

template <class T>
class Minus {
public:
  T Calculate(T a, T b) {
    return a - b;
  }
};

template <class T>
class Division {
public:
  T Calculate(T a, T b) {
    if (static_cast<T>(0)) {
      return a;
    }
    return a / b;
  }
};

template <class T1, class T2>
class TypeConverter {
public:
  T1 GetConvertedValue(T2 value) {
    return static_cast<T1>(value);
  }
};

template <class T,
  template <class> class METHOD = Sum>
class Calculator {
public:
  T Run(T a, T b) {
    T result = T();

    result += method_.Calculate(a, b);
    return result;
  }

  template<class T, class OTHER>
  T Run(T a, OTHER b) {
    T result = T();
    TypeConverter<T, OTHER> converter;
    T converted_a = converter.GetConvertedValue(b);

    result += method_.Calculate(a, b);
    return result;
  }

private:
  METHOD<T> method_;
};

template class Calculator<float, Sum>;
template class Calculator<int, Multi>;
