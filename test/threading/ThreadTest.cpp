//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <future>

#include <gtest/gtest.h>

namespace {

void threadFunction(const int i, std::shared_ptr<std::mutex> mutex)
{
    std::lock_guard<std::mutex> lock(*mutex);
    std::cout << "testing1 " << i << std::endl;
}

TEST(ThreadTest, thread_test_1)
{
    std::vector<std::thread> threads;
    std::shared_ptr<std::mutex> mutexPointer = std::make_shared<std::mutex>();
    threads.reserve(100);
    for (int i = 0; i < 100; ++i) {
        threads.emplace_back(&threadFunction, i, mutexPointer);
    }
    for (std::thread& thread : threads) {
        thread.join();
    }
}

TEST(ThreadTest, thread_test_3)
{
    std::vector<std::thread> threads;
    threads.reserve(100);
    std::mutex mutex;
    std::vector<int> result;
    for (int i = 0; i < 100; ++i) {
        std::function<void()> callFunc([i, &mutex, &result](){
            const int miliseconds = rand() % 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
            std::lock_guard<std::mutex> lock(mutex);
            result.push_back(i);
        });
        threads.emplace_back(callFunc);
    }
    for (std::thread& thread : threads) {
        thread.join();
    }
    ASSERT_FALSE(std::is_sorted(result.cbegin(), result.cend()));
}

TEST(ThreadTest, thread_test_4)
{
    std::vector<int> result;
    std::vector<std::future<void>> futures;
    std::mutex mutex;
    for (int i = 0; i < 100; ++i) {
        std::function<void()> callFunc([i, &mutex, &result]() {
            const int miliseconds = rand() % 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
            std::lock_guard<std::mutex> lock(mutex);
            result.push_back(i);
        });
        futures.push_back(std::async(std::launch::async, callFunc));
    }
    for (std::future<void>& future : futures) {
        future.wait();
        future.get();
    }
    ASSERT_FALSE(std::is_sorted(result.cbegin(), result.cend()));
}

TEST(ThreadTest, deadlock)
{
    std::mutex firstMutex;
    std::mutex secondMutex;
    bool isTerminated = false;
    bool isFirstLocked = false;
    bool isSecondLocked = false;

    auto firstFunction = [&firstMutex, &secondMutex, &isTerminated, &isFirstLocked, &isSecondLocked](const int value)
    {
        std::lock_guard<std::mutex> firstLock(firstMutex);
        isFirstLocked = true;
        if (isSecondLocked) {
            isTerminated = true;
            return;
        }
        std::lock_guard<std::mutex> secondLock(secondMutex);
        std::cout << "Function 1 prints : " << value << std::endl;
        isFirstLocked = false;
        isSecondLocked = false;
    };

    auto secondFunction = [&firstMutex, &secondMutex, &isTerminated, &isFirstLocked, &isSecondLocked](const int value)
    {
        std::lock_guard<std::mutex> secondLock(secondMutex);
        isSecondLocked = true;
        if (isFirstLocked) {
            isTerminated = true;
            return;
        }
        std::lock_guard<std::mutex> firstLock(firstMutex);
        std::cout << "Function 2 prints : " << value << std::endl;
        isFirstLocked = false;
        isSecondLocked = false;
    };

    auto cycleAndLog = [](std::function<void(int)> fn) {
        for (int i = 0; i < 1000; ++i) {
            fn(i);
        }
    };

    std::thread firstThread(cycleAndLog, firstFunction);
    std::thread secondThread(cycleAndLog, secondFunction);

    firstThread.join();
    secondThread.join();

    EXPECT_TRUE(isTerminated);
}
}
