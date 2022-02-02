//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>
#include <vector>
#include <string>

namespace cpptests::core::patterns {

class IComponent {
public:
    virtual std::string getPath() const = 0;
    virtual ~IComponent() = default;
};

class Lief : public IComponent {
public:
    explicit Lief(const std::string& path);
    std::string getPath() const override;

private:
    const std::string mPath;
};

class Composite : public IComponent {
public:
    void addChild(std::unique_ptr<IComponent>&& IComponent);
    std::string getPath() const override;

private:
    std::vector<std::unique_ptr<IComponent>> mChildren;
};

}
