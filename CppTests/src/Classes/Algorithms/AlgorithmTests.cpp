#include "AlgorithmTests.h"
#include "StandardAlgorithms.h"
#include <iostream>

AlgorithmTests::AlgorithmTests()
{
}


AlgorithmTests::~AlgorithmTests()
{
}

void AlgorithmTests::testBubbleSort()
{
    const int arraySize = 10;
    int arr[arraySize];
    for (int i = 0; i < arraySize; ++i)
    {
        arr[i] = rand() % (i + 1);
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    StandardAlgorithms::bubbleSort(arr, arraySize);
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}


void AlgorithmTests::testCountSort()
{
    const int arraySize = 10;
    int arr[arraySize];
    for (int i = 0; i < arraySize; ++i)
    {
        arr[i] = rand() % (i + 1);
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    StandardAlgorithms::countSortEasy(arr, arraySize);
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

void AlgorithmTests::testSelectionSort()
{
    const int arraySize = 10;
    int arr[arraySize];
    for (int i = 0; i < arraySize; ++i)
    {
        arr[i] = rand() % (i + 1);
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    StandardAlgorithms::selectionSort(arr, arraySize);
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

void AlgorithmTests::testInsertionSort()
{
    const int arraySize = 10;
    int arr[arraySize];
    for (int i = 0; i < arraySize; ++i)
    {
        arr[i] = rand() % (i + 1);
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    StandardAlgorithms::insertionSort(arr, arraySize);
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

void AlgorithmTests::testBinarySearch()
{
    const int arraySize = 10;
    int arr[arraySize];
    for (int i = 0; i < arraySize; ++i)
    {
        arr[i] = i;
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    std::cout << StandardAlgorithms::binarySearch(arr, arraySize, 7) << std::endl;
}
