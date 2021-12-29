//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/smart_pointers/SharedPtr.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::smart_pointers;

TEST(SharedPtrTest, verify_shared_pointer)
{
    auto ptr1 = make_shared_ptr<int>(1);
    auto ptr2 = make_shared_ptr<int>(2);
    auto ptr3 = ptr1;
    ASSERT_EQ(*ptr1, 1);
    ASSERT_EQ(*ptr2, 2);
    ASSERT_NE(ptr1, ptr2);
    ASSERT_EQ(ptr1, ptr3);

    ptr3 = std::move(ptr2);
    ASSERT_EQ(*ptr3, 2);
    ASSERT_EQ(ptr2.get(), nullptr);
}
}
