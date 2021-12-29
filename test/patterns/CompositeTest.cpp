//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/patterns/Composite.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(CompositeTest, verify_the_global_access_of_the_singleton)
{
    auto root = std::make_unique<Composite>();
    root->add_child(std::make_unique<Lief>("F1"));
    root->add_child(std::make_unique<Lief>("F2"));
    root->add_child(std::make_unique<Lief>("F3"));

    std::unique_ptr<Composite> child = std::make_unique<Composite>();
    child->add_child(std::make_unique<Lief>("F4"));
    child->add_child(std::make_unique<Lief>("F5"));
    child->add_child(std::make_unique<Lief>("F6"));

    root->add_child(std::move(child));
    const std::string full_path = root->get_path();
    assert(full_path == "-F1\n-F2\n-F3\n--F4\n--F5\n--F6\n");
}
}
