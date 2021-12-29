//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <array>
#include <vector>
#include <random>

namespace test {

template <size_t size = 30>
decltype(auto) create_test_array()
{
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(1, 20);

    std::array<int, size> test_array;
    for (auto& item : test_array)
    {
        item = distribution(generator);
    }
    return test_array;
}

template <size_t size = 30>
decltype(auto) create_test_vector()
{
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(1, 20);

    std::vector<int> test_array(size);
    for (auto& item : test_array)
    {
        item = distribution(generator);
    }
    return test_array;
}

template <typename T>
T create_sorted_array(const T& test_array)
{
    auto sorted_array = test_array;
    std::sort(sorted_array.begin(), sorted_array.end());
    return sorted_array;
}

template <typename T>
bool is_equal(const std::vector<T>& vector1, const std::vector<T>& vector2)
{
    return std::equal(vector1.cbegin(), vector1.cend(), vector2.cbegin(), vector2.cend());
}

}
