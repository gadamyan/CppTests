//
//  CppTests
//
//  Created by Gevorg Adamyan
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
    subject.registerObserver(user1);
    subject.registerObserver(user2);

    const std::string message = "Test";
    subject.notifyObservers(message);
    ASSERT_EQ(user1->getMessage(), message);
    ASSERT_EQ(user2->getMessage(), message);
}
}
