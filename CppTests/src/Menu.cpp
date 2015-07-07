#include "Menu.h"
#include "Classes/Solution1.h"
#include "Classes/Containers/ContainerTests.h"
#include "Classes/Algorithms/AlgorithmTests.h"
#include <iostream>

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::show()
{
    Solution1 solution1;
    ContainerTests containerTests;
    AlgorithmTests algorithmTests;
    int number;
    while (true)
    {
        std::cout << "99 - Exit" << std::endl;
        std::cout << "1 - Ex 1" << std::endl;
        std::cout << "2 - Ex 2" << std::endl;
        std::cout << "3 - Ex 3" << std::endl;
        std::cout << "4 - Ex 4" << std::endl;
        std::cout << "5 - Ex 5" << std::endl;
        std::cout << "6 - Ex 6" << std::endl;
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
        case 101:
            solution1.removeElements();
            break;
        case 102:
            solution1.geometric1();
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
        case 99:
            return;
        default:
            break;
        }
        std::cout << std::endl;
    }
}
