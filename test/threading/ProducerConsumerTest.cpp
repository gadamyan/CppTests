//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/threading/ProducerConsumer.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::threading;

TEST(ProducerConsumerTest, verify_that_the_consumer_processes_the_tasks_that_producer_creates)
{
    ProducerConsumer producerConsumer(100000);
    producerConsumer.startProducing();
    producerConsumer.startConsuming();
    producerConsumer.finish();
    ASSERT_EQ(producerConsumer.getExecutedTaskCount(), 100000);
}
}
