//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include "core/testable/TestFactory.h"
#include <iostream>

using namespace cpptests::core::testable;

AbstractTest::AbstractTest(std::string&& cathegory, std::string&& name)
: m_cathegory(std::move(cathegory))
, m_name(std::move(name))
{
}

std::string AbstractTest::get_cathegory() const
{
    return m_cathegory;
}

std::string AbstractTest::get_name() const
{
    return m_name;
}

TestFactory& cpptests::core::testable::get_factory()
{
    static TestFactory factory;
    return factory;
}

void TestFactory::add_test(std::unique_ptr<AbstractTest> test)
{
    m_tests.push_back(std::move(test));
}

void TestFactory::run_all_tests() const
{
    for (auto& test : m_tests)
    {
        test->run();
        std::cout << "Test " << test->get_cathegory() << " " << test->get_name() << " succeeded!\n";
    }
}
