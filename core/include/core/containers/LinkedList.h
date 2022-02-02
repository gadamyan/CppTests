//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

namespace cpptests::core::containers {

template <typename T>
class LinkedList {
private:
    struct ListNode {
        T data;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
    };

public:
    LinkedList() = default;

    LinkedList(std::initializer_list<T> list) {
        for (T item : list) {
            pushBack(item);
        }
    }

    ~LinkedList() {
        while (mFront) {
            auto node = mFront;
            mFront = mFront->next;
            delete node;
        }
    }

    void pushBack(const T& item) {
        ++mSize;
        ListNode* node = new ListNode;
        node->data = item;
        if (!mFront) {
            mFront = node;
            mBack = node;
        } else {
            mBack->next = node;
            node->prev = mBack;
            mBack = node;
        }
    }

    void push_front(const T& item) {
        ListNode* node = new ListNode;
        node->data = item;
        if (mSize == 0) {
            mFront = mBack = node;
        } else {
            node->next = mFront;
            mFront->prev = node;
            mFront = node;
        }
        ++mSize;
    }

    T popBack() {
        assert(mSize != 0);
        --mSize;
        auto node = mBack;

        if (mSize == 0) {
            mBack = nullptr;
            mFront = nullptr;
        } else {
            mBack = mBack->prev;
            mBack->next = nullptr;
        }

        T data = node->data;
        delete node;

        return data;
    }

    T popFront() {
        if (mSize == 0) {
            throw "List is empty";
        }
        ListNode* temp = mFront;
        T tempData = temp->data;
        mFront = mFront->next;
        delete temp;
        --mSize;
        return tempData;
    }

    void clear() {
        for (int i = 0; i < mSize; ++i) {
            ListNode* temp = mFront;
            mFront = mFront->next;
            delete temp;
        }
        mSize = 0;
    }

    int size() const {
        return mSize;
    }

private:
    ListNode* mFront = nullptr;
    ListNode* mBack = nullptr;
    int mSize = 0;
};


}
