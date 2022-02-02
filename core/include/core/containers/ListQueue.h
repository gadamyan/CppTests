//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

namespace cpptests::core::containers {

    template<typename T>
    struct NodeQueue {
        NodeQueue<T>* next;
        T data;
    };

    template<typename T>
    class ListQueue {
    private:
        NodeQueue<T>* mFront;
        NodeQueue<T>* mBack;
        int mSize;

    public:
        ListQueue();
        ~ListQueue();
        void pushBack(T& item);
        T popFront();
        int size();
        void clear();
    };

    template<typename T>
    ListQueue<T>::ListQueue()
        : mFront(nullptr)
        , mBack(nullptr)
        , mSize(0)
    {}

    template<typename T>
    ListQueue<T>::~ListQueue() {
        clear();
    }

    template<typename T>
    void ListQueue<T>::pushBack(T& item) {
        NodeQueue<T>* temp = new NodeQueue<T>;
        temp->data = item;
        if (mSize == 0) {
            mFront = temp;
        } else {
            mBack->next = temp;
        }
        mBack = temp;
        ++mSize;
    }

    template<typename T>
    T ListQueue<T>::popFront() {
        if (mSize == 0) {
            throw "Queue is empty";
        }
        NodeQueue<T>* temp = mFront;
        T tempData = temp->data;
        mFront = mFront->next;
        --mSize;
        delete temp;
        return tempData;
    }

    template<typename T>
    void ListQueue<T>::clear() {
        for (int i = 0; i < mSize; ++i) {
            NodeQueue<T>* temp = mFront;
            mFront = mFront->next;
            delete temp;
        }
        mSize = 0;
    }

    template<typename T>
    int ListQueue<T>::size() {
        return mSize;
    }
}
