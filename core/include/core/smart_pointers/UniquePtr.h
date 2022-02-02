//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>

namespace cpptests::core::smart_pointers {

template <typename T>
class UniquePtr {
public:
    UniquePtr() = default;

    UniquePtr(const UniquePtr&) = delete;

    UniquePtr& operator=(const UniquePtr&) = delete;

    explicit UniquePtr(T* ptr) {
        mPtr = ptr;
    }

    UniquePtr(UniquePtr&& pointer) noexcept {
        mPtr = pointer.mPtr;
        pointer.mPtr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& pointer) noexcept {
        reset();
        mPtr = pointer.mPtr;
        pointer.mPtr = nullptr;
        return *this;
    }

    T& operator->() const {
        return *mPtr;
    }

    T& operator*() const {
        return *mPtr;
    }

    T* get() const {
        return mPtr;
    }

    void reset() {
        if (mPtr != nullptr) {
            delete mPtr;
            mPtr = nullptr;
        }
    }

    T* release() {
        T* ptr = mPtr;
        mPtr = nullptr;
        return ptr;
    }

    ~UniquePtr() {
        reset();
    }

private:
    T* mPtr = nullptr;
};

template <typename T, class... Args>
UniquePtr<T> makeUniquePtr(Args&&... args) {
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

}
