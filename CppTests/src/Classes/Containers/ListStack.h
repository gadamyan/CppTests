#ifndef ListStack_h__
#define ListStack_h__

namespace mcont {

    template<typename T>
    struct NodeStack
    {
        NodeStack<T>* next;
        T data;
    };

    template<typename T>
    class ListStack
    {
    private:
        NodeStack<T>*   m_top;
        int             m_size;

    public:
        ListStack();
        ~ListStack();
        void push(T& item);
        T pop();
        void clear();
        int size();
    };

    template<typename T>
    ListStack<T>::ListStack()
        : m_size(0)
        , m_top(nullptr)
    {
    }

    template<typename T>
    ListStack<T>::~ListStack()
    {
        clear();
    }

    template<typename T>
    void ListStack<T>::push(T& item)
    {
        NodeStack<T>* temp = new NodeStack<T>;
        temp->next = m_top;
        temp->data = item;
        m_top = temp;
        ++m_size;
    }

    template<typename T>
    T ListStack<T>::pop()
    {
        if (m_size == 0)
        {
            throw "Stack is empty";
        }
        NodeStack<T>* temp = m_top;
        m_top = m_top->next;
        T item = temp->data;
        delete temp;
        --m_size;
        return item;
    }

    template<typename T>
    void ListStack<T>::clear()
    {
        for (int i = 0; i < m_size; ++i)
        {
            NodeStack<T>* temp = m_top;
            m_top = m_top->next;
            delete temp;
        }
        m_size = 0;
    }

    template<typename T>
    int ListStack<T>::size()
    {
        return m_size;
    }
}


#endif // ListStack_h__ 

