//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <cstddef>

namespace cpptests::core::containers {

template<typename T>
class ArrayStack {
public:
    ArrayStack();
    ArrayStack(const ArrayStack&) = delete;
    ArrayStack& operator=(const ArrayStack&) = delete;
    void push(T& item);
    T pop();
    size_t size();

private:
    static constexpr int mMaxSize = 256;
    size_t mTop;
    T container[mMaxSize];
};

template<typename T>
ArrayStack<T>::ArrayStack()
    : mTop(0)
{}

template<typename T>
void ArrayStack<T>::push(T& item) {
    if (mTop == mMaxSize) {
        throw "Stack overflow";
    }
    container[mTop] = item;
    ++mTop;
}

template<typename T>
T ArrayStack<T>::pop() {
    if (mTop == 0) {
        throw "Stack is Empty";
    }
    return container[--mTop];
}

template<typename T>
size_t ArrayStack<T>::size() {
    return mTop;
}
}