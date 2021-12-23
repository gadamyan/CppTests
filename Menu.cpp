#include "Menu.h"
#include "Classes/Solution1.h"
#include "Classes/Solution2.h"
#include "Classes/TestSolutions.h"
#include "Classes/Containers/ContainerTests.h"
#include "Classes/Algorithms/AlgorithmTests.h"
#include "Classes/Algorithms/RandomAlgorithms.h"
#include "Classes/CStyle/CSolutions.h"
#include "Classes/Multithreading/ThreadTest.h"
#include <iostream>

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::show()
{
    CSolutions cSolutions;
    Solution1 solution1;
    Solution2 solution2;
    TestSolutions testSolutions;
    ContainerTests containerTests;
    AlgorithmTests algorithmTests;
    RandomAlgorithms randomAlgorithms;
    MainThreading::ThreadTest threadTest;
    
    int number;
    while (true)
    {
        std::cout << "Input a number" << std::endl;
        std::cout << "99 - Exit" << std::endl;
        std::cin >> number;
        switch (number)
        {
        case 1:
            solution1.ex1();
            break;
        case 2:
            solution1.ex2();
            break;
        case 3:
            solution1.ex3();
            break;
        case 4:
            solution1.ex4();
            break;
        case 5:
            solution1.ex5();
            break;
        case 6:
            solution1.ex6();
            break;
        case 11:
            solution2.ex1();
            break;
        case 100:
            testSolutions.wordInDict();
            break;
        case 101:
            testSolutions.removeElements();
            break;
        case 102:
            testSolutions.geometric1();
            break;
        case 103:
            containerTests.testArrayStack();
            break;
        case 104:
            containerTests.testListStack();
            break;
        case 105:
            containerTests.testListQueue();
            break;
        case 106:
            containerTests.testLinkedList();
            break;
        case 107:
            containerTests.testTreeMap();
            break;
        case 200:
            algorithmTests.testBubbleSort();
            break;
        case 201:
            algorithmTests.testBinarySearch();
            break;
        case 202:
            algorithmTests.testCountSort();
            break;
        case 203:
            algorithmTests.testSelectionSort();
            break;
        case 204:
            algorithmTests.testInsertionSort();
            break;
        case 301:
            randomAlgorithms.mergeSortedVectors();
            break;
        case 302:
            randomAlgorithms.fileFilter();
            break;
        case 403:
            cSolutions.alocate();
            break;
        case 500:
            threadTest.test();
        case 99:
            return;
        default:
            break;
        }
        std::cout << std::endl;
        std::cin.clear();
    }
}