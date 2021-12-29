//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/patterns/Singleton.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(SingletonTest, verify_the_global_access_of_the_singleton)
{
    GlobalsSingleton::get_instance().set_int(5);
    assert(GlobalsSingleton::get_instance().get_int() == 5);
}
}
