#ifndef StandardAlgorithms_h__
#define StandardAlgorithms_h__

class StandardAlgorithms
{
public:
    static void bubbleSort(int* arr, int size);
    static void countSortEasy(int* arr, const int size);
    static void selectionSort(int* arr, int size);
    static void insertionSort(int* arr, int size);
    static int binarySearch(int* arr, int size, int search);
};

#endif // StandardAlgorithms_h__