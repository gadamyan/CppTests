//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>
#include <thread>
#include <deque>

namespace cpptests::core::threading {

class ProducerConsumer {
public:
    explicit ProducerConsumer(int taskCount);
    ~ProducerConsumer();
    void startProducing();
    void startConsuming();
    void finish();
    int getExecutedTaskCount() const;

private:
    void produce();
    void consume();

private:
    const int mTaskCount;
    int mExecutedTaskCount;
    std::deque<int> mData;
    std::mutex mMutex;
    std::condition_variable mCond;
    std::thread mProducerThread;
    std::thread mConsumerThread;
};

}
