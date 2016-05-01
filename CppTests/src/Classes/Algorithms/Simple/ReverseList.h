#ifndef ReverseList_h__
#define ReverseList_h__

#include <iostream>


template <typename T>
struct ListNode
{
    T data;
    ListNode<T>* next;
};

class ReverseList
{
public:
    
    static ListNode<int>* createList()
    {
        ListNode<int>* root = nullptr;
        ListNode<int>* current = nullptr;
        int array[] = { 1, 3, 5, 7, 8, 9 };
        for (int item : array)
        {
            ListNode<int>* temp = new ListNode<int> { item, nullptr };
            if (root == nullptr)
            {
                root = temp;
                current = temp;
            }
            else
            {
                current->next = temp;
                current = temp;
            }
        }
        return root;
    }
    
    static void removeList(ListNode<int>* root)
    {
        while (root != nullptr)
        {
            ListNode<int>* temp = root;
            root = root->next;
            delete temp;
        }
    }
    
    static void printList(ListNode<int>* root)
    {
        while (root != nullptr)
        {
            std::cout << root->data << " ";
            root = root->next;
        }
        std::cout << std::endl;
    }
    
    static void testReverse()
    {
        ListNode<int>* root = createList();
        root = reverse(root);
        printList(root);
        removeList(root);
    }
    
    template <typename T>
    static ListNode<T>* reverse(ListNode<T>* root)
    {
        if (root == nullptr)
        {
            return root;
        }
        else
        {
            ListNode<T>* prev = nullptr;
            ListNode<T>* current = root;
            while (current != nullptr)
            {
                ListNode<T>* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }
    }
};

#endif // ReverseList_h__