//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/patterns/Observer.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::patterns;

TEST(ObserverTest, verify_the_global_access_of_the_singleton)
{
    Subject subject;
    auto user1 = std::make_shared<User>();
    auto user2 = std::make_shared<User>();
    subject.register_observer(user1);
    subject.register_observer(user2);

    subject.notifyObservers("Test");
    assert(user1->get_message() == "Test");
    assert(user2->get_message() == "Test");
}
}
