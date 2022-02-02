//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>

namespace cpptests::core::patterns {

class Component {
public:
    virtual int getPrice() const = 0;
    virtual ~Component() = default;
};

class ConcreteProduct : public Component {
public:
    int getPrice() const override;
};

class ConcreteDecorator : public Component {
public:
    ConcreteDecorator(std::unique_ptr<Component>&& component);
    int getPrice() const override;

private:
    std::unique_ptr<Component> mComponent;
};

}
