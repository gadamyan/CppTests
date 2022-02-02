//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/testable/TestFactory.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::testable;

class SimpleTest : public AbstractTest {
    using AbstractTest::AbstractTest;
public:
    void run() override {
        ASSERT_EQ(1, 1);
    }
};

bool simple_test = makeTest<SimpleTest>("SimpleTestCathegory", "SimpleTest");

TEST(TestFactoryTest, run_all_the_statically_created_tests)
{
    getFactory().runAllTests();
}
}

