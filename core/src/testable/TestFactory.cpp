//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/testable/TestFactory.h"
#include <iostream>

using namespace cpptests::core::testable;

AbstractTest::AbstractTest(std::string&& category, std::string&& name)
: mCategory(std::move(category))
, mName(std::move(name))
{}

std::string AbstractTest::getCategory() const {
    return mCategory;
}

std::string AbstractTest::getName() const {
    return mName;
}

TestFactory& cpptests::core::testable::getFactory() {
    static TestFactory factory;
    return factory;
}

void TestFactory::addTest(std::unique_ptr<AbstractTest> test) {
    mTests.push_back(std::move(test));
}

void TestFactory::runAllTests() const {
    for (auto& test : mTests) {
        test->run();
        std::cout << "Test " << test->getCategory() << " " << test->getName() << " succeeded!\n";
    }
}
