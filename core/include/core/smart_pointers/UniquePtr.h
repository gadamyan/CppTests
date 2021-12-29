//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <memory>

namespace cpptests::core::smart_pointers {

template <typename T>
class UniquePtr
{
public:
    UniquePtr() = default;

    UniquePtr(const UniquePtr&) = delete;

    UniquePtr& operator =(const UniquePtr&) = delete;

    explicit UniquePtr(T* ptr) {
        m_ptr = ptr;
    }

    UniquePtr(UniquePtr&& pointer) noexcept {
        m_ptr = pointer.m_ptr;
        pointer.m_ptr = nullptr;
    }

    UniquePtr& operator =(UniquePtr&& pointer) noexcept {
        reset();
        m_ptr = pointer.m_ptr;
        pointer.m_ptr = nullptr;
        return *this;
    }

    T& operator ->() const {
        return *m_ptr;
    }

    T& operator *() const {
        return *m_ptr;
    }

    T* get() const {
        return m_ptr;
    }

    void reset() {
        if (m_ptr != nullptr) {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

    T* release() {
        T* ptr = m_ptr;
        m_ptr = nullptr;
        return ptr;
    }

    ~UniquePtr()
    {
        reset();
    }

private:
    T* m_ptr = nullptr;
};

template <typename T, class... Args>
UniquePtr<T> make_unique_ptr(Args&&... args)
{
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

}
