//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/smart_pointers/SharedPtr.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::smart_pointers;

TEST(SharedPtrTest, verify_shared_pointer)
{
    auto ptr1 = makeSharedPtr<int>(1);
    auto ptr2 = makeSharedPtr<int>(2);
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
