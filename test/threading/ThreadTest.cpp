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
for (int i = 0; i < 100; ++i)
    {
        threads.emplace_back(&threadFunction, i, mutexPointer);
    }
    for (std::thread& thread : threads)
    {
        thread.join();
    }
}

TEST(ThreadTest, thread_test_2)
{
        std::vector<std::thread> threads;
        threads.reserve(100);
        std::mutex mutex;
        for (int i = 0; i < 100; ++i)
        {
            std::function<void()> callFunc([i, &mutex](){
                std::lock_guard<std::mutex> lock(mutex);
                std::cout << "testing2 " << i << std::endl;
            });
            threads.emplace_back(callFunc);
        }
        for (std::thread& thread : threads)
        {
            thread.join();
        }
    }

    TEST(ThreadTest, thread_test_3)
    {
        std::vector<std::thread> threads;
        threads.reserve(100);
        std::mutex mutex;
        for (int i = 0; i < 100; ++i)
        {
            std::function<void()> callFunc([i, &mutex](){
                int miliseconds = rand() % 1000;
                std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
                std::lock_guard<std::mutex> lock(mutex);
                std::cout << "testing3 " << i << std::endl;
            });
            threads.emplace_back(callFunc);
        }
        for (std::thread& thread : threads)
        {
            thread.join();
        }
    }


    TEST(ThreadTest, thread_test_4)
    {
        std::vector<std::future<void>> futures;
        for (int i = 0; i < 100; ++i)
        {
            std::function<void()> callFunc([i]()
                                           {
                                               std::cout << i;
                                           });
            futures.push_back(std::async(std::launch::async, callFunc));
        }
        for (std::future<void>& future : futures)
        {
            future.wait();
            future.get();
        }
    }

    TEST(ThreadTest, deadlock)
    {
        std::mutex firstMutex;
        std::mutex secondMutex;

        auto firstFunction = [&firstMutex, &secondMutex](const int value)
        {
            std::lock_guard<std::mutex> firstLock(firstMutex);
            std::lock_guard<std::mutex> secondLock(secondMutex);
            std::cout << "Function 1 prints : " << value << std::endl;
        };

        auto secondFunction = [&firstMutex, &secondMutex](const int value)
        {
            std::lock_guard<std::mutex> secondLock(secondMutex);
            std::lock_guard<std::mutex> firstLock(firstMutex);
            std::cout << "Function 2 prints : " << value << std::endl;
        };

        auto cycleAndLog = [](std::function<void(int)> fn)
        {
            for (int i = 0; i < 1000; ++i)
            {
                fn(i);
            }
        };

        std::thread firstThread(cycleAndLog, firstFunction);
        std::thread secondThread(cycleAndLog, secondFunction);

        firstThread.join();
        secondThread.join();
    }
}
