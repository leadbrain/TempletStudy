#include <cstdio>
#include <stack>
#include <functional>
#include <boost/lambda/lambda.hpp>

struct LogicalTrue: public std::unary_function<int, bool> {
  bool operator() (int value) { 
    return true;
  }
};

template<typename T, typename Condition = LogicalTrue>
//template<typename T, typename Condition = boost::lambda::constant(true)>
//template<typename T, typename Condition = std::bind1st(std::less<int>(), 5) >
class ConditionStack: public std::stack<T> {
public:
  typedef std::stack<T> BaseType;

public:
  void pop() {
    if(condition_(BaseType::top())) {
      BaseType::pop();
    }
  }

private:
  Condition condition_;
};

int main(int argc, char* argv[]) {
  ConditionStack<int> stack;

  for(int i = 0; i <= 10; i++) {
    stack.push(i);
  }
  for(int i = 0; i <= 10; i++) {
    printf("Top: %d\n", stack.top());
    stack.pop();
  }

  return 0;
}
