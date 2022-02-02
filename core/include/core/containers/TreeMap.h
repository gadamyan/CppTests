//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <string>
#include <cassert>
#include <stack>
#include <queue>
#include <vector>
#include <map>

namespace cpptests::core::containers {

    template<typename T>
    struct NodeTree {
        std::string key;
        T value;
        NodeTree<T>* left;
        NodeTree<T>* right;
    };

    template<typename T>
    struct TreeMapPair {
        std::string& first;
        T& second;
        TreeMapPair(std::string& f, T& s) : first(f), second(s) {}
        TreeMapPair(const TreeMapPair<T>& pair) : first(pair.first), second(pair.second) {}
    };

    template<typename T>
    class TreeMapIterator {
    public:
        TreeMapIterator(const std::vector<NodeTree<T>*>& nodes, int currentIndex)
            : mNodes(nodes)
            , mCurrentIndex(currentIndex) {
        }

        TreeMapIterator<T>& operator++() {
            ++mCurrentIndex;
            return *this;
        }

        TreeMapIterator<T> operator++(int) {
            auto temp = this;
            ++mCurrentIndex;
            return temp;
        }

        bool operator != (const TreeMapIterator<T>& item) const {
            return mCurrentIndex != item.mCurrentIndex;
        }

        bool operator == (const TreeMapIterator<T>& item) const {
            return mCurrentIndex == item.mCurrentIndex;
        }

        TreeMapPair<T> operator*() const {
            assert(mNodes.size() > mCurrentIndex && "Out of range");
            auto item = mNodes[mCurrentIndex];
            return TreeMapPair<T>(item->key, item->value);
        }

    private:
        std::vector<NodeTree<T>*> mNodes;
        int mCurrentIndex;
    };

    template<typename T>
    class TreeMap {
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

    private:
        NodeTree<T>* mTop;
        int mSize;
    };

    template<typename T>
    TreeMap<T>::TreeMap()
        : mTop(nullptr)
        , mSize(0)
    {}

    template<typename T>
    TreeMap<T>::~TreeMap() {
        clear();
    }

    template<typename T>
    TreeMapIterator<T> TreeMap<T>::begin() {
        return TreeMapIterator<T>(breathFirstSearch(), 0);
    }

    template<typename T>
    TreeMapIterator<T> TreeMap<T>::end() {
        return TreeMapIterator<T>(breathFirstSearch(), mSize);
    }

    template<typename T>
    void TreeMap<T>::set(const std::string& key, const T& value) {
        NodeTree<T>* temp = new NodeTree<T>;
        temp->key = key;
        temp->value = value;
        temp->right = nullptr;
        temp->left = nullptr;
        if (mSize == 0) {
            mTop = temp;
            ++mSize;
        } else {
            NodeTree<T>* element = mTop;
            while (true) {
                if (element->key > key) {
                    if (element->left == nullptr) {
                        element->left = temp;
                        ++mSize;
                        break;
                    } else {
                        element = element->left;
                    }
                } else if (element->key < key) {
                    if (element->right == nullptr) {
                        element->right = temp;
                        ++mSize;
                        break;
                    } else {
                        element = element->right;
                    }
                } else {
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
        NodeTree<T>* element = mTop;
        while (true) {
            if (element->key > key) {
                element = element->left;
                if (element == nullptr) {
                    break;
                }
            } else if (element->key < key) {
                element = element->right;
                if (element == nullptr) {
                    break;
                }
            } else {
                break;
            }
        }
        assert(element != nullptr && "Element doesn't exist");
        return element->value;
    }

    template<typename T>
    bool TreeMap<T>::exists(const std::string& key) {
        NodeTree<T>* element = mTop;
        while (true) {
            if (element->key > key) {
                element = element->left;
                if (element == nullptr) {
                    break;
                }
            } else if (element->key < key) {
                element = element->right;
                if (element == nullptr) {
                    break;
                }
            } else {
                break;
            }
        }
        return element != nullptr;
    }

    template<typename T>
    void TreeMap<T>::clear() {
        if (mSize == 0) {
            return;
        }
        std::vector<NodeTree<T>*> elementsList = depthFirstSearch();
        for (auto it = elementsList.begin(); it != elementsList.end(); ++it) {
            auto ptr = *it;
            delete ptr;
        }
        mSize = 0;
    }

    template<typename T>
    std::vector<NodeTree<T>*> TreeMap<T>::depthFirstSearch() {
        std::vector<NodeTree<T>*> result;
        if (mSize == 0) {
            return result;
        }
        std::stack<NodeTree<T>*> tempStack;
        NodeTree<T>* element = mTop;
        tempStack.push(element);
        while (!tempStack.empty()) {
            element = tempStack.top();
            result.push_back(element);
            tempStack.pop();
            if (element->left != nullptr) {
                tempStack.push(element->left);
            }
            if (element->right != nullptr) {
                tempStack.push(element->right);
            }
        }
        return result;
    }

    template<typename T>
    std::vector<NodeTree<T>*> TreeMap<T>::breathFirstSearch() {
        std::vector<NodeTree<T>*> result;
        if (mSize == 0) {
            return result;
        }
        std::queue<NodeTree<T>*> tempQueue;
        NodeTree<T>* element = mTop;
        tempQueue.push(element);
        while (!tempQueue.empty()) {
            element = tempQueue.front();
            result.push_back(element);
            tempQueue.pop();
            if (element->left != nullptr) {
                tempQueue.push(element->left);
            }
            if (element->right != nullptr) {
                tempQueue.push(element->right);
            }
        }
        return result;
    }

    template<typename T>
    int TreeMap<T>::size() {
        return mSize;
    }
}
