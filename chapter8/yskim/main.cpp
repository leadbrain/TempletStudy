//
//  main.cpp
//  chapter8
//
//  Created by Young sun Kim on 12. 12. 14..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#include <string>
#include "gtest/gtest.h"
#include "Calculator.h"

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CalculatorTest, test) {
    int result = Calculator<1, 2>::result;
    EXPECT_EQ(3, result);
    result = Calculator<2, 1, Sub>::result;
    EXPECT_EQ(1, result);
    result = Calculator<2, 2, Mul>::result;
    EXPECT_EQ(4, result);
    result = Calculator<1, 0, Div>::result;
    EXPECT_EQ(1, result);
}

