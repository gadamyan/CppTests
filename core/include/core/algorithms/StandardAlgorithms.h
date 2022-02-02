//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <algorithm>
#include <vector>

namespace cpptests::core::algorithms {

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

void selectionSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            std::swap(array[i], array[minIndex]);
        }
    }
}

void insertionSort(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 && array[j] < array[j - 1]; --j) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

void countSort(int* array, int size) {
    int containerSize = 0;
    for (int i = 0; i < size; ++i) {
        containerSize = std::max(containerSize, array[i]);
    }
    containerSize += 1;
    std::vector<int> tempContainer(containerSize, 0);
    for (int i = 0; i < size; ++i) {
        ++tempContainer[array[i]];
    }
    int counter = 0;
    for (int i = 0; i < containerSize; ++i) {
        while (tempContainer[i] != 0) {
            array[counter++] = i;
            --tempContainer[i];
        }
    }
}

int binarySearch(const int* array, int size, int search) {
    int low = 0;
    int high = size;
    while (low < high) {
        int middle = (low + high) / 2;
        if (search <= array[middle]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    return (array[low] == search)? low : -1;
}
}
