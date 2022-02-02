//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>
#include <ostream>

namespace cpptests::core::containers {

template <typename T, size_t Size>
class Array {
public:
    class Iterator {
        friend class Array;

    public:
        Iterator& operator ++() {
            ++mIndex;
            return *this;
        }

        bool operator == (const Iterator& iterator) {
            return &mArray == &iterator.mArray && mIndex == iterator.mIndex;
        }

        bool operator != (const Iterator& iterator) {
            return &mArray != &iterator.mArray || mIndex != iterator.mIndex;
        }

        T& operator *() {
            return mArray[mIndex];
        }

    private:
        Iterator(Array& array, int index)
        : mIndex(index)
        , mArray(array)
        {
        }

    private:
        int mIndex;
        Array<T, Size>& mArray;
    };

    Array() = default;

    Array(std::initializer_list<T> list) {
        assert(Size == list.size());
        int i = 0;
        for (auto item : list) {
            mArray[i++] = item;
        }
    }

    Array(const Array& other) {
        std::copy(std::begin(other.mArray), std::end(other.mArray), std::begin(mArray));
    }

    T& operator[](int index) {
        return mArray[index];
    }

    constexpr size_t size() {
        return Size;
    }

    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, Size);
    }

private:
    T mArray[Size];
};

template <typename T, size_t Size>
std::ostream& operator << (std::ostream& stream, Array<T, Size>& array) {
    bool isFirst = true;
    for (const auto& item : array) {
        if (!isFirst) {
            stream << ", ";
        } else {
            isFirst = false;
        }
        stream << item;
    }
    return stream;
}

}
