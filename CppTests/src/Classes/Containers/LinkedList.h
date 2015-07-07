#ifndef LinkedList_h__
#define LinkedList_h__

namespace mcont
{
    template<typename T>
    struct NodeList
    {
        NodeList<T>* prev;
        NodeList<T>* next;
        T data;
    };

    template<typename T>
    class LinkedList
    {
    private:
        NodeList<T>*        m_front;
        NodeList<T>*        m_back;
        int                 m_size;

    public:
        LinkedList();
        ~LinkedList();
        void pushBack(const T& item);
        void pushFront(const T& item);
        T popFront();
        T popBack();
        void clear();
        int size();
    };

    template<typename T>
    LinkedList<T>::LinkedList()
        : m_front(nullptr)
        , m_back(nullptr)
        , m_size(0)
    {
    }

    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        clear();
    }

    template<typename T>
    void LinkedList<T>::pushBack(const T& item)
    {
        NodeList<T>* node = new NodeList<T>;
        node->data = item;
        if (m_size == 0)
        {
            m_front = m_back = node;
        }
        else
        {
            m_back->next = node;
            node->prev = m_back;
            m_back = node;
        }
        ++m_size;
    }

    template<typename T>
    void LinkedList<T>::pushFront(const T& item)
    {
        NodeList<T>* node = new NodeList < T > ;
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

    template<typename T>
    T LinkedList<T>::popBack()
    {
        if (m_size == 0)
        {
            throw "List is empty";
        }
        NodeList<T>* temp = m_back;
        T tempData = temp->data;
        m_back = m_back->prev;
        delete temp;
        --m_size;
        return tempData;
    }

    template<typename T>
    T LinkedList<T>::popFront()
    {
        if (m_size == 0)
        {
            throw "List is empty";
        }
        NodeList<T>* temp = m_front;
        T tempData = temp->data;
        m_front = m_front->next;
        delete temp;
        --m_size;
        return tempData;
    }

    template<typename T>
    void LinkedList<T>::clear()
    {
        for (int i = 0; i < m_size; ++i)
        {
            NodeList<T>* temp = m_front;
            m_front = m_front->next;
            delete temp;
        }
        m_size = 0;
    }

    template<typename T>
    int LinkedList<T>::size()
    {
        return m_size;
    }
}

#endif // LinkedList_h__