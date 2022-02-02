//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/smart_pointers/UniquePtr.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::smart_pointers;

TEST(UniquePtrTest, verify_unique_pointer)
{
    auto ptr1 = makeUniquePtr<int>(1);
    auto ptr2 = makeUniquePtr<int>(2);
    ASSERT_EQ(*ptr1, 1);
    ASSERT_EQ(*ptr2, 2);

    ptr1 = std::move(ptr2);
    ASSERT_EQ(*ptr1, 2);
    ASSERT_EQ(ptr2.get(), nullptr);
}
}
