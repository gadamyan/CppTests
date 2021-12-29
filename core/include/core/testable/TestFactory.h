//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <string>
#include <vector>
#include <memory>

namespace cpptests::core::testable {

class AbstractTest
{
public:
    AbstractTest(std::string&& cathegory, std::string&& name);
    virtual void run() = 0;
    virtual ~AbstractTest() = default;

    std::string get_cathegory() const;
    std::string get_name() const;

private:
    const std::string m_cathegory;
    const std::string m_name;
};

class TestFactory
{
public:
    void add_test(std::unique_ptr<AbstractTest> test);
    void run_all_tests() const;

private:
    std::vector<std::unique_ptr<AbstractTest>> m_tests;
};

TestFactory& get_factory();

template <typename T, typename... Args>
bool make_test(Args&&... args)
{
    get_factory().add_test(std::make_unique<T>(std::forward<Args>(args)...));
    return true;
}

}
