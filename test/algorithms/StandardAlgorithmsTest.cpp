//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/algorithms/StandardAlgorithms.h"
#include <gtest/gtest.h>
#include "utils/TestUtils.h"

namespace {

using namespace cpptests::core::algorithms;

struct SortFixture : public ::testing::Test
{
    using SortFuncType = std::function<void(int*, int)>;

    void sort(SortFuncType&& sort_func)
    {
        auto test_array = test::create_test_array();
        const auto sorted_array = test::create_sorted_array(test_array);

        sort_func(test_array.data(), test_array.size());

        assert(test_array == sorted_array);
    }
};

TEST_F(SortFixture, BubbleSort)
{
    sort(bubble_sort);
}

TEST_F(SortFixture, SelectionSort)
{
    sort(selection_sort);
}

TEST_F(SortFixture, InsertionSort)
{
    sort(insertion_sort);
}

TEST_F(SortFixture, CountSort)
{
    sort(count_sort);
}

TEST(BinarySearchTest, test)
{
    auto sorted_array = test::create_sorted_array(test::create_test_array());
    const int search_value = sorted_array[static_cast<int>(sorted_array.size()/3)];
    const auto it = std::find(sorted_array.cbegin(), sorted_array.cend(), search_value);
    const int search_position = static_cast<int>(it - sorted_array.cbegin());

    const int test_out = binary_search(sorted_array.data(), sorted_array.size(), search_value);
    assert(test_out == search_position);
}
}
