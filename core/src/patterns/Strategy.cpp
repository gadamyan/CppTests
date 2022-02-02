//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Strategy.h"

using namespace cpptests::core::patterns;

int PowStrategy::calculate(int number) const {
    return number * number;
}

int SumStrategy::calculate(int number) const {
    int sum = 0;
    for (int i = 1; i <= number; ++i) {
        sum += i;
    }
    return sum;
}

void NumberContext::setStrategy(std::unique_ptr<IStrategy>&& strategy) {
    mStrategy = std::move(strategy);
}

int NumberContext::calculate(int number) const {
    return mStrategy->calculate(number);
}