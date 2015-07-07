#ifndef TreeMap_h__
#define TreeMap_h__

#include <string>
#include <cassert>
#include <stack>
#include <queue>
#include <vector>
#include <map>

namespace mcont
{
    template<typename T>
    struct NodeTree
    {
        std::string     key;
        T               value;
        NodeTree<T>*    left;
        NodeTree<T>*    right;
    };

    template<typename T>
    struct TreeMapPair
    {
        std::string& first;
        T& second;
        TreeMapPair(std::string& f, T& s) : first(f), second(s) {}
        TreeMapPair(const TreeMapPair<T>& pair) : first(pair.first), second(pair.second) {}
    };

    template<typename T>
    class TreeMapIterator
    {
    private:
        std::vector<NodeTree<T>*>       m_nodes;
        int                             m_currentIndex;

    public:
        TreeMapIterator(const std::vector<NodeTree<T>*>& nodes, int currentIndex)
            : m_nodes(nodes)
            , m_currentIndex(currentIndex)
        {
        }

        TreeMapIterator<T>& operator++()
        {
            ++m_currentIndex;
            return *this;
        }

        TreeMapIterator<T> operator++(int)
        {
            auto temp = this;
            ++m_currentIndex;
            return temp;
        }

        const bool operator != (const TreeMapIterator<T>& item) const
        {
            return m_currentIndex != item.m_currentIndex;
        }

        const bool operator == (const TreeMapIterator<T>& item) const 
        {
            return m_currentIndex == item.m_currentIndex;
        }

        TreeMapPair<T> operator*() const
        {
            assert(m_nodes.size() > m_currentIndex && "Out of range");
            auto item = m_nodes[m_currentIndex];
            return TreeMapPair<T>(item->key, item->value);
        }

        TreeMapPair<T>* operator->() const
        {
            return &operator*();
        }
    };

    template<typename T>
    class TreeMap
    {
    private:
        NodeTree<T>*    m_top;
        int             m_size;

    public:
        TreeMap();
        ~TreeMap();
        void set(const std::string& key, const T& value);
        T& get(const std::string& key);
        bool exists(const std::string& key);
        std::vector<NodeTree<T>*> depthFirstSearch();
        std::vector<NodeTree<T>*> breathFirstSearch();
        void clear();
        int size();
        TreeMapIterator<T> begin();
        TreeMapIterator<T> end();
    };

    template<typename T>
    TreeMap<T>::TreeMap()
        : m_top(nullptr)
        , m_size(0)
    {
    }

    template<typename T>
    TreeMap<T>::~TreeMap()
    {
        clear();
    }

    template<typename T>
    TreeMapIterator<T> TreeMap<T>::begin()
    {
        return TreeMapIterator<T>(breathFirstSearch(), 0);
    }

    template<typename T>
    TreeMapIterator<T> TreeMap<T>::end()
    {
        return TreeMapIterator<T>(breathFirstSearch(), m_size);
    }

    template<typename T>
    void TreeMap<T>::set(const std::string& key, const T& value)
    {
        NodeTree<T>* temp = new NodeTree<T>;
        temp->key = key;
        temp->value = value;
        temp->right = nullptr;
        temp->left = nullptr;
        if (m_size == 0)
        {
            m_top = temp;
            ++m_size;
        }
        else
        {
            NodeTree<T>* element = m_top;
            while (true)
            {
                if (element->key > key)
                {
                    if (element->left == nullptr)
                    {
                        element->left = temp;
                        ++m_size;
                        break;
                    }
                    else
                    {
                        element = element->left;
                    }
                }
                else if (element->key < key)
                {
                    if (element->right == nullptr)
                    {
                        element->right = temp;
                        ++m_size;
                        break;
                    }
                    else
                    {
                        element = element->right;
                    }
                }
                else
                {
                    element->value = value;
                    delete temp;
                    break;
                }
            }
        }
    }

    template<typename T>
    T& TreeMap<T>::get(const std::string& key)
    {
        NodeTree<T>* element = m_top;
        while (true)
        {
            if (element->key > key)
            {
                element = element->left;
                if (element == nullptr)
                {
                    break;
                }
            }
            else if (element->key < key)
            {
                element = element->right;
                if (element == nullptr)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        assert(element != nullptr && "Element doesn't exist");
        return element->value;
    }

    template<typename T>
    bool TreeMap<T>::exists(const std::string& key)
    {
        NodeTree<T>* element = m_top;
        while (true)
        {
            if (element->key > key)
            {
                element = element->left;
                if (element == nullptr)
                {
                    break;
                }
            }
            else if (element->key < key)
            {
                element = element->right;
                if (element == nullptr)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return element != nullptr;
    }

    template<typename T>
    void TreeMap<T>::clear()
    {
        if (m_size == 0)
        {
            return;
        }
        std::vector<NodeTree<T>*> elementsList = depthFirstSearch();
        for (auto it = elementsList.begin(); it != elementsList.end(); ++it)
        {
            auto ptr = *it;
            delete ptr;
        }
        m_size = 0;
    }

    template<typename T>
    std::vector<NodeTree<T>*> TreeMap<T>::depthFirstSearch()
    {
        std::vector<NodeTree<T>*> result;
        if (m_size == 0)
        {
            return result;
        }
        std::stack<NodeTree<T>*> tempStack;
        NodeTree<T>* element = m_top;
        tempStack.push(element);
        while (!tempStack.empty())
        {
            element = tempStack.top();
            result.push_back(element);
            tempStack.pop();
            if (element->left != nullptr)
            {
                tempStack.push(element->left);
            }
            if (element->right != nullptr)
            {
                tempStack.push(element->right);
            }
        }
        return result;
    }

    template<typename T>
    std::vector<NodeTree<T>*> TreeMap<T>::breathFirstSearch()
    {
        std::vector<NodeTree<T>*> result;
        if (m_size == 0)
        {
            return result;
        }
        std::queue<NodeTree<T>*> tempQueue;
        NodeTree<T>* element = m_top;
        tempQueue.push(element);
        while (!tempQueue.empty())
        {
            element = tempQueue.front();
            result.push_back(element);
            tempQueue.pop();
            if (element->left != nullptr)
            {
                tempQueue.push(element->left);
            }
            if (element->right != nullptr)
            {
                tempQueue.push(element->right);
            }
        }
        return result;
    }

    template<typename T>
    int TreeMap<T>::size()
    {
        return m_size;
    }
}

#endif // TreeMap_h__