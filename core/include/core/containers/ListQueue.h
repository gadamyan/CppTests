#pragma once

namespace cpptests::core::containers {

    template<typename T>
    struct NodeQueue
    {
        NodeQueue<T>* next;
        T data;
    };

    template<typename T>
    class ListQueue
    {
    private:
        NodeQueue<T>*       m_front;
        NodeQueue<T>*       m_back;
        int                 m_size;

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
        : m_front(nullptr)
        , m_back(nullptr)
        , m_size(0)
    {
    }

    template<typename T>
    ListQueue<T>::~ListQueue()
    {
        clear();
    }

    template<typename T>
    void ListQueue<T>::pushBack(T& item)
    {
        NodeQueue<T>* temp = new NodeQueue<T>;
        temp->data = item;
        if (m_size == 0)
        {
            m_front = temp;
        }
        else
        {
            m_back->next = temp;
        }
        m_back = temp;
        ++m_size;
    }

    template<typename T>
    T ListQueue<T>::popFront()
    {
        if (m_size == 0)
        {
            throw "Queue is empty";
        }
        NodeQueue<T>* temp = m_front;
        T tempData = temp->data;
        m_front = m_front->next;
        --m_size;
        delete temp;
        return tempData;
    }

    template<typename T>
    void ListQueue<T>::clear()
    {
        for (int i = 0; i < m_size; ++i)
        {
            NodeQueue<T>* temp = m_front;
            m_front = m_front->next;
            delete temp;
        }
        m_size = 0;
    }

    template<typename T>
    int ListQueue<T>::size()
    {
        return m_size;
    }
}
