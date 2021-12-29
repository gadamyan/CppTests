//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <memory>
#include <ostream>

namespace cpptests::core::containers {

template <typename T, size_t Size>
class Array
{
public:
    class Iterator
    {
        friend class Array;

    public:
        Iterator& operator ++()
        {
            ++m_index;
            return *this;
        }

        bool operator == (const Iterator& iterator)
        {
            return &m_array == &iterator.m_array && m_index == iterator.m_index;
        }

        bool operator != (const Iterator& iterator)
        {
            return &m_array != &iterator.m_array || m_index != iterator.m_index;
        }

        T& operator *()
        {
            return m_array[m_index];
        }

    private:
        Iterator(Array& array, int index)
        : m_index(index)
        , m_array(array)
        {
        }

    private:
        int m_index;
        Array<T, Size>& m_array;
    };

    Array() = default;

    Array(std::initializer_list<T> list)
    {
        assert(Size == list.size());
        int i = 0;
        for (auto item : list)
        {
            m_array[i++] = item;
        }
    }

    T& operator[](int index)
    {
        return m_array[index];
    }

    constexpr size_t size()
    {
        return Size;
    }

    Iterator begin()
    {
        return Iterator(*this, 0);
    }

    Iterator end()
    {
        return Iterator(*this, Size);
    }

private:
    T m_array[Size];
};

template <typename T, size_t Size>
std::ostream& operator << (std::ostream& stream, Array<T, Size>& array)
{
    bool is_first = true;
    for (const auto& item : array)
    {
        if (!is_first)
        {
            stream << ", ";
        }
        else
        {
            is_first = false;
        }
        stream << item;
    }
    return stream;
}

}
