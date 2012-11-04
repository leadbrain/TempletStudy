//
//  main.cpp
//  chapter5
//
//  Created by Young sun Kim on 12. 11. 4..
//  Copyright (c) 2012년 Young sun Kim. All rights reserved.
//

#include "gtest/gtest.h"
#include "ArraySorter.h"
#include "stdlib.h"

#define ARRAY_SIZE 100000

int array_a[ARRAY_SIZE];
float array_b[ARRAY_SIZE];
double array_c[ARRAY_SIZE];

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    int array_count = 0;
    
    while (array_count < ARRAY_SIZE) {
        int num = rand() % ARRAY_SIZE;
        array_a[array_count] = num;
        array_b[array_count] = num;
        array_c[array_count] = num;
        array_count++;

    }
    return RUN_ALL_TESTS();
}

TEST(ArraySortTest, quick_sort_test) {
    ArraySorter<int> sorter;
    sorter.SortArray(array_a, ARRAY_SIZE);
}

TEST(ArraySortTest, bubble_sort_test) {
    ArraySorter<float, BubbleSort> sorter;
    sorter.SortArray(array_b, ARRAY_SIZE);
}

TEST(ArraySortTest, insertion_sort_test) {
    ArraySorter<double, InsertionSort> sorter;
    sorter.SortArray(array_c, ARRAY_SIZE);
}

TEST(ArraySortTest, result_test) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        EXPECT_EQ(array_a[i], array_b[i]);
        EXPECT_EQ(array_a[i], array_c[i]);
    }
}

