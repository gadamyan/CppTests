//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/threading/ProducerConsumer.h"

using namespace cpptests::core::threading;

ProducerConsumer::ProducerConsumer(int taskCount)
    : mTaskCount(taskCount)
    , mExecutedTaskCount(0)
{}

ProducerConsumer::~ProducerConsumer() {
    finish();
}

int ProducerConsumer::getExecutedTaskCount() const {
    return mExecutedTaskCount;
}

void ProducerConsumer::produce() {
    int count = mTaskCount;
    while (count != 0) {
        std::unique_lock<std::mutex> lock(mMutex);
        mData.push_back(count);
        lock.unlock();
        mCond.notify_one();
        --count;
    }
}

void ProducerConsumer::consume() {
    int value = 0;
    while (value != 1) {
        std::unique_lock<std::mutex> lock(mMutex);
        mCond.wait(lock, [this](){ return !mData.empty(); });
        value = mData.front();
        mData.pop_front();
        ++mExecutedTaskCount;
        lock.unlock();
    }
}

void ProducerConsumer::startProducing() {
    mProducerThread = std::thread(&ProducerConsumer::produce, this);
}

void ProducerConsumer::startConsuming() {
    mConsumerThread = std::thread(&ProducerConsumer::consume, this);
}

void ProducerConsumer::finish() {
    if (mProducerThread.joinable()) {
        mProducerThread.join();
    }
    if (mConsumerThread.joinable()) {
        mConsumerThread.join();
    }
}