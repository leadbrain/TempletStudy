#include <vector>

#ifndef CONDITION_H_
#define CONDITION_H_ 1

template <typename Type>
class Condition {
  std::vector<Type> elements_;
  Type& element_;
  
public:
  bool Run();
  void SetVector(std::vector<Type> elements);
  void SetElement(Type& element);
};

template <typename Type>
bool Condition<Type>::Run() {
  bool exist = false;

  while(!elements_.empty()) {
    if (elements_.back() == element_) {
      exist = true;
      break;
    } else {
      elements_.pop_back();
    }
  }

  return exist;
}

template <typename Type>
void Condition<Type>::SetVector(std::vector<Type> elements) {
  elements_.clear();
  elements_ = elements;
}

template <typename Type>
void Condition<Type>::SetElement(Type& element) {
  element_ = element;
}

#endif  // CONDITION_H_