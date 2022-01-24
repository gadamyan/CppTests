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

TEST(ArrayTest, array_access)
{
    std::initializer_list<int> list { 1, 4, 7, 9, 8 };
    Array<int, 5> testArray = list;

    std::vector<int> expectedVector = list;
    std::vector<int> actualVector;
    for (auto item : testArray) {
        actualVector.push_back(item);
    }

    ASSERT_EQ(4, testArray[1]);
    static_assert(testArray.size() == 5);
    ASSERT_TRUE(test::is_equal(actualVector, expectedVector));
}

TEST(LinkedListTest, link_list_access)
{
    std::initializer_list<int> list { 1, 4, 7, 9, 8 };
    LinkedList<int> testList = list;
    ASSERT_EQ(testList.size(), list.size());

    std::vector<int> expectedVector = list;
    std::vector<int> actualVector;
    actualVector.reserve(list.size());
    for (int i = 0; i < list.size(); ++i) {
        actualVector.push_back(testList.pop_back());
    }
    std::reverse(actualVector.begin(), actualVector.end());

    ASSERT_EQ(0, testList.size());
    ASSERT_TRUE(test::is_equal(actualVector, expectedVector));
}

TEST(LinkedListTest, test_linked_list)
{
    std::vector<int> list { 1, 4, 7, 9, 8 };
    std::vector<int> actualVector;
    actualVector.reserve(list.size());
    LinkedList<int> testList;
    for (int i : list) {
        testList.push_front(i);
    }
    size_t stackSize = testList.size();
    for (int i = 0; i < stackSize; ++i) {
        actualVector.emplace_back(testList.pop_front());
    }
    std::reverse(actualVector.begin(), actualVector.end());

    ASSERT_EQ(0, testList.size());
    ASSERT_TRUE(test::is_equal(actualVector, list));
}

TEST(ArrayStackTest, test_array_stack)
{
    std::vector<int> list { 1, 4, 7, 9, 8 };
    std::vector<int> actualVector;
    actualVector.reserve(list.size());
    ArrayStack<int> testStack;
    for (int i : list) {
        testStack.push(i);
    }
    size_t stackSize = testStack.size();
    for (int i = 0; i < stackSize; ++i) {
        actualVector.emplace_back(testStack.pop());
    }
    std::reverse(actualVector.begin(), actualVector.end());

    ASSERT_EQ(0, testStack.size());
    ASSERT_TRUE(test::is_equal(actualVector, list));
}

TEST(ListStackTest, test_list_stack)
{
    std::vector<int> list { 1, 4, 7, 9, 8 };
    std::vector<int> actualVector;
    actualVector.reserve(list.size());
    ListStack<int> testStack;
    for (int i : list) {
        testStack.push(i);
    }
    size_t stackSize = testStack.size();
    for (int i = 0; i < stackSize; ++i) {
        actualVector.emplace_back(testStack.pop());
    }
    std::reverse(actualVector.begin(), actualVector.end());

    ASSERT_EQ(0, testStack.size());
    ASSERT_TRUE(test::is_equal(actualVector, list));
}

TEST(ListQueueTest, test_list_queue)
{
    std::vector<int> list { 1, 4, 7, 9, 8 };
    std::vector<int> actualVector;
    actualVector.reserve(list.size());
    ListQueue<int> testQueue;
    for (int i : list) {
        testQueue.pushBack(i);
    }
    size_t stackSize = testQueue.size();
    for (int i = 0; i < stackSize; ++i) {
        actualVector.emplace_back(testQueue.popFront());
    }

    ASSERT_EQ(0, testQueue.size());
    ASSERT_TRUE(test::is_equal(actualVector, list));
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
