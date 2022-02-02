//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Composite.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(CompositeTest, verify_the_global_access_of_the_singleton)
{
    auto root = std::make_unique<Composite>();
    root->addChild(std::make_unique<Lief>("F1"));
    root->addChild(std::make_unique<Lief>("F2"));
    root->addChild(std::make_unique<Lief>("F3"));

    auto child = std::make_unique<Composite>();
    child->addChild(std::make_unique<Lief>("F4"));
    child->addChild(std::make_unique<Lief>("F5"));
    child->addChild(std::make_unique<Lief>("F6"));

    root->addChild(std::move(child));
    const std::string fullPath = root->getPath();
    ASSERT_EQ(fullPath, "-F1\n-F2\n-F3\n--F4\n--F5\n--F6\n");
}
}
