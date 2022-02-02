//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <algorithm>
#include <vector>
#include <regex>

namespace cpptests::core::algorithms {

template <typename T>
std::vector<T> mergeTwoSortedVectors(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    const auto size = vec1.size() + vec2.size();
    std::vector<T> result(size);
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < size; ++i) {
        if (index1 == vec1.size()) {
            result[i] = vec2[index2++];
        } else if (index2 == vec2.size()) {
            result[i] = vec1[index1++];
        } else {
            result[i] = vec1[index1] < vec2[index2] ? vec1[index1++] : vec2[index2++];
        }
    }
    return result;
}

int getFibonacciRecursive(int number) {
    if (number < 2) {
        return 1;
    }
    return getFibonacciRecursive(number - 1) + getFibonacciRecursive(number - 2);
}

int getFibonacciIterative(int number) {
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

std::vector<std::string> filerWords(const std::string& inputText) {
    const std::regex regex("\\w+");
    const std::sregex_iterator itBegin(inputText.cbegin(), inputText.cend(), regex);
    const std::sregex_iterator itEnd;
    std::vector<std::string> output;
    std::transform(itBegin, itEnd, std::back_inserter(output), [](auto match){ return match.str(); });
    return output;
}


template <typename T>
std::vector<T> mergeSortedVectors(const std::vector<std::vector<T>>& inputVectors) {
    const size_t inputVectorsSize = inputVectors.size();
    size_t allElementsSize = 0;
    std::vector<size_t> vectorsPointers(inputVectorsSize, 0);

    for (const auto& item : inputVectors) {
        allElementsSize += item.size();
    }

    std::vector<T> outputVector(allElementsSize, 0);
    for (int i = 0; i < allElementsSize; ++i) {
        T min = std::numeric_limits<T>::max();
        size_t indexOfMin = 0;
        for (int j = 0; j < inputVectorsSize; ++j) {
            const size_t pos = vectorsPointers[j];
            const auto& currentVector = inputVectors[j];
            if (pos < currentVector.size() && currentVector[pos] < min) {
                indexOfMin = j;
                min = currentVector[pos];
            }
        }
        outputVector[i] = min;
        ++vectorsPointers[indexOfMin];
    }
    return outputVector;
}


int convertToInt(const char* str, const int length) {
    int result = 0;
    const int zeroVal = static_cast<int>('0');
    int counter = 1;
    for (int i = length - 1; i >= 0; --i) {
        const int current = static_cast<int>(*(str + i));
        const int value = current - zeroVal;
        if (value < 0 || value > 9) {
            return -1;
        }
        result += value  * counter;
        counter *= 10;
    }
    return result;
}

}
