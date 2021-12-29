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

template <typename T>
class LinkedList
{
private:
    struct ListNode
    {
        T data;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
    };

public:
    LinkedList() = default;

    LinkedList(std::initializer_list<T> list)
    {
        for (T item : list)
        {
            push_back(item);
        }
    }

    ~LinkedList()
    {
        while (m_front)
        {
            auto node = m_front;
            m_front = m_front->next;
            delete node;
        }
    }

    void push_back(const T& item)
    {
        ++m_size;
        ListNode* node = new ListNode;
        node->data = item;
        if (!m_front)
        {
            m_front = node;
            m_back = node;
        }
        else
        {
            m_back->next = node;
            node->prev = m_back;
            m_back = node;
        }
    }

    void push_front(const T& item)
    {
        ListNode* node = new ListNode;
        node->data = item;
        if (m_size == 0)
        {
            m_front = m_back = node;
        }
        else
        {
            node->next = m_front;
            m_front->prev = node;
            m_front = node;
        }
        ++m_size;
    }

    T pop_back()
    {
        assert(m_size != 0);
        --m_size;
        auto node = m_back;

        if (m_size == 0)
        {
            m_back = nullptr;
            m_front = nullptr;
        }
        else
        {
            m_back = m_back->prev;
            m_back->next = nullptr;
        }

        T data = node->data;
        delete node;

        return data;
    }

    T pop_front()
    {
        if (m_size == 0)
        {
            throw "List is empty";
        }
        ListNode* temp = m_front;
        T tempData = temp->data;
        m_front = m_front->next;
        delete temp;
        --m_size;
        return tempData;
    }

    void clear()
    {
        for (int i = 0; i < m_size; ++i)
        {
            ListNode* temp = m_front;
            m_front = m_front->next;
            delete temp;
        }
        m_size = 0;
    }

    int size() const
    {
        return m_size;
    }

private:
    ListNode* m_front = nullptr;
    ListNode* m_back = nullptr;
    int m_size = 0;
};


}
