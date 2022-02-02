//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <string>
#include <vector>
#include <memory>

namespace cpptests::core::testable {

class AbstractTest {
public:
    AbstractTest(std::string&& category, std::string&& name);
    virtual void run() = 0;
    virtual ~AbstractTest() = default;

    std::string getCategory() const;
    std::string getName() const;

private:
    const std::string mCategory;
    const std::string mName;
};

class TestFactory {
public:
    void addTest(std::unique_ptr<AbstractTest> test);
    void runAllTests() const;

private:
    std::vector<std::unique_ptr<AbstractTest>> mTests;
};

TestFactory& getFactory();

template <typename T, typename... Args>
bool makeTest(Args&&... args) {
    getFactory().addTest(std::make_unique<T>(std::forward<Args>(args)...));
    return true;
}

}
