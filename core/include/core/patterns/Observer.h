//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

namespace cpptests::core::patterns {

class IObserver
{
public:
    virtual void set_message(const std::string& message) = 0;
    virtual ~IObserver() = default;
};

class Subject
{
public:
    void notifyObservers(const std::string& message)
    {
        for (const auto& observer : m_observers)
        {
            observer->set_message(message);
        }
    }

    void register_observer(std::shared_ptr<IObserver> observer)
    {
        m_observers.push_back(std::move(observer));
    }

    void remove_observer(std::shared_ptr<IObserver> observer)
    {
        m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
    }

private:
    std::vector<std::shared_ptr<IObserver>> m_observers;
};

class User : public IObserver
{
public:
    void set_message(const std::string& message) override
    {
        m_message = message;
    }

    std::string get_message() const
    {
        return m_message;
    }

private:
    std::string m_message;
};

}
