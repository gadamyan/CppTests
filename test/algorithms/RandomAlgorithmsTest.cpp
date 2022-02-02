//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/algorithms/RandomAlgorithms.h"
#include "core/algorithms/LinkedListAlgorithms.h"
#include "core/algorithms/BinaryTreeAlgorithms.h"
#include "utils/TestUtils.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::algorithms;

TEST(MergeTwoSortedVectorsTest, verify_merged_sorted_vectors)
{
    const auto vec1 = test::createSortedArray(test::createTestVector<30>());
    const auto vec2 = test::createSortedArray(test::createTestVector<40>());

    std::vector<int> mergedVector;
    mergedVector.reserve(vec1.size() + vec2.size());
    mergedVector.insert(mergedVector.end(), vec1.cbegin(), vec1.cend());
    mergedVector.insert(mergedVector.end(), vec2.cbegin(), vec2.cend());
    std::sort(mergedVector.begin(), mergedVector.end());

    const auto result = mergeTwoSortedVectors(vec1, vec2);

    ASSERT_TRUE(test::isEqual(result, mergedVector));
}

TEST(MergeSortedVectorsTest, verify_merged_sorted_vectors)
{
    const auto vec1 = test::createSortedArray(test::createTestVector<30>());
    const auto vec2 = test::createSortedArray(test::createTestVector<40>());
    const auto vec3 = test::createSortedArray(test::createTestVector<50>());

    std::vector<int> mergedVector;
    mergedVector.reserve(vec1.size() + vec2.size());
    mergedVector.insert(mergedVector.end(), vec1.cbegin(), vec1.cend());
    mergedVector.insert(mergedVector.end(), vec2.cbegin(), vec2.cend());
    mergedVector.insert(mergedVector.end(), vec3.cbegin(), vec3.cend());
    std::sort(mergedVector.begin(), mergedVector.end());

    const auto result = mergeSortedVectors(std::vector<std::vector<int>>{vec1, vec2, vec3});

    ASSERT_TRUE(test::isEqual(result, mergedVector));
}

TEST(ReverseLinkedListTest, check_the_values_of_the_reversed_link_list)
{
    const auto testVector = test::createTestVector<30>();
    auto reversedVector = testVector;
    std::reverse(reversedVector.begin(), reversedVector.end());
    auto root = createLinkedList(testVector);

    const auto reversedRoot = reverseLinkedList(root);

    const auto result = createVectorFromLinkedList(reversedRoot);
    ASSERT_TRUE(test::isEqual(result, reversedVector));
}

TEST(ReverseBinaryTreeTest, check_the_values_of_the_reversed_binary_tree)
{
    const auto testVector = test::createSortedArray(test::createTestVector());
    auto root = createTreeFromVector(testVector);

    root = reverseBinaryTree(root);

    auto reversedVector = testVector;
    std::reverse(reversedVector.begin(), reversedVector.end());

    auto result = createVectorFromTree(root);
    ASSERT_TRUE(test::isEqual(result, reversedVector));
}

TEST(RegexTest, verify_filered_words)
{
    const std::string inputText("fasd , adsfads,... adsfads ,,adfa ,a, adsf");
    const std::vector<std::string> expectedResult {"fasd", "adsfads", "adsfads", "adfa", "a", "adsf"};
    auto words = filerWords(inputText);
    ASSERT_TRUE(test::isEqual(words, expectedResult));
}

TEST(IntConversionTest, verify_converted_integer)
{
    ASSERT_EQ(convertToInt("1111", 4), 1111);
}

struct FibonacciFixture : public ::testing::Test
{
    using FibonacciFuncType = std::function<int(int)>;

    void fibonacci(FibonacciFuncType&& fibonacciFunc) {
        const std::vector<int> fibSequence {1, 1, 2, 3, 5, 8, 13, 21};
        for (int i = 0; i < fibSequence.size(); ++i) {
            ASSERT_EQ(fibonacciFunc(i), fibSequence[i]);
        }
    }
};

TEST_F(FibonacciFixture, check_recursive_fibonacci_value)
{
    fibonacci(getFibonacciRecursive);
}

TEST_F(FibonacciFixture, check_iterative_fibonacci_value)
{
    fibonacci(getFibonacciIterative);
}
}
