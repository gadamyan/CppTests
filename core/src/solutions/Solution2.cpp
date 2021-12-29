#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

struct ListNode
{
    ListNode* next;
    int data;
    
    ListNode() : next(nullptr), data(0)
    {}
    
    ListNode(const int value) : next(nullptr), data(value)
    {}
};


ListNode* createList()
{
    ListNode* head = nullptr;
    ListNode* node = nullptr;
    const std::vector<int> array { 0, 1, 2, 3, 4, 4, 7, 3 };
    for (const int item : array)
    {
        ListNode* temp = new ListNode(item);
        if (head == nullptr)
        {
            head = temp;
            node = temp;
        }
        else
        {
            node->next = temp;
            node = temp;
        }
    }
    return head;
}

void destroyList(ListNode* head)
{
    ListNode* node = head;
    while (node != nullptr)
    {
        ListNode* next = node->next;
        delete node;
        node = next;
    }
}

void coutList(ListNode* head)
{
    ListNode* node = head;
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void ex1()
{
    ListNode* head = createList();
    
    std::set<int> elementsSet;
    ListNode* node = head;
    ListNode* prev = nullptr;
    
    while (node != nullptr)
    {
        ListNode* nextNode = node->next;
        int data = node->data;
        if (elementsSet.find(data) != elementsSet.cend())
        {
            prev->next = nextNode;
            delete node;
        }
        else
        {
            elementsSet.insert(data);
            prev = node;
        }
        node = nextNode;
    }
    
    coutList(head);
    destroyList(head);
}

/*void ex2()
{
    ListNode* head = createList();
    
    const int n = 3;
    
    ListNode* begin = nullptr;
    ListNode* end = nullptr;
    
    for (int i = 0; i < n; ++i)
    {
        if (end == nullptr)
        {
            return;
        }
        end = end->next
    }
    
    coutList(head);
    destroyList(head);
}*/