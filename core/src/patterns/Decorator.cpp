//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Decorator.h"

using namespace cpptests::core::patterns;

int ConcreteProduct::getPrice() const {
        return 100;
}

ConcreteDecorator::ConcreteDecorator(std::unique_ptr<Component>&& component)
    : mComponent(std::move(component))
{}

int ConcreteDecorator::getPrice() const {
    return mComponent->getPrice() + 100;
}