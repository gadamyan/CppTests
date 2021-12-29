//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/containers/Array.h"

#include "core/containers/ArrayStack.h"
#include "core/containers/ListStack.h"
#include "core/containers/ListQueue.h"
#include "core/containers/LinkedList.h"
#include "core/containers/TreeMap.h"
#include "core/containers/HashMap.h"


#include "utils/TestUtils.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::containers;

TEST(ArrayTest, verify_the_global_access_of_the_singleton)
{
    std::initializer_list<int> list { 1, 4, 7, 9, 8 };
    Array<int, 5> test_array = list;

    std::vector<int> expected_vector = list;
    std::vector<int> actual_vector;
    for (auto item : test_array)
    {
        actual_vector.push_back(item);
    }

    assert(test_array[1] == 4);
    static_assert(test_array.size() == 5);
    assert(test::is_equal(actual_vector, expected_vector));
}

TEST(LinkedListTest, verify_the_global_access_of_the_singleton)
{
    std::initializer_list<int> list { 1, 4, 7, 9, 8 };
    LinkedList<int> test_list = list;
    assert(test_list.size() == list.size());

    std::vector<int> expected_vector = list;
    std::vector<int> actual_vector;
    actual_vector.reserve(list.size());
    for (int i = 0; i < list.size(); ++i)
    {
        actual_vector.push_back(test_list.pop_back());
    }
    std::reverse(actual_vector.begin(), actual_vector.end());

    assert(test_list.size() == 0);
    assert(test::is_equal(actual_vector, expected_vector));
}

TEST(ArrayStackTest, test_array_stack)
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

    TEST(ListStackTest, test_list_stack)
    {
        ListStack<int> s;
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

    TEST(ListQueueTest, test_list_queue)
    {
        ListQueue<int> s;
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

    TEST(LinkedListTest, test_linked_list)
    {
        LinkedList<int> s;
        for (int i = 0; i < 20; ++i)
        {
            s.push_back(i);
        }
        size_t stackSize = s.size();
        for (int i = 0; i < stackSize; ++i)
        {
            std::cout << s.pop_front() << " ";
        }
        std::cout << std::endl;
    }

    TEST(TreeMapTest, test_tree_map)
    {
        TreeMap<int> s;
        for (int i = 0; i < 20; ++i)
        {
            s.set(std::to_string(i), i);
        }

        /*for (auto it = s.begin(); it != s.end(); ++it)
        {
            auto item = *it;
            std::cout << it->first << "  " << it->second << std::endl;
        }*/

        s.clear();
        size_t stackSize = s.size();
        for (int i = 0; i < stackSize; ++i)
        {
            std::cout << s.get(std::to_string(i)) << " ";
        }
        std::cout << std::endl;
    }
}
