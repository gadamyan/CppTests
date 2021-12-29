//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/threading/ProducerConsumer.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::threading;

TEST(ProducerConsumerTest, verify_the_global_access_of_the_singleton)
{
    ProducerConsumer producer_consumer;
    std::thread producer(&ProducerConsumer::produce, &producer_consumer);
    std::thread consumer(&ProducerConsumer::consume, &producer_consumer);

    producer.join();
    consumer.join();
}
}
