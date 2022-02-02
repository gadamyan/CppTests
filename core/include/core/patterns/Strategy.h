//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>

namespace cpptests::core::patterns {

class IStrategy {
public:
    virtual int calculate(int number) const = 0;
    virtual ~IStrategy() = default;
};

class PowStrategy : public IStrategy {
public:
    int calculate(int number) const override;
};

class SumStrategy : public IStrategy {
public:
    int calculate(int number) const override;
};

class NumberContext {
public:
    void setStrategy(std::unique_ptr<IStrategy>&& strategy);
    int calculate(int number) const;

private:
    std::unique_ptr<IStrategy> mStrategy;
};

}
