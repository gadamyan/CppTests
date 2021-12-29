//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <algorithm>
#include <vector>
#include <regex>
#include <iostream>

namespace cpptests::core::algorithms {

inline std::vector<int> merge_two_sorted_vectors(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
    const auto size = vec1.size() + vec2.size();
    std::vector<int> result(size);
    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i < size; ++i)
    {
        if (counter1 == vec1.size()) {
            result[i] = vec2[counter2++];
        }
        else if (counter2 == vec2.size()) {
            result[i] = vec1[counter1++];
        }
        else if (vec1[counter1] < vec2[counter2]) {
            result[i] = vec1[counter1++];
        }
        else {
            result[i] = vec2[counter2++];
        }
    }
    return result;
}

int get_fibonacci_recursive(int number)
{
    if (number < 2) {
        return 1;
    }
    return get_fibonacci_recursive(number - 1) + get_fibonacci_recursive(number - 2);
}

int get_fibonacci_iterative(int number)
{
    if (number < 2) {
        return 1;
    }
    int first = 1;
    int second = 1;
    for (int i = 0; i < number - 1; ++i) {
        int temp = second;
        second += first;
        first = temp;
    }
    return second;
}

    void fileFilter()
    {
        std::string inputText("fasd , adsfads,... adsfads ,,adfa ,a, adsf");
        const std::regex regex("\\w+");
        const std::sregex_iterator itBegin(inputText.cbegin(), inputText.cend(), regex);
        const std::sregex_iterator itEnd;
        for (auto it = itBegin; it != itEnd; ++it)
        {
            std::cout << it->str() << " ";
        }
        std::cout << std::endl << std::distance(itBegin, itEnd) << std::endl;
    }

    void mergeSortedVectors()
    {
        const std::vector<int> firstVector = { 1, 4, 6, 7, 9, 11 };
        const std::vector<int> seconsdVector = { 1, 4, 5, 6, 7, 9, 11, 12, 15 };
        const std::vector<int> thirdVector = { 2, 3, 5, 7, 9 };
        const std::vector<std::vector<int>> inputVectors = { firstVector, seconsdVector, thirdVector };

        const size_t inputVectorsSize = inputVectors.size();
        size_t allElementsSize = 0;
        std::vector<size_t> vectorsPointers(inputVectorsSize, 0);

        for (const auto& item : inputVectors)
        {
            allElementsSize += item.size();
        }

        std::vector<int> outputVector(allElementsSize, 0);
        for (int i = 0; i < allElementsSize; ++i)
        {
            int min = std::numeric_limits<int>::max();
            size_t indexOfMin = 0;
            for (int j = 0; j < inputVectorsSize; ++j)
            {
                const size_t pos = vectorsPointers[j];
                const auto& currentVector = inputVectors[j];
                if (pos < currentVector.size() && currentVector[pos] < min)
                {
                    indexOfMin = j;
                    min = currentVector[pos];
                }
            }
            outputVector[i] = min;
            ++vectorsPointers[indexOfMin];
        }

        for (const int item : outputVector)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

}
