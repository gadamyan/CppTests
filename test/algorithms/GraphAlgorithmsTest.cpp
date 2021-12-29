//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/algorithms/GraphAlgorithms.h"
#include "utils/TestUtils.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::algorithms;

TEST(DijkstraGraphTest, verify_the_global_access_of_the_singleton)
{
//    const auto vec1 = test::create_sorted_array(test::create_test_vector<30>());
//    const auto vec2 = test::create_sorted_array(test::create_test_vector<40>());
//
//    std::vector<int> merged_vector;
//    merged_vector.reserve(vec1.size() + vec2.size());
//    merged_vector.insert(merged_vector.end(), vec1.cbegin(), vec1.cend());
//    merged_vector.insert(merged_vector.end(), vec2.cbegin(), vec2.cend());
//    std::sort(merged_vector.begin(), merged_vector.end());
//
//    const auto result = merge_two_sorted_vectors(vec1, vec2);
//
//    ASSERT_TRUE(test::is_equal(result, merged_vector));
}
}
