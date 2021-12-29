//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <memory>

namespace cpptests::core::patterns {

class IStrategy
{
public:
    virtual int calculate(int number) const = 0;
    virtual ~IStrategy() = default;
};

class PowStrategy : public IStrategy
{
public:
    int calculate(int number) const override
    {
        return number * number;
    }
};

class SumStrategy : public IStrategy
{
public:
    int calculate(int number) const override
    {
        int sum = 0;
        for (int i = 1; i <= number; ++i)
        {
            sum += i;
        }
        return sum;
    }
};

class NumberContext
{
public:
    void set_strategy(std::unique_ptr<IStrategy> strategy)
    {
        m_strategy = std::move(strategy);
    }

    int calculate(int number) const
    {
        return m_strategy->calculate(number);
    }

private:
    std::unique_ptr<IStrategy> m_strategy;
};

}
