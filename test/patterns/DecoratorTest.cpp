//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/patterns/Decorator.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(DecoratorTest, when_we_wrap_the_product_into_a_decorator_decoratro_returns_correct_price)
{
    auto product = std::make_unique<ConcreteProduct>();
    ASSERT_EQ(100, product->get_price());
    auto first_decorator = std::make_unique<ConcreteDecorator>(std::move(product));
    ASSERT_EQ(200, first_decorator->get_price());
    auto second_decorator = std::make_unique<ConcreteDecorator>(std::move(first_decorator));
    ASSERT_EQ(300, second_decorator->get_price());
}
}
