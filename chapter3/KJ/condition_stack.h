#include <vector>

template <typename T>
class Condition {
public:
	bool Empty(const T *element) const;
};

template <typename T>
bool Condition<T>::Empty(const T *element) const {
	return element->empty();
}

template <typename T, typename C = Condition<std::vector<T> > >
class ConditionStack {
public:
	void Push(const T elem);
	T Top() const;
	void Pop();
private:
	std::vector<T> element;
	C cond;
};

template <typename T, typename C>
void ConditionStack<T>::Push(const T elem) {
	element.push_back(elem);
}

template <typename T, typename C>
T ConditionStack<T>::Top() const {
	if (cond.Empty(&element))
		return NULL;
	else
		return element.back();
}

template <typename T, typename C>
void ConditionStack<T>::Pop() {
	if (!cond.Empty(&element))
		element.pop_back();
}

