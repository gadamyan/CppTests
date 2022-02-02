//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <array>
#include <vector>
#include <random>

namespace test {

template <size_t Size = 30>
decltype(auto) createTestArray() {
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(1, 20);

    std::array<int, Size> testArray;
    for (auto& item : testArray) {
        item = distribution(generator);
    }
    return testArray;
}

template <size_t Size = 30>
decltype(auto) createTestVector() {
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distribution(1, 20);

    std::vector<int> testArray(Size);
    for (auto& item : testArray) {
        item = distribution(generator);
    }
    return testArray;
}

template <typename T>
T createSortedArray(const T& testArray) {
    auto sortedArray = testArray;
    std::sort(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}

template <typename T>
bool isEqual(const std::vector<T>& vector1, const std::vector<T>& vector2) {
    return std::equal(vector1.cbegin(), vector1.cend(), vector2.cbegin(), vector2.cend());
}

}
