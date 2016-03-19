//
//  ThreadTest.cpp
//  MainApp
//
//  Created by Gevorg Adamyan on 1/16/16.
//  Copyright © 2016 Gevorg Adamyan. All rights reserved.
//

#include "ThreadTest.h"
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <future>

void MainThreading::ThreadTest::test()
{
    test1();
    test2();
    test3();
    test4();
}

void MainThreading::ThreadTest::threadFunction(const int i, std::shared_ptr<std::mutex> mutex)
{
    mutex->lock();
    std::cout << "testing1 " << i << std::endl;
    mutex->unlock();
}

void MainThreading::ThreadTest::test1()
{
    std::vector<std::thread> threads;
    std::shared_ptr<std::mutex> mutexPointer = std::make_shared<std::mutex>();
    for (int i = 0; i < 100; ++i)
    {
        threads.push_back(std::thread(&ThreadTest::threadFunction, this, i, mutexPointer));
    }
    for (std::thread& thread : threads)
    {
        thread.join();
    }
}

void MainThreading::ThreadTest::test2()
{
    std::vector<std::thread> threads;
    std::mutex mutex;
    for (int i = 0; i < 100; ++i)
    {
        std::function<void()> callFunc([i, &mutex](){
            mutex.lock();
            std::cout << "testing2 " << i << std::endl;
            mutex.unlock();
        });
        threads.push_back(std::thread(callFunc));
    }
    for (std::thread& thread : threads)
    {
        thread.join();
    }
}

void MainThreading::ThreadTest::test3()
{
    std::vector<std::thread> threads;
    std::mutex mutex;
    for (int i = 0; i < 100; ++i)
    {
        std::function<void()> callFunc([i, &mutex](){
            int miliseconds = rand() % 1000;
            std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
            mutex.lock();
            std::cout << "testing3 " << i << std::endl;
            mutex.unlock();
        });
        threads.push_back(std::thread(callFunc));
    }
    for (std::thread& thread : threads)
    {
        thread.join();
    }
}

void MainThreading::ThreadTest::test4()
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