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

class GlobalsSingleton
{
public:
    GlobalsSingleton(const GlobalsSingleton&) = delete;
    GlobalsSingleton& operator =(const GlobalsSingleton&) = delete;

    static GlobalsSingleton& get_instance()
    {
        return s_instance;
    }

    int get_int() const
    {
        return m_value;
    }

    void set_int(int value)
    {
        m_value = value;
    }
private:
    GlobalsSingleton() = default;

private:
    int m_value = 0;
    static GlobalsSingleton s_instance;
};

GlobalsSingleton GlobalsSingleton::s_instance;

}
