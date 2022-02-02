//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/containers/Array.h"
#include "core/containers/ArrayStack.h"
#include "core/containers/ListStack.h"
#include "core/containers/ListQueue.h"
#include "core/containers/LinkedList.h"
#include "core/containers/TreeMap.h"


#include "utils/TestUtils.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::containers;

TEST(ArrayTest, validate_array_access)
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
    ASSERT_TRUE(test::isEqual(actualVector, expectedVector));
}

TEST(LinkedListTest, validate_link_list_pop_back)
{
    std::initializer_list<int> list { 1, 4, 7, 9, 8 };
    LinkedList<int> testList = list;
    ASSERT_EQ(testList.size(), list.size());

    std::vector<int> expectedVector = list;
    std::vector<int> actualVector;
    actualVector.reserve(list.size());
    for (int i = 0; i < list.size(); ++i) {
        actualVector.push_back(testList.popBack());
    }
    std::reverse(actualVector.begin(), actualVector.end());

    ASSERT_EQ(0, testList.size());
    ASSERT_TRUE(test::isEqual(actualVector, expectedVector));
}

TEST(LinkedListTest, validate_linked_list_pop_front)
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
        actualVector.emplace_back(testList.popFront());
    }
    std::reverse(actualVector.begin(), actualVector.end());

    ASSERT_EQ(0, testList.size());
    ASSERT_TRUE(test::isEqual(actualVector, list));
}

TEST(ArrayStackTest, validate_array_stack_access)
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
    ASSERT_TRUE(test::isEqual(actualVector, list));
}

TEST(ListStackTest, validate_list_stack_access)
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
    ASSERT_TRUE(test::isEqual(actualVector, list));
}

TEST(ListQueueTest, validate_list_queue_access)
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
    ASSERT_TRUE(test::isEqual(actualVector, list));
}

TEST(TreeMapTest, validate_tree_map_access)
{
    TreeMap<int> treeMap;
    for (int i = 0; i < 20; ++i) {
        treeMap.set(std::to_string(i), i);
    }

    for (auto it = treeMap.begin(); it != treeMap.end(); ++it) {
        auto item = *it;
        ASSERT_EQ(item.first, std::to_string(item.second));
    }

    size_t size = treeMap.size();
    ASSERT_EQ(size, 20);
    for (int i = 0; i < size; ++i) {
        std::string key = std::to_string(i);
        ASSERT_EQ(treeMap.get(key), i);
    }

    treeMap.clear();
    ASSERT_EQ(treeMap.size(), 0);
}
}
