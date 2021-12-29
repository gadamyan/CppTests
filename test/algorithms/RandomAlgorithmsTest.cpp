//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/algorithms/RandomAlgorithms.h"
#include "core/algorithms/LinkedList.h"
#include "core/algorithms/BinaryTree.h"
#include "utils/TestUtils.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::algorithms;

TEST(MergeTwoSortedVectorsTest, verify_the_global_access_of_the_singleton)
{
    const auto vec1 = test::create_sorted_array(test::create_test_vector<30>());
    const auto vec2 = test::create_sorted_array(test::create_test_vector<40>());

    std::vector<int> merged_vector;
    merged_vector.reserve(vec1.size() + vec2.size());
    merged_vector.insert(merged_vector.end(), vec1.cbegin(), vec1.cend());
    merged_vector.insert(merged_vector.end(), vec2.cbegin(), vec2.cend());
    std::sort(merged_vector.begin(), merged_vector.end());

    const auto result = merge_two_sorted_vectors(vec1, vec2);

    ASSERT_TRUE(test::is_equal(result, merged_vector));
}

TEST(ReverseLinkedListTest, verify_the_global_access_of_the_singleton)
{
    const auto test_vector = test::create_test_vector<30>();
    auto reversed_vector = test_vector;
    std::reverse(reversed_vector.begin(), reversed_vector.end());
    auto root = create_linked_list(test_vector);

    const auto reversed_root = reverse_linked_list(root);

    const auto result = create_vector_from_linked_list(reversed_root);
    assert(test::is_equal(result, reversed_vector));
}


TEST(ReverseBinaryTreeTest, verify_the_global_access_of_the_singleton)
{
    const auto test_vector = test::create_sorted_array(test::create_test_vector());
    auto root = create_tree_from_vector(test_vector);

    root = reverse_binary_tree(root);

    auto reversed_vector = test_vector;
    std::reverse(reversed_vector.begin(), reversed_vector.end());

    auto result = create_vector_from_tree(root);
    assert(test::is_equal(result, reversed_vector));
}

struct FibonacciFixture : public ::testing::Test
{
    using FibonacciFuncType = std::function<int(int)>;

    void fibonacci(FibonacciFuncType&& fibonacci_func)
    {
        const std::vector<int> fib_sequence { 1, 1, 2, 3, 5, 8, 13, 21 };
        for (int i = 0; i < fib_sequence.size(); ++i)
        {
            ASSERT_EQ(fibonacci_func(i), fib_sequence[i]);
        }
    }
};

TEST_F(FibonacciFixture, RecursiveFibonacciTest)
{
    fibonacci(get_fibonacci_recursive);
}

TEST_F(FibonacciFixture, IterativeFibonacciTest)
{
    fibonacci(get_fibonacci_iterative);
}
}
