//
//  main.cpp
//  chapter4
//
//  Created by Young sun Kim on 12. 10. 26..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#include "gtest/gtest.h"
#include "Factorial.h"

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(FactorealTest, test) {
    Factorial<10> ten_factorial;
    EXPECT_EQ(3628800, ten_factorial.GetFactorial());
    Factorial<5> five_factorial;
    EXPECT_EQ(120, five_factorial.GetFactorial());
}

