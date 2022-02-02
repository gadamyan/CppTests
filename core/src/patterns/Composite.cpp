//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/patterns/Composite.h"

using namespace cpptests::core::patterns;

Lief::Lief(const std::string& path)
    : mPath(path)
{}

std::string Lief::getPath() const {
    return mPath + "\n";
}

void Composite::addChild(std::unique_ptr<IComponent>&& IComponent) {
    mChildren.emplace_back(std::move(IComponent));
}

std::string Composite::getPath() const {
    std::string path;
    for (const auto& child : mChildren) {
        std::string curretPath = child->getPath();
        size_t pos = 0;

        do {
            curretPath.insert(pos, "-");
            pos = curretPath.find('\n', pos) + 1;
        } while (pos != std::string::npos && pos != curretPath.size());

        path += curretPath;
    }
    return path;
}