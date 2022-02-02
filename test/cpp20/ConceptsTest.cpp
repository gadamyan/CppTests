//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/cpp20/Concepts.h"

#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::cpp20;

TEST(ConceptTest, verify_concept_function_overloads)
{
    conceptOverload('c');
    conceptOverload(3.0);
}

TEST(ConceptTest, verify_enable_if_function_overloads)
{
    enableIfOverload('c');
    enableIfOverload(3.0);
}

TEST(ConceptTest, verify_applicable_functions)
{
    std::vector charVector = { 'a', 'b', 'c' };
    auto it = charVector.begin();
    f1(it);
    f2(it);
    f3(it);
    f4(it);
    f5(it);
    f6(it);
    f7(it);
    f8(it);
    CustomConcept auto v = it;
}
}
