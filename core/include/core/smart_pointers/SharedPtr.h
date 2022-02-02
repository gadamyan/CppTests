//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <memory>

namespace cpptests::core::smart_pointers {

template <typename T>
class SharedPtr {
    struct MemoryBlock {
        int mReferenceCounter = 1;
    };

public:
    SharedPtr() = default;

    explicit SharedPtr(T* ptr)
    : mPtr(ptr)
    , mMemoryBlock(new MemoryBlock)
    {}

    SharedPtr(const SharedPtr& other)
    : mPtr(other.mPtr)
    , mMemoryBlock(other.mMemoryBlock) {
        ++mMemoryBlock->mReferenceCounter;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        reset();
        mPtr = other.mPtr;
        mMemoryBlock = other.mMemoryBlock;
        ++mMemoryBlock->m_reference_count;
        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept
    : mPtr(other.mPtr)
    , mMemoryBlock(other.mMemoryBlock) {
        other.mPtr = nullptr;
        other.mMemoryBlock = nullptr;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept {
        reset();
        mPtr = other.mPtr;
        mMemoryBlock = other.mMemoryBlock;
        other.mPtr = nullptr;
        other.mMemoryBlock = nullptr;
        return *this;
    }

    bool operator==(const SharedPtr& other) const {
        return mPtr == other.mPtr;
    }

    bool operator!=(const SharedPtr& other) const {
        return !(*this == other);
    }

    ~SharedPtr() {
        reset();
    }

    T& operator*() const {
        return *mPtr;
    }

    T& operator->() const {
        return *mPtr;
    }

    T* get() const {
        return mPtr;
    }

    void reset() {
        if (mPtr != nullptr) {
            --mMemoryBlock->mReferenceCounter;
            if (mMemoryBlock->mReferenceCounter == 0) {
                delete mPtr;
                delete mMemoryBlock;
            }
        }
    }

private:
    T* mPtr = nullptr;
    MemoryBlock* mMemoryBlock = nullptr;
};

template <typename T, class... Args>
SharedPtr<T> makeSharedPtr(Args&&... args) {
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}
}
