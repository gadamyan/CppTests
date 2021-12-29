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

class Component
{
public:
    virtual int get_price() const = 0;
    virtual ~Component() = default;
};

class ConcreteProduct : public Component
{
public:
    int get_price() const override
    {
        return 100;
    }
};

class ConcreteDecorator : public Component
{
public:
    ConcreteDecorator(std::unique_ptr<Component> component)
    : m_component(std::move(component))
    {
    }

    int get_price() const override
    {
        return m_component->get_price() + 100;
    }
private:
    std::unique_ptr<Component> m_component;
};

}
