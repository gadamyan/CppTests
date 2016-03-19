
#ifndef SharedPtr_h
#define SharedPtr_h

#include <cstdlib>

namespace SmartPointers {
    template<class T>
    class SharedPtr
    {
    private:
        T* m_pointer;
        size_t* m_refCount;
    
    public:
        SharedPtr(T* pointer);
        SharedPtr(const SharedPtr<T>& pointer);
        ~SharedPtr();
        void clear();
        SharedPtr<T>& operator=(const SharedPtr<T>& pointer);
        SharedPtr<T>& operator=(T* pointer);
        T& operator*();
        T* operator->();
        size_t getRefCount();
    };
    
    template<class T>
    SharedPtr<T>::SharedPtr(T* pointer)
    : m_pointer(pointer)
    , m_refCount(new size_t(1))
    {
    }
    
    template<class T>
    SharedPtr<T>::SharedPtr(const SharedPtr<T>& pointer)
        : m_pointer(pointer.m_pointer)
        , m_refCount(pointer.m_refCount)
    {
        ++*m_refCount;
    }
    
    
    template<class T>
    SharedPtr<T>::~SharedPtr()
    {
        clear();
    }
    
    template<class T>
    void SharedPtr<T>::clear()
    {
        if (m_pointer != nullptr)
        {
            if (*m_refCount == 1)
            {
                delete m_pointer;
                delete m_refCount;
                m_pointer = nullptr;
                m_refCount = nullptr;
            }
            else
            {
                --*m_refCount;
            }
        }
    }
    
    template<class T>
    SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& pointer)
    {
        m_pointer = pointer.m_pointer;
        m_refCount = pointer.m_refCount;
        ++*m_refCount;
    }
    
    template<class T>
    SharedPtr<T>& SharedPtr<T>::operator=(T* pointer)
    {
        clear();
        m_pointer = pointer;
        m_refCount = new size_t(1);
    }
    
    template<class T>
    T& SharedPtr<T>::operator*()
    {
        return *m_pointer;
    }
    
    template<class T>
    T* SharedPtr<T>::operator->()
    {
        return m_pointer;
    }
    
    template<class T>
    size_t SharedPtr<T>::getRefCount()
    {
        return *m_refCount;
    }
    
};

#endif /* SharedPtr_h */
