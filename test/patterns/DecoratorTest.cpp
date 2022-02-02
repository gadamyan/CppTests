//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Decorator.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(DecoratorTest, when_we_wrap_the_product_into_a_decorator_decoratro_returns_correct_price)
{
    auto product = std::make_unique<ConcreteProduct>();
    ASSERT_EQ(100, product->getPrice());
    auto firstDecorator = std::make_unique<ConcreteDecorator>(std::move(product));
    ASSERT_EQ(200, firstDecorator->getPrice());
    auto secondDecorator = std::make_unique<ConcreteDecorator>(std::move(firstDecorator));
    ASSERT_EQ(300, secondDecorator->getPrice());
}
}
