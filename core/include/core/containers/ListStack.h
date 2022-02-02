//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

namespace cpptests::core::containers {

    template<typename T>
    struct NodeStack {
        NodeStack<T>* next;
        T data;
    };

    template<typename T>
    class ListStack {
    public:
        ListStack();
        ~ListStack();
        void push(T& item);
        T pop();
        void clear();
        int size();

    private:
        NodeStack<T>* mTop;
        int mSize;
    };

    template<typename T>
    ListStack<T>::ListStack()
        : mSize(0)
        , mTop(nullptr)
    {}

    template<typename T>
    ListStack<T>::~ListStack() {
        clear();
    }

    template<typename T>
    void ListStack<T>::push(T& item) {
        NodeStack<T>* temp = new NodeStack<T>;
        temp->next = mTop;
        temp->data = item;
        mTop = temp;
        ++mSize;
    }

    template<typename T>
    T ListStack<T>::pop() {
        if (mSize == 0) {
            throw "Stack is empty";
        }
        NodeStack<T>* temp = mTop;
        mTop = mTop->next;
        T item = temp->data;
        delete temp;
        --mSize;
        return item;
    }

    template<typename T>
    void ListStack<T>::clear() {
        for (int i = 0; i < mSize; ++i) {
            NodeStack<T>* temp = mTop;
            mTop = mTop->next;
            delete temp;
        }
        mSize = 0;
    }

    template<typename T>
    int ListStack<T>::size() {
        return mSize;
    }
}
