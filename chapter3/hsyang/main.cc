#include "condition_stack.h"

int main(void) {
	ConditionStack<int, MaxPopCondition<int> > max_pop_stack;
	max_pop_stack.PushItem(4);
	max_pop_stack.PushItem(5);
	max_pop_stack.PushItem(6);

	max_pop_stack.PopItem();
	std::cout << "Current Top : " << max_pop_stack.GetTopItem() << std::endl;

	ConditionStack<int, MinPopCondition<int> > min_pop_stack;
	min_pop_stack.PushItem(4);
	min_pop_stack.PushItem(5);
	min_pop_stack.PushItem(6);

	min_pop_stack.PopItem();
	std::cout << "Current Top : " << min_pop_stack.GetTopItem() << std::endl;

	return 0;
}