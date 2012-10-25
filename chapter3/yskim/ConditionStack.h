//
//  ConditionStack.h
//  chapter3
//
//  Created by Young sun Kim on 12. 10. 26..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#ifndef chapter3_ConditionStack_h
#define chapter3_ConditionStack_h

#include <vector>

template <typename Type, typename Condition>
class ConditionStack {
private:
    std::vector<Type> items_;
public:
    void Push(Type item) {
        items_.push_back(item);
    };
    
    Type Top() const {
        size_t size = items_.size();
        if (size == 0) {
            return Type();
        }
        return items_.at(size-1);
    };
    
    void Pop() {
        typename std::vector<Type>::iterator it_item = items_.end();
        for (; it_item != items_.begin(); it_item--) {
            if (Condition::IsPop(*it_item)) {
                items_.erase(it_item);
                break;
            }
        }
    };
};

#endif
