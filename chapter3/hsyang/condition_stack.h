#include <vector>
#include <iostream>

template<typename T, typename Condition = ConditionRemainSmall<T> >
class ConditionStack {
public:
	void PushItem(T item) {
		items.push_back(item);
	}

	T GetTopItem() {
		return items.back();
	}

	void PopItem() {
		std::vector<T>::iterator it_item = items.begin();
		T top_item = GetTopItem();

		for(; it_item != (items.end()-1); ++it_item) {
			bool result_condition = condition.is_pop_item(top_item, *it_item);
			if (!result_condition) 
				return;
		}

		items.pop_back();
	}

private:
	std::vector<T> items;
	Condition condition;
};

template<typename T>
class MaxPopCondition {
public:
	bool is_pop_item(T target_item, T other_item) {
		return target_item > other_item;
	}
};

template<typename T>
class MinPopCondition {
public:
	bool is_pop_item(T target_item, T other_item) {
		return target_item < other_item;
	}
};

