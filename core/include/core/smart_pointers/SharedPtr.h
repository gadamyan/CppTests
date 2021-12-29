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
class SharedPtr
{
    struct MemoryBlock
    {
        int m_reference_counter = 1;
    };

public:
    SharedPtr() = default;

    explicit SharedPtr(T* ptr)
    : m_ptr(ptr)
    , m_memory_block(new MemoryBlock)
    {
    }

    SharedPtr(const SharedPtr& other)
    : m_ptr(other.m_ptr)
    , m_memory_block(other.m_memory_block)
    {
        ++m_memory_block->m_reference_counter;
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        reset();
        m_ptr = other.m_ptr;
        m_memory_block = other.m_memory_block;
        ++m_memory_block->m_reference_count;
        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept
    : m_ptr(other.m_ptr)
    , m_memory_block(other.m_memory_block)
    {
        other.m_ptr = nullptr;
        other.m_memory_block = nullptr;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept
    {
        reset();
        m_ptr = other.m_ptr;
        m_memory_block = other.m_memory_block;
        other.m_ptr = nullptr;
        other.m_memory_block = nullptr;
        return *this;
    }

    bool operator==(const SharedPtr& other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const SharedPtr& other) const
    {
        return !(*this == other);
    }

    ~SharedPtr()
    {
        reset();
    }

    T& operator*() const
    {
        return *m_ptr;
    }

    T& operator->() const
    {
        return *m_ptr;
    }

    T* get() const
    {
        return m_ptr;
    }

    void reset()
    {
        if (m_ptr != nullptr)
        {
            --m_memory_block->m_reference_counter;
            if (m_memory_block->m_reference_counter == 0)
            {
                delete m_ptr;
                delete m_memory_block;
            }
        }
    }

private:
    T* m_ptr = nullptr;
    MemoryBlock* m_memory_block = nullptr;
};

template <typename T, class... Args>
SharedPtr<T> make_shared_ptr(Args&&... args)
{
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}
}
