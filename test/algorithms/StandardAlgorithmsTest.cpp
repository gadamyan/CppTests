//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/algorithms/StandardAlgorithms.h"
#include <gtest/gtest.h>
#include "utils/TestUtils.h"

namespace {

using namespace cpptests::core::algorithms;

struct SortFixture : public ::testing::Test
{
    using SortFuncType = std::function<void(int*, int)>;

    static void sort(SortFuncType&& sortFunc) {
        auto testArray = test::createTestArray();
        const auto sorted_array = test::createSortedArray(testArray);

        sortFunc(testArray.data(), testArray.size());

        ASSERT_EQ(testArray, sorted_array);
    }
};

TEST_F(SortFixture, validate_bubble_sort)
{
    sort(bubbleSort);
}

TEST_F(SortFixture, validate_selection_sort)
{
    sort(selectionSort);
}

TEST_F(SortFixture, validate_insertion_sort)
{
    sort(insertionSort);
}

TEST_F(SortFixture, validate_count_sort)
{
    sort(countSort);
}

TEST(BinarySearchTest, validate_binary_search)
{
    auto sortedArray = test::createSortedArray(test::createTestArray());
    const int searchValue = sortedArray[static_cast<int>(sortedArray.size() / 3)];
    const auto it = std::find(sortedArray.cbegin(), sortedArray.cend(), searchValue);
    const int searchPosition = static_cast<int>(it - sortedArray.cbegin());

    const int testOut = binarySearch(sortedArray.data(), sortedArray.size(), searchValue);
    ASSERT_EQ(testOut, searchPosition);
}
}
