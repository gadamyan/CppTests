#pragma once

#include <cstddef>

namespace cpptests::core::containers {

template<typename T>
class ArrayStack
{
private:
    static const int m_maxSize = 256;
    size_t m_top;
    T container[m_maxSize];
public:
    ArrayStack();
    void push(T& item);
    T pop();
    size_t size();
};

template<typename T>
ArrayStack<T>::ArrayStack()
    : m_top(0)
{
}

template<typename T>
void ArrayStack<T>::push(T& item)
{
    if (m_top == m_maxSize)
    {
        throw "Stack overflow";
    }
    container[m_top] = item;
    ++m_top;
}

template<typename T>
T ArrayStack<T>::pop()
{
    if (m_top == 0)
    {
        throw "Stack is Empty";
    }
    return container[--m_top];
}

template<typename T>
size_t ArrayStack<T>::size()
{
    return m_top;
}
}