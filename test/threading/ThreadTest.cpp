//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include <vector>
#include <thread>
#include <chrono>
#include <future>

#include <gtest/gtest.h>

namespace {

constexpr int kThreadCount = 100;

void threadFunction(std::shared_ptr<int> accessCount, std::shared_ptr<std::mutex> mutex) {
    std::lock_guard<std::mutex> lock(*mutex);
    ++(*accessCount);
}

TEST(ThreadTest, verify_thread_function_access)
{
    std::vector<std::thread> threads;
    auto mutexPointer = std::make_shared<std::mutex>();
    auto accessCount = std::make_shared<int>(0);
    threads.reserve(kThreadCount);
    for (int i = 0; i < kThreadCount; ++i) {
        threads.emplace_back(&threadFunction, accessCount, mutexPointer);
    }
    for (std::thread& thread : threads) {
        thread.join();
    }
    ASSERT_EQ(*accessCount, kThreadCount);
}

TEST(ThreadTest, verify_thread_lambda_access)
{
    std::vector<std::thread> threads;
    threads.reserve(kThreadCount);
    std::mutex mutex;
    std::vector<int> result;
    for (int i = 0; i < kThreadCount; ++i) {
        std::function<void()> callFunc([i, &mutex, &result](){
            const int milliseconds = rand() % 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
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

TEST(ThreadTest, verify_async_future_access)
{
    std::vector<int> result;
    std::vector<std::future<void>> futures;
    std::mutex mutex;
    for (int i = 0; i < kThreadCount; ++i) {
        std::function<void()> callFunc([i, &mutex, &result]() {
            const int milliseconds = rand() % 100;
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
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

TEST(ThreadTest, verify_that_threads_dont_create_deadlock)
{
    std::mutex firstMutex;
    std::mutex secondMutex;
    constexpr int iterationCount = 100000;
    int accessCount = 0;

    auto firstFunction = [&firstMutex, &secondMutex, &accessCount](int value) {
        std::lock_guard<std::mutex> firstLock(firstMutex);
        std::lock_guard<std::mutex> secondLock(secondMutex);
        ++accessCount;
    };

    auto secondFunction = [&firstMutex, &secondMutex, &accessCount](int value) {
        //NOTE reversing the order of locking these two mutexes will result in deadlock
        std::lock_guard<std::mutex> firstLock(firstMutex);
        std::lock_guard<std::mutex> secondLock(secondMutex);
        ++accessCount;
    };

    auto cycleAndLog = [](const std::function<void(int)>& fn) {
        for (int i = 0; i < iterationCount; ++i) {
            fn(i);
        }
    };

    std::thread firstThread(cycleAndLog, firstFunction);
    std::thread secondThread(cycleAndLog, secondFunction);

    firstThread.join();
    secondThread.join();
    ASSERT_EQ(accessCount, iterationCount * 2);
}
}
