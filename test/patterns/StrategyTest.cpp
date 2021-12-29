//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/patterns/Strategy.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(StrategyTest, verify_the_strategy_is_set_correctly)
{
    NumberContext context;

    context.set_strategy(std::make_unique<PowStrategy>());
    assert(context.calculate(5) == 25);

    context.set_strategy(std::make_unique<SumStrategy>());
    assert(context.calculate(5) == 15);
}
}
