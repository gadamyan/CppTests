#ifndef ArrayStack_h__
#define ArrayStack_h__

template<typename T>
class ArrayStack
{
private:
    static const int m_maxSize = 256;
    size_t m_top;
    T container[m_maxSize];
public:
    ArrayStack();
    void push(T& item);
    T pop();
    size_t size();
};

template<typename T>
ArrayStack<typename T>::ArrayStack()
    : m_top(0)
{
}

template<typename T>
void ArrayStack<typename T>::push(T& item)
{
    if (m_top == m_maxSize)
    {
        throw "Stack overflow";
    }
    container[m_top] = item;
    ++m_top;
}

template<typename T>
T ArrayStack<typename T>::pop()
{
    if (m_top == 0)
    {
        throw "Stack is Empty";
    }
    return container[--m_top];
}

template<typename T>
size_t ArrayStack<typename T>::size()
{
    return m_top;
}

#endif // ArrayStack_h__