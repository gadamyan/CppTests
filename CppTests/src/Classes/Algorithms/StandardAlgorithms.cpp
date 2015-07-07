#include "StandardAlgorithms.h"

void StandardAlgorithms::bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void StandardAlgorithms::countSortEasy(int* arr, const int size)
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

void StandardAlgorithms::selectionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void StandardAlgorithms::insertionSort(int* arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

int StandardAlgorithms::binarySearch(int* arr, int size, int search)
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
