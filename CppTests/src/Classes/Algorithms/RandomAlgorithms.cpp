#include "RandomAlgorithms.h"

#include <regex>
#include <iostream>
#include "Simple/ReverseList.h"
#include "Simple/ReverseBTree.h"
#include "Simple/Fibonachi.h"

void RandomAlgorithms::fileFilter()
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

void RandomAlgorithms::mergeSortedVectors()
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
        int min = std::numeric_limits<int>().max();
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


void reverseList()
{
    ReverseList::testReverse();
}

void reverseBTree()
{
    ReverseBTree::testReverse();
}


void fibonachi()
{
    Fibonachi::testFibonachi();
}