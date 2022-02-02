//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Strategy.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(StrategyTest, verify_the_strategy_is_set_correctly)
{
    NumberContext context;

    context.setStrategy(std::make_unique<PowStrategy>());
    ASSERT_EQ(context.calculate(5), 25);

    context.setStrategy(std::make_unique<SumStrategy>());
    ASSERT_EQ(context.calculate(5), 15);
}
}
