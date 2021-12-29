//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/testable/TestFactory.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::testable;

class SimpleTest : public AbstractTest
{
    using AbstractTest::AbstractTest;
public:
    void run() override
    {
        ASSERT_EQ(1, 1);
    }
};

bool simple_test = make_test<SimpleTest>("SimpleTestCathegory", "SimpleTest");

TEST(ProducerConsumerTest, verify_the_global_access_of_the_singleton)
{
    get_factory().run_all_tests();
}
}

