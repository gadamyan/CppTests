//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/smart_pointers/UniquePtr.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::smart_pointers;

TEST(UniquePtrTest, verify_unique_pointer)
{
    auto ptr1 = make_unique_ptr<int>(1);
    auto ptr2 = make_unique_ptr<int>(2);
    assert(*ptr1 == 1);
    assert(*ptr2 == 2);

    ptr1 = std::move(ptr2);
    assert(*ptr1 == 2);
    assert(ptr2.get() == nullptr);
}
}
