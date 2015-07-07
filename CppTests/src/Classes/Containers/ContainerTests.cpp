#include "ContainerTests.h"
#include "ArrayStack.h"
#include "ListStack.h"
#include "ListQueue.h"
#include "LinkedList.h"
#include "TreeMap.h"
#include <iostream>

void ContainerTests::testArrayStack()
{
    ArrayStack<int> s;
    for (int i = 0; i < 20; ++i)
    {
        s.push(i);
    }
    size_t stackSize = s.size();
    for (int i = 0; i < stackSize; ++i)
    {
        std::cout << s.pop() << " ";
    }
    std::cout << std::endl;
}

void ContainerTests::testListStack()
{
    mcont::ListStack<int> s;
    for (int i = 0; i < 20; ++i)
    {
        s.push(i);
    }
    size_t stackSize = s.size();
    for (int i = 0; i < stackSize; ++i)
    {
        std::cout << s.pop() << " ";
    }
    std::cout << std::endl;
}

void ContainerTests::testListQueue()
{
    mcont::ListQueue<int> s;
    for (int i = 0; i < 20; ++i)
    {
        s.pushBack(i);
    }
    size_t stackSize = s.size();
    for (int i = 0; i < stackSize; ++i)
    {
        std::cout << s.popFront() << " ";
    }
    std::cout << std::endl;
}

void ContainerTests::testLinkedList()
{
    mcont::LinkedList<int> s;
    for (int i = 0; i < 20; ++i)
    {
        s.pushBack(i);
    }
    size_t stackSize = s.size();
    for (int i = 0; i < stackSize; ++i)
    {
        std::cout << s.popFront() << " ";
    }
    std::cout << std::endl;
}

void ContainerTests::testTreeMap()
{
    mcont::TreeMap<int> s;
    for (int i = 0; i < 20; ++i)
    {
        s.set(std::to_string(i), i);
    }

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        auto item = *it;
        std::cout << it->first << "  " << it->second << std::endl;
    }

    s.clear();
    size_t stackSize = s.size();
    for (int i = 0; i < stackSize; ++i)
    {
        std::cout << s.get(std::to_string(i)) << " ";
    }
    std::cout << std::endl;
}
