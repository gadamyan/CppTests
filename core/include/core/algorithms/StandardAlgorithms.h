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

namespace cpptests::core::algorithms {

void bubble_sort(int* array, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

void selection_sort(int* array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[min_index] > array[j]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            std::swap(array[i], array[min_index]);
        }
    }
}

void insertion_sort(int* array, int size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j > 0 && array[j] < array[j - 1]; --j)
        {
            std::swap(array[j], array[j - 1]);
        }
    }
}

void count_sort(int* array, int size)
{
    int container_size = 0;
    for (int i = 0; i < size; ++i)
    {
        container_size = std::max(container_size, array[i]);
    }
    container_size += 1;
    std::vector<int> temp_container(container_size, 0);
    for (int i = 0; i < size; ++i)
    {
        ++temp_container[array[i]];
    }
    int counter = 0;
    for (int i = 0; i < container_size; ++i)
    {
        while (temp_container[i] != 0)
        {
            array[counter++] = i;
            --temp_container[i];
        }
    }
}

int binary_search(const int* array, int size, int search)
{
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

    void countSortEasy(int* arr, const int size)
    {
        int max = arr[0], i;
        for (i = 0; i < size; ++i)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        const int sortSize = max + 1;
        int* sort = new int[sortSize];

        for (i = 0; i < sortSize; ++i)
        {
            sort[i] = 0;
        }

        for (i = 0; i < size; ++i)
        {
            ++sort[arr[i]];
        }

        i = 0;
        int tail = 0;
        for (i = 0; i < sortSize; ++i)
        {
            while (sort[i] != 0)
            {
                arr[tail++] = i;
                --sort[i];
            }
        }
        delete[] sort;
    }

    int binarySearch(int* arr, int size, int search)
    {
        int low = 0, up = size;
        while (low + 1 < up)
        {
            int middle = (low + up) >> 1;
            if (arr[middle] > search)
            {
                up = middle;
            }
            else
            {
                low = middle;
            }
        }
        int position = -1;
        if (arr[low] == search)
        {
            position = low;
        }
        return position;
    }

}
