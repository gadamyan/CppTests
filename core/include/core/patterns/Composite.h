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

class IComponent
{
protected:
    IComponent() = default;

public:
    virtual std::string get_path() const = 0;

    IComponent(const IComponent&) = delete;

    IComponent& operator=(const IComponent&) = delete;

    virtual ~IComponent() = default;
};

class Lief : public IComponent
{
public:
    Lief(const std::string& path)
        : m_path(path)
    {
    }

    std::string get_path() const override
    {
        return m_path + "\n";
    }

private:
    const std::string m_path;
};

class Composite : public IComponent
{
public:
    void add_child(std::unique_ptr<IComponent> IComponent)
    {
        m_children.push_back(std::move(IComponent));
    }

    std::string get_path() const override
    {
        std::string path;
        for (const auto& child : m_children)
        {
            std::string curret_path = child->get_path();
            size_t pos = 0;

            do {
                curret_path.insert(pos, "-");
                pos = curret_path.find('\n', pos) + 1;
            } while (pos != std::string::npos && pos != curret_path.size());

            path += curret_path;
        }
        return path;
    }

private:
    std::vector<std::unique_ptr<IComponent>> m_children;
};

}
