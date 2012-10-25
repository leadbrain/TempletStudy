//
//  main.cpp
//  chapter3
//
//  Created by Young sun Kim on 12. 10. 19..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//
#include "gtest/gtest.h"
#include "ConditionStack.h"
#include <string>

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CondithonStackTest, IntTest) {
    class Condition {
    public:
        static bool IsPop(int item) {
            return item > 0;
        }
    };
    
    ConditionStack<int, Condition> condition_stack;
    
    condition_stack.Push(1);
    EXPECT_EQ(1, condition_stack.Top());
    condition_stack.Push(-1);
    EXPECT_EQ(-1, condition_stack.Top());
    condition_stack.Pop();
    EXPECT_EQ(-1, condition_stack.Top());
}

TEST(CondithonStackTest, StringTest) {
    class Condition {
    public:
        static bool IsPop(std::string item) {
            return item.length() > 5;
        }
    };
    ConditionStack<std::string, Condition> stack;
    std::string first = "aaaaa";
    std::string second = "bbb";
    stack.Push("aaaaa");
    EXPECT_TRUE(first.compare(stack.Top()));
    stack.Push("bbb");
    EXPECT_TRUE(second.compare(stack.Top()));
    stack.Pop();
    EXPECT_TRUE(second.compare(stack.Top()));
}

