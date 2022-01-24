//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <memory>
#include <thread>
#include <deque>

namespace cpptests::core::threading {

class ProducerConsumer
{
public:
    void produce() {
        int count = 10;
        while (count != 0) {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_data.push_back(count);
            lock.unlock();
            m_cond.notify_one();
            --count;
        }
    }

    void consume() {
        int value = 0;
        while (value != 1) {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_cond.wait(lock, [this](){ return !m_data.empty(); });
            value = m_data.front();
            m_data.pop_front();
            lock.unlock();
        }
    }

private:
    std::deque<int> m_data;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};

}
