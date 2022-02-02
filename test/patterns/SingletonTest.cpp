//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Singleton.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(SingletonTest, verify_the_global_access_of_the_singleton)
{
    GlobalsSingleton::getInstance().setInt(5);
    ASSERT_EQ(GlobalsSingleton::getInstance().getInt(), 5);
}
}
